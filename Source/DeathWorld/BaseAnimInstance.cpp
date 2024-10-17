// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseAnimInstance.h"
#include "GameFramework/CharacterMovementComponent.h" 
#include "Misc/App.h"
#include "BaseCharacter.h"
#include "Kismet/KismetMathLibrary.h"

void UBaseAnimInstance::NativeInitializeAnimation()
{
    Super::NativeInitializeAnimation();

    Character = CachePawn<ABaseCharacter>(); 
}

// the base NativeUpdateAnimation should retreive the pawn for all inherited classes
void UBaseAnimInstance::NativeUpdateAnimation(float DeltaTime)
{
    Super::NativeUpdateAnimation(DeltaTime);

    if (!Character) return; // Early return if character is not cached

    UpdateMovementProperties();
    UpdateCharacterProperties(DeltaTime);
    UpdateWeaponProperties();
}

void UBaseAnimInstance::UpdateMovementProperties()
{
    /*
         set acceleration, movement speed, bIsInAir for base character which inherits to both Main and AI 
    
    */
    FVector Speed = Pawn->GetVelocity();
    FVector LateralSpeed = FVector(Speed.X, Speed.Y, 0.f);
    MovementSpeed = LateralSpeed.Size();

    bIsInAir = Pawn->GetMovementComponent()->IsFalling();
    bIsAccelerating = Character->GetCharacterMovement()->GetCurrentAcceleration().Size() > 0;


}

void UBaseAnimInstance::UpdateCharacterProperties(float)
{
    bAiming = Character->IsAiming();
    auto equippedWeapon = Character->GetCurrentWeapon();


}


void UBaseAnimInstance::UpdateWeaponProperties()
{
    bWeaponEquipped = Character->IsWeaponEquipped();

}
