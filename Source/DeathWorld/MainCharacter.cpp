// Fill out your copyright notice in the Description page of Project Settings.


#include "MainCharacter.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "BaseWeapon.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"

// Sets default values
AMainCharacter::AMainCharacter()
{
    PrimaryActorTick.bCanEverTick = true;

    // Initialize specific input actions
    SprintAction = nullptr;
    JumpAction = nullptr;
    EquipAction = nullptr;

<<<<<<< HEAD
=======

>>>>>>> 0bcdb22c66cd4a7c278cb80e5b52113ddf83a582
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


}

void AMainCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
    Super::SetupPlayerInputComponent(PlayerInputComponent);

    if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerInputComponent))
    {
        // Bind wrapper functions for jumping
        EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Triggered, this, &AMainCharacter::JumpStart);
        EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Completed, this, &AMainCharacter::JumpEnd);

        EnhancedInputComponent->BindAction(SprintAction, ETriggerEvent::Triggered, this, &AMainCharacter::SprintStart);
        EnhancedInputComponent->BindAction(SprintAction, ETriggerEvent::Completed, this, &AMainCharacter::SprintEnd);

        EnhancedInputComponent->BindAction(EquipAction, ETriggerEvent::Triggered, this, &AMainCharacter::EquipButtonPressed);
<<<<<<< HEAD
        EnhancedInputComponent->BindAction(FireAction, ETriggerEvent::Triggered, this, &AMainCharacter::FireButtonPressed);
        EnhancedInputComponent->BindAction(FireAction, ETriggerEvent::Completed, this, &AMainCharacter::FireButtonReleased);

        EnhancedInputComponent->BindAction(AimAction, ETriggerEvent::Triggered, this, &AMainCharacter::AimButtonPressed);
        EnhancedInputComponent->BindAction(AimAction, ETriggerEvent::Completed, this, &AMainCharacter::AimButtonReleased);



    }
}

void AMainCharacter::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);

}

=======
    }
}

>>>>>>> 0bcdb22c66cd4a7c278cb80e5b52113ddf83a582
void AMainCharacter::SprintStart(const FInputActionValue& Value)
{
    SprintStart_Server();
}

void AMainCharacter::SprintStart_Server_Implementation()
{
    GetCharacterMovement()->MaxWalkSpeed *= speedMultiplier;
}

void AMainCharacter::JumpStart(const FInputActionValue& Value)
{
    Jump(); // Call ACharacter::Jump() directly
    UE_LOG(LogTemp, Warning, TEXT("Jump function called"));
}

void AMainCharacter::JumpEnd(const FInputActionValue& Value)
{
    StopJumping(); // Call ACharacter::StopJumping() directly
}

void AMainCharacter::EquipButtonPressed(const FInputActionValue& Value)
{
    UE_LOG(LogTemp, Warning, TEXT("Equip Button Pressed"));
    Equip();
}

<<<<<<< HEAD
// Server-side implementation
void AMainCharacter::ServerEquipButtonPressed_Implementation()
{
    if (GetOverlappingWeapon().IsValid() && GetCurrentWeapon().IsValid())
    {
        UE_LOG(LogTemp, Warning, TEXT("Overlapped weapons valid on server"));
        GetCurrentWeapon()->EquipWeapon(GetOverlappingWeapon().Get());
    }  
}

// only want equip to be called on server
void AMainCharacter::Equip()
{
    // check if overlapping weapon is valid 
=======
void AMainCharacter::Equip()
{
    // check if overlapping weapon is valid 

>>>>>>> 0bcdb22c66cd4a7c278cb80e5b52113ddf83a582
    if (GetOverlappingWeapon().IsValid() && GetCurrentWeapon().IsValid())
    {
        UE_LOG(LogTemp, Warning, TEXT("Both weapons are valid"));
        if (HasAuthority())
        {
            // Just call EquipWeapon without using it in a conditional check
<<<<<<< HEAD
            // GetCurrentWeapon()->SetOwner(this);
            ServerEquipButtonPressed_Implementation();
        }
        else
        {
            ServerEquipButtonPressed();
=======
            GetCurrentWeapon()->EquipWeapon(GetOverlappingWeapon().Get());
>>>>>>> 0bcdb22c66cd4a7c278cb80e5b52113ddf83a582
        }
    }
    else
    {
<<<<<<< HEAD
        UE_LOG(LogTemp, Warning, TEXT("Weapons are not valid"));
=======
        UE_LOG(LogTemp, Warning, TEXT("One or both variables are invalid"));
>>>>>>> 0bcdb22c66cd4a7c278cb80e5b52113ddf83a582
    }

	// else if (GetCurrentWeapon()->ShouldSwapWeapons())
	// {
	// 	myWeapon->SwapWeapons();
	// }

}


<<<<<<< HEAD
void AMainCharacter::FireButtonPressed(const FInputActionValue& Value)
{
    ServerSetFiring(true);  // Directly request server to start firing
}

void AMainCharacter::FireButtonReleased(const FInputActionValue& Value)
{
    ServerSetFiring(false);  // Directly request server to stop firing
}

void AMainCharacter::AimButtonPressed()
{	
    if (HasAuthority())
    {
        ServerSetAiming(true);
    }
    else
    {
        ServerSetAiming(true);
    }
}


void AMainCharacter::AimButtonReleased()
{
    if (HasAuthority())
    {
        ServerSetAiming(false);
    }
    else
    {
        ServerSetAiming(false);
    }
}

=======
>>>>>>> 0bcdb22c66cd4a7c278cb80e5b52113ddf83a582
void AMainCharacter::SprintEnd(const FInputActionValue& Value)
{
    SprintEnd_Server();
}

void AMainCharacter::SprintEnd_Server_Implementation()
{
    GetCharacterMovement()->MaxWalkSpeed *= speedMultiplier;
}



