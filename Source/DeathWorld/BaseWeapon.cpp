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

}

void ABaseWeapon::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);

    DOREPLIFETIME(ABaseWeapon, equippedWeapon);
	DOREPLIFETIME(ABaseWeapon, secondaryWeapon);
    DOREPLIFETIME(ABaseWeapon, primaryWeapon);


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
    // currentWeapon->SetOwner(baseCharacter);
    // if (!baseCharacter)
    // {
    //     UE_LOG(LogTemp, Warning, TEXT("Base Character is still not valid"));
    //     return;
    // }
	/*
        if no weapon is equipped equip primary weapon else equip secondary else if both equipped then swap

	*/

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

    if (baseCharacter) // Check baseCharacter validity
    {
        UE_LOG(LogTemp, Warning, TEXT("Base character is finally valid"));
    }
    else  UE_LOG(LogTemp, Warning, TEXT("Base character is not valid"));

}

void ABaseWeapon::EquipSecondaryWeapon(TWeakObjectPtr<class ABaseWeapon> SecondWeapon)
{

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

void ABaseWeapon::OnRep_EquippedWeapon()
{

}

void ABaseWeapon::OnRep_SecondaryWeapon()
{
	
}


void ABaseWeapon::SwapWeapons()
{

}



void ABaseWeapon::HandleAttachToSocket()
{
    // // Ensure the equipped weapon is valid
    // if (!equippedWeapon.IsValid())
    // {
    //     UE_LOG(LogTemp, Warning, TEXT("HandleAttachToSocket: equippedWeapon is not valid"));
    //     return;
    // }

    // // Ensure the owning character is valid
    // if (!baseCharacter.IsValid() || !baseCharacter->GetMesh())
    // {
    //     UE_LOG(LogTemp, Warning, TEXT("HandleAttachToSocket: baseCharacter or its Mesh is nullptr"));
    //     return;
    // }

    // // Determine the socket name based on weapon type
    // FName SocketName = DetermineSocketNameBasedOnWeaponType();

    // // Attach the weapon to the designated socket on the character mesh
    // // AttachActorToSocketByName(equippedWeapon.Get(), SocketName);
}

// Attach weapon to the right hand.
void ABaseWeapon::AttachActorToRightHand(AActor* WeaponToAttach)
{
    UE_LOG(LogTemp, Log, TEXT("Attempting to attach %s to RightHandSocket"), *WeaponToAttach->GetName());
    AttachActorToSocketByName(WeaponToAttach, FName("RightHandSocket"));
}

// Attach weapon to the secondary weapon socket.
void ABaseWeapon::AttachWeaponToWeaponSocket(AActor* WeaponToAttach)
{
    UE_LOG(LogTemp, Log, TEXT("Attempting to attach %s to SecondaryWeaponSocket"), *WeaponToAttach->GetName());
    AttachActorToSocketByName(WeaponToAttach, FName("SecondaryWeaponSocket"));
}

void ABaseWeapon::AttachActorToSocket(AActor* WeaponToAttach, AActor* TargetActor)
{
    if (!WeaponToAttach || !TargetActor)
    {
        UE_LOG(LogTemp, Warning, TEXT("AttachActorToSocket: WeaponToAttach or TargetActor is nullptr"));
        return;
    }

    // Attach to a socket based on the weapon type
    FName SocketName = DetermineSocketNameBasedOnWeaponType();
    AttachActorToSocketByName(WeaponToAttach, SocketName);
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

void ABaseWeapon::AttachActorToSocketByName(AActor* WeaponToAttach, FName SocketName)
{
    // if (!baseCharacter.IsValid() || !baseCharacter->GetMesh())
    // {
    //     UE_LOG(LogTemp, Warning, TEXT("AttachActorToSocketByName: baseCharacter or its Mesh is nullptr"));
    //     return;
    // }

    // if (!WeaponToAttach)
    // {
    //     UE_LOG(LogTemp, Warning, TEXT("AttachActorToSocketByName: WeaponToAttach is nullptr"));
    //     return;
    // }

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

void ABaseWeapon::SetAiming(bool bIsAiming)
{
}

void ABaseWeapon::ServerSetAiming_Implementation(bool bIsAiming)
{

}

void ABaseWeapon::SetHUDCrosshairs(float DeltaTime)
{

}
