// Fill out your copyright notice in the Description page of Project Settings.


#include "MainCharacter.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "EnhancedInputComponent.h"
#include "Game_Interactable.h"
#include "Kismet/KismetSystemLibrary.h"
#include "EnhancedInputSubsystems.h"

// Sets default values
AMainCharacter::AMainCharacter()
{
    PrimaryActorTick.bCanEverTick = true;

    // Initialize specific input actions
    SprintAction = nullptr;
    InteractAction = nullptr;

    // static ConstructorHelpers::FObjectFinder<USkeletalMesh> SkeletalMeshAsset(TEXT("/Game/KayKit/Characters/rogue"));
    // if (SkeletalMeshAsset.Succeeded())
    // {
    //     GetMesh()->SetSkeletalMesh(SkeletalMeshAsset.Object);
    //     GetMesh()->SetRelativeLocation(FVector(0.f, 0.f, -91.f));
    // }
}

void AMainCharacter::BeginPlay()
{
    Super::BeginPlay();
}

void AMainCharacter::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    // if actor does not have authority return
    if(!HasAuthority()) return;

    isInteracting();



}

void AMainCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
    Super::SetupPlayerInputComponent(PlayerInputComponent);

    if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerInputComponent))
    {
        EnhancedInputComponent->BindAction(SprintAction, ETriggerEvent::Triggered, this, &AMainCharacter::SprintStart);
        EnhancedInputComponent->BindAction(SprintAction, ETriggerEvent::Completed, this, &AMainCharacter::SprintEnd);
        EnhancedInputComponent->BindAction(InteractAction, ETriggerEvent::Triggered, this, &AMainCharacter::Interact);
    }
}

void AMainCharacter::SprintStart(const FInputActionValue& Value)
{
    SprintStart_Server();
}

void AMainCharacter::SprintStart_Server_Implementation()
{

    GetCharacterMovement()->MaxWalkSpeed *= speedMultiplier;
}



void AMainCharacter::SprintEnd(const FInputActionValue& Value)
{
    SprintEnd_Server();
}

void AMainCharacter::SprintEnd_Server_Implementation()
{

    GetCharacterMovement()->MaxWalkSpeed *= speedMultiplier;
}



void AMainCharacter::Interact(const FInputActionValue& Value)
{
    Interact_Server();
}

void AMainCharacter::Interact_Server_Implementation()
{
    if(InteractableActor)
    {
        IGame_Interactable::Execute_Interact(InteractableActor, this);
    }
}

bool AMainCharacter::isInteracting()
{
    // this line is to make sure only the sevrer will perform the traces for all the characters
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
        // sphere trace single is used to perform a single trce in the shape of a sphere
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