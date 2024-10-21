// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseWeapon.h"
#include "Components/SphereComponent.h"
#include "Net/UnrealNetwork.h"
#include "Engine/SkeletalMeshSocket.h"
#include "EngineUtils.h"
#include "BaseCharacter.h"
#include "Math/UnrealMathUtility.h" 
#include "MyPlayerController.h"
#include "BasePickUpComponent.h"
#include "WeaponState.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/CharacterMovementComponent.h" 
#include "GameFramework/Actor.h"

// Sets default values
ABaseWeapon::ABaseWeapon()
{
	PrimaryActorTick.bCanEverTick = true;
	bReplicates = true;
	SetReplicateMovement(true);

    weaponMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("weaponMesh"));
	SetRootComponent(weaponMesh); // sets the weaponMesh variable to be the root component

	// weaponMesh->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Block);
	// weaponMesh->SetCollisionResponseToChannel(ECollisionChannel::ECC_Pawn, ECollisionResponse::ECR_Ignore); /*
	// if you want the pawn to run through the weapon without colliding with it */
	// weaponMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);

    weaponMesh->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Block);
    weaponMesh->SetCollisionResponseToChannel(ECollisionChannel::ECC_Pawn, ECollisionResponse::ECR_Ignore);
    weaponMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);
    weaponMesh->SetCollisionObjectType(ECollisionChannel::ECC_WorldDynamic);

    // Initialize the pickup component
    basePickUpComponent = CreateDefaultSubobject<UBasePickUpComponent>(TEXT("BasePickUpComponent"));
    // basePickUpComponent->SetupAttachment(RootComponent);

    primaryWeapon = nullptr;
    secondaryWeapon = nullptr;
    equippedWeapon = nullptr;
    
}

// Called when the game starts or when spawned
void ABaseWeapon::BeginPlay()
{
	Super::BeginPlay();

}


void ABaseWeapon::OnSphereOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
    UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
	// you only want overlap events to happen on the server
{

}


void ABaseWeapon::OnSphereEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{

}

// Called every frame
void ABaseWeapon::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

    FHitResult HitResult;
	CrossHairTrace(HitResult);

	SetHUDCrosshairs(DeltaTime);


}

void ABaseWeapon::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);

    DOREPLIFETIME(ABaseWeapon, equippedWeapon);
	DOREPLIFETIME(ABaseWeapon, secondaryWeapon);
    DOREPLIFETIME(ABaseWeapon, primaryWeapon);
    DOREPLIFETIME(ABaseWeapon, WeaponState);


    DOREPLIFETIME(ABaseWeapon, bIsFiring);
    DOREPLIFETIME(ABaseWeapon, CrosshairVelocityFactor);

}


void ABaseWeapon::SetFiringState(bool bFire)
{
	bFireButtonPressed = bFire;

	if(!equippedWeapon.IsValid()) return;

	if (baseCharacter && bFireButtonPressed)
	{
		FHitResult TraceHitResult;
		FVector HitTarget = CrossHairTrace(TraceHitResult);

		if(HitTarget!= FVector::ZeroVector)
		{  
			equippedWeapon->Fire(HitTarget);

		}
	}
}
void ABaseWeapon::Fire(const FVector& Hit)
{

}

bool ABaseWeapon::WeaponIsEmpty() const
{
    return false;
}


void ABaseWeapon::EquipWeapon(TWeakObjectPtr<class ABaseWeapon> currentWeapon)
{
    baseCharacter = baseCharacter == nullptr ? Cast<ABaseCharacter>(GetOwner()) : baseCharacter;
    if(baseCharacter) 
    {        
        UE_LOG(LogTemp, Warning, TEXT("Owner character is still valid"));
    }
    else 
    {
        UE_LOG(LogTemp, Warning, TEXT("Owner Character is still not valid"));
        return;
    }

	// if no primary weapon is equipped, EquipSecondary
	// if secondary weapon is equipped, EquipPrimary
	// else swap weapon

    // If there's no primary weapon equipped, equip this one as primary.
    if (!primaryWeapon.IsValid())
    {
        EquipPrimaryWeapon(currentWeapon);
    }
    // If no secondary weapon is equipped and currentWeapon is different, equip as secondary.
    else if (!secondaryWeapon.IsValid() && primaryWeapon != currentWeapon)
    {
        EquipSecondaryWeapon(currentWeapon);
    }
    // If both primary and secondary weapons are equipped, swap them.
    else if (primaryWeapon.IsValid() && secondaryWeapon.IsValid())
    {
        SwapWeapons();
    }

}
void ABaseWeapon::EquipPrimaryWeapon(TWeakObjectPtr<class ABaseWeapon> firstWeapon)
{
    UE_LOG(LogTemp, Warning, TEXT("Equip primary weapon called"));

    if(firstWeapon == nullptr) return;

	equippedWeapon = firstWeapon;
    if(equippedWeapon.IsValid())
    {
        UE_LOG(LogTemp, Warning, TEXT("Equipped weapon is valid"));
    }
    equippedWeapon->SetWeaponState(EWeaponState::EWS_Equipped);
    
    const USkeletalMeshSocket* HandSocket = baseCharacter->GetMesh()->GetSocketByName(FName("RightHandSocket"));
    if (HandSocket) HandSocket->AttachActor(equippedWeapon.Get(), baseCharacter->GetMesh());

    SetHUDCrosshairs(0.f);
}

void ABaseWeapon::EquipSecondaryWeapon(TWeakObjectPtr<class ABaseWeapon> SecondWeapon)
{

}

void ABaseWeapon::OnRep_EquippedWeapon()
{

}

void ABaseWeapon::OnRep_SecondaryWeapon()
{
	
}


void ABaseWeapon::SwapWeapons()
{

}



// Attach weapon to the secondary weapon socket.
void ABaseWeapon::AttachWeaponToWeaponSocket(AActor* WeaponToAttach)
{
    // if (!baseCharacter || !baseCharacter->GetMesh())
    // {
    //     UE_LOG(LogTemp, Warning, TEXT("Base character or Mesh is nullptr"));
    //     return;
    // }

    // // Determine the correct socket based on weapon type
    // FName SocketName = DetermineSocketNameBasedOnWeaponType();
    
    // // Attach the weapon to the appropriate socket
    // const USkeletalMeshSocket* Socket = baseCharacter->GetMesh()->GetSocketByName(SocketName);
    // if (Socket)
    // {
    //     Socket->AttachActor(WeaponToAttach, baseCharacter->GetMesh());
    //     UE_LOG(LogTemp, Log, TEXT("Successfully attached %s to socket %s"), *WeaponToAttach->GetName(), *SocketName.ToString());
    // }
    // else
    // {
    //     UE_LOG(LogTemp, Warning, TEXT("Failed to attach %s to socket %s: Socket not found"), *WeaponToAttach->GetName(), *SocketName.ToString());
    // }
}

FName ABaseWeapon::DetermineSocketNameBasedOnWeaponType() const
{
    switch (WeaponType)
    {
        case EWeaponType::EWT_HandGun:
            return FName("HolsterSocket");
        case EWeaponType::EWT_AssaultRifle:
        case EWeaponType::EWT_Shotgun:
        case EWeaponType::EWT_SniperRifle:
            return FName("WeaponSocket");
        default:
            return FName("DefaultSocket");
    }
}

void ABaseWeapon::OnRep_Owner()
{
	Super::OnRep_Owner();
	if(Owner == nullptr)
	{
		baseCharacter = nullptr;
        playerController = nullptr;
	}
	else
	{
        baseCharacter = baseCharacter == nullptr ? Cast<ABaseCharacter>(Owner) : baseCharacter;
        
        if(baseCharacter)
        {
            UE_LOG(LogTemp, Warning, TEXT("base character successfully cast"));
        }
	}
}

void ABaseWeapon::SetWeaponState(EWeaponState NewState)
{
    WeaponState = NewState;
    HandleWeaponState();
}

void ABaseWeapon::OnRep_WeaponState()
{
    HandleWeaponState();
}

void ABaseWeapon::HandleWeaponState()
{
    switch (WeaponState)
    {
    case EWeaponState::EWS_Equipped:
        PrimaryEquippedState();
        break;
    
    case EWeaponState::EWS_EquippedSecondary:
        SecondaryEquippedState();
        break;
        
    case EWeaponState::EWS_Dropped:
        ConfigureDroppedState();
        break;
    }
}

void ABaseWeapon::PrimaryEquippedState()
{
    // hide pick up widget
    basePickUpComponent->GetAreaSphere()->SetCollisionEnabled(ECollisionEnabled::NoCollision);    
    weaponMesh->SetSimulatePhysics(false);
    weaponMesh->SetEnableGravity(false);
    weaponMesh->SetSimulatePhysics(false);
    weaponMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);
}

void ABaseWeapon::SecondaryEquippedState()
{
    // basePickUpComponent->GetAreaSphere()->SetCollisionEnabled(ECollisionEnabled::NoCollision);
    // weaponMesh->SetSimulatePhysics(false);
    // weaponMesh->SetEnableGravity(false);
    // weaponMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);
}

void ABaseWeapon::ConfigureDroppedState()
{
    basePickUpComponent->GetAreaSphere()->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
    weaponMesh->SetSimulatePhysics(true);
    weaponMesh->SetEnableGravity(true);
    weaponMesh->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
    weaponMesh->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Block);
    weaponMesh->SetCollisionResponseToChannel(ECollisionChannel::ECC_Pawn, ECollisionResponse::ECR_Ignore);
    weaponMesh->SetCollisionResponseToChannel(ECollisionChannel::ECC_Camera, ECollisionResponse::ECR_Ignore);
}

FVector ABaseWeapon::CrossHairTrace(FHitResult& TraceHitResult)
{    
	FVector2D ViewportSize;

    if (GEngine && GEngine->GameViewport)
    {
        GEngine->GameViewport->GetViewportSize(ViewportSize);
        // UE_LOG(LogTemp, Warning, TEXT("Viewport Size: %s"), *ViewportSize.ToString());
    }

    FVector2D CrosshairLocation(ViewportSize.X / 2.f, ViewportSize.Y / 2.f);
    FVector CrosshairWorldPosition;
    FVector CrosshairWorldDirection;

    bool bScreenToWorld = UGameplayStatics::DeprojectScreenToWorld(
        UGameplayStatics::GetPlayerController(this, 0), CrosshairLocation, CrosshairWorldPosition,
        CrosshairWorldDirection
    );

    // UE_LOG(LogTemp, Warning, TEXT("Crosshair Location: %s"), *CrosshairLocation.ToString());
    // UE_LOG(LogTemp, Warning, TEXT("Crosshair World Position: %s"), *CrosshairWorldPosition.ToString());
    // UE_LOG(LogTemp, Warning, TEXT("Crosshair World Direction: %s"), *CrosshairWorldDirection.ToString());

    if (bScreenToWorld)
    {
        FVector Start = CrosshairWorldPosition;
        FVector End = Start + CrosshairWorldDirection * Trace_Length;
        bool bHit = GetWorld()->LineTraceSingleByChannel(TraceHitResult, Start, End, ECollisionChannel::ECC_Visibility);

        if (bHit && TraceHitResult.bBlockingHit)
        {
            LocalHitTarget = TraceHitResult.ImpactPoint;
            // UE_LOG(LogTemp, Warning, TEXT("Line Trace Hit at: %s"), *TraceHitResult.ImpactPoint.ToString());
            return TraceHitResult.ImpactPoint;
        }
        else
        {
            UE_LOG(LogTemp, Warning, TEXT("Line Trace did not hit"));
            return End;
        }
    }

    UE_LOG(LogTemp, Warning, TEXT("Screen to World conversion failed"));
    return FVector::ZeroVector;
}

void ABaseWeapon::SetHUDCrosshairs(float DeltaTime)
{
    if (baseCharacter == nullptr) return;

    AMyPlayerController* PlayerController = Cast<AMyPlayerController>(baseCharacter->GetController());
    if (PlayerController == nullptr)
    {
        UE_LOG(LogTemp, Warning, TEXT("Failed to cast MainCharacter's controller to AMyPlayerController"));
        return;
    }

    HUD = HUD == nullptr ? Cast<AMyHUD>(PlayerController->GetHUD()) : HUD;
    if (HUD)
    {
        if (equippedWeapon == nullptr)
        {
            // UE_LOG(LogTemp, Warning, TEXT("Equipped Weapon not valid in set HUD"));
            return;
        }

        HUDPackage.CrosshairsCenter = equippedWeapon->CrosshairsCenter;
        HUDPackage.CrosshairsLeft = equippedWeapon->CrosshairsLeft;
        HUDPackage.CrosshairsRight = equippedWeapon->CrosshairsRight;
        HUDPackage.CrosshairsBottom = equippedWeapon->CrosshairsBottom;
        HUDPackage.CrosshairsTop = equippedWeapon->CrosshairsTop;

        FVector2D SpeedRange(0.f, baseCharacter->GetCharacterMovement()->MaxWalkSpeed);
        FVector2D VelocityRange(0.f , 1.f);
        FVector Velocity = baseCharacter->GetVelocity();
        Velocity.Z = 0.f;

        CrosshairVelocityFactor = FMath::GetMappedRangeValueClamped(SpeedRange, VelocityRange, Velocity.Size());

        HUDPackage.CrosshairSpread = FMath::Clamp(0.5f + CrosshairVelocityFactor, 0.f, 1.f);

        HUD->SetHUDPackage(HUDPackage);
    }
}



