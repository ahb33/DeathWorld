#include "BaseCharacter.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "EnhancedInputComponent.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Game_Interactable.h"
#include "EnhancedInputSubsystems.h"
#include "BaseWeapon.h"
#include "Net/UnrealNetwork.h"   

// Sets default values
ABaseCharacter::ABaseCharacter()
{
    PrimaryActorTick.bCanEverTick = true;

    CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
    CameraBoom->SetupAttachment(RootComponent);
    CameraBoom->TargetArmLength = 300.0f;
    CameraBoom->bUsePawnControlRotation = true;

    FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
    FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);
    FollowCamera->bUsePawnControlRotation = false;

    bUseControllerRotationPitch = false;
    bUseControllerRotationYaw = false;
    bUseControllerRotationRoll = false;

    GetCapsuleComponent()->InitCapsuleSize(60.f, 96.0f);

    GetCharacterMovement()->bOrientRotationToMovement = true;
    GetCharacterMovement()->RotationRate = FRotator(0.0f, 500.0f, 0.0f);
    GetCharacterMovement()->MaxWalkSpeed = 50.f;
    GetCharacterMovement()->BrakingDecelerationWalking = 2000.f;

    MoveAction = nullptr;
    LookAction = nullptr;
    InteractAction = nullptr;
    InteractableActor = nullptr;

    myWeapon = CreateDefaultSubobject<ABaseWeapon>(TEXT("Weapon"));

}

void ABaseCharacter::BeginPlay()
{
    Super::BeginPlay();

    if (APlayerController* PlayerController = Cast<APlayerController>(Controller))
    {
        if (UEnhancedInputLocalPlayerSubsystem* Subsystem = 
        ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
        {
            Subsystem->AddMappingContext(DefaultMappingContext, 0);
        }
    }
}

void ABaseCharacter::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    isInteracting();

}

void ABaseCharacter::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);

    DOREPLIFETIME(ABaseCharacter, Health);
    DOREPLIFETIME(ABaseCharacter, overlappingWeapon);
    DOREPLIFETIME(ABaseCharacter, myWeapon);


    // Add other properties to replicate

}

void ABaseCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
    Super::SetupPlayerInputComponent(PlayerInputComponent);

    if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerInputComponent))
    {
        EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &ABaseCharacter::Move);
        EnhancedInputComponent->BindAction(LookAction, ETriggerEvent::Triggered, this, &ABaseCharacter::Look);

                
        EnhancedInputComponent->BindAction(InteractAction, ETriggerEvent::Triggered, this, &ABaseCharacter::Interact);

    }
}

void ABaseCharacter::Move(const FInputActionValue& Value)
{
    // Get the movement vector from the input action (which should be a FVector2D)
    const FVector2D MovementVector = Value.Get<FVector2D>();

    if (Controller && (MovementVector.X != 0.0f || MovementVector.Y != 0.0f))
    {
        // Get the rotation of the controller
        const FRotator Rotation = Controller->GetControlRotation();
        const FRotator YawRotation(0, Rotation.Yaw, 0);

        // Get forward and right vectors based on controller's yaw rotation
        const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
        const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

        // Move character based on the forward and right direction, scaled by input value
        AddMovementInput(ForwardDirection, MovementVector.Y);
        AddMovementInput(RightDirection, MovementVector.X);
    }
        // const auto Rotation = Controller->GetControlRotation();
        // const FRotator YawRotation(0, Rotation.Yaw, 0);

        // const auto ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
        // const auto RightDirectionDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);


        // AddMovementInput(GetActorForwardVector(), MovementVector.Y);
        // AddMovementInput(GetActorRightVector(), MovementVector.X);
}


void ABaseCharacter::Look(const FInputActionValue& Value)
{
    const FVector2D LookAxisVector = Value.Get<FVector2D>();

    if (Controller)
    {
        // Apply a scaling factor to control sensitivity
        AddControllerYawInput(LookAxisVector.X);
        AddControllerPitchInput(LookAxisVector.Y);
    }
}

void ABaseCharacter::Interact(const FInputActionValue& Value)
{
    Interact_Server();
}

void ABaseCharacter::Interact_Server_Implementation()
{
    if(InteractableActor)
    {
        IGame_Interactable::Execute_Interact(InteractableActor, this);
    }
}

bool ABaseCharacter::isInteracting()
{
    // this line is to make sure only the server will perform the traces for all the characters
    if(HasAuthority())
    {
        // FCollisionQueryParams QueryParams;
        // QueryParams.bTraceComplex = true; // trace against complex collisions
        // QueryParams.AddIgnoredActor(this);

        
        FHitResult HitResult;
        FVector Start = GetActorLocation(); // Starting point is the character's location
        FVector ForwardVector = GetActorForwardVector(); // Get the forward direction the character is facing
        FVector End = Start + (ForwardVector * 200.0f); // End point is some distance in front of the character 
        float SphereRadius = 30.f;
         // Trace channel - use ECC_Visibility if you are checking for visible objects
        ETraceTypeQuery TraceChannel = UEngineTypes::ConvertToTraceType(ECC_Visibility);

        // perform sphere trace to check whether the character is pointing at something
        // sphere trace single is used to perform a single trace in the shape of a sphere
        // along a line between 2 points
        bool bIsHitSuccessful = UKismetSystemLibrary::SphereTraceSingle(GetWorld(), Start, End, SphereRadius,  
        TraceChannel, false, TArray<AActor*>{this}, EDrawDebugTrace::ForOneFrame, HitResult, true);
    
        // check if HitResult is valid and then if HitResult hit actor implements the UGame_Interactable interface.
        if(bIsHitSuccessful && HitResult.GetActor() && HitResult.GetActor()->GetClass()->ImplementsInterface(UGame_Interactable::StaticClass()))
        {
            DrawDebugSphere(GetWorld(), HitResult.ImpactPoint, SphereRadius, 15, FColor::Red, false, 1.f);
            InteractableActor = HitResult.GetActor();
        }
        else 
        {
            InteractableActor = nullptr;
        }

    }

    return false;
}

void ABaseCharacter::SetOverlappingWeapon(TWeakObjectPtr<ABaseWeapon> Weapon)
{
    UE_LOG(LogTemp, Warning, TEXT("Set Overlapping weapon called and has authority"));
    if (HasAuthority())
    {
        overlappingWeapon = Weapon;
        OnRep_OverlappingWeapon(); // Optional to update locally
    }
}

void ABaseCharacter::OnRep_OverlappingWeapon()
{

}

void ABaseCharacter::OnRep_CurrentWeapon()
{

}


void ABaseCharacter::EquipWeapon(ABaseWeapon* weaponToEquip)
{
    // if (weaponToEquip)
    // {
    //     equippedWeapon = weaponToEquip;
    //     // Additional logic to attach the weapon to the character
    //     UE_LOG(LogTemp, Log, TEXT("Weapon equipped: %s"), *weaponToEquip->GetName());
    // }
}






