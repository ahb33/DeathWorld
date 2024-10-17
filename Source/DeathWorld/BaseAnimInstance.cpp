// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseAnimInstance.h"
#include "GameFramework/CharacterMovementComponent.h" 
#include "Misc/App.h"
<<<<<<< HEAD
#include "BaseCharacter.h"
=======
>>>>>>> 0bcdb22c66cd4a7c278cb80e5b52113ddf83a582
#include "Kismet/KismetMathLibrary.h"

void UBaseAnimInstance::NativeInitializeAnimation()
{
    Super::NativeInitializeAnimation();
<<<<<<< HEAD

    Character = CachePawn<ABaseCharacter>(); 
=======
    
>>>>>>> 0bcdb22c66cd4a7c278cb80e5b52113ddf83a582
}

// the base NativeUpdateAnimation should retreive the pawn for all inherited classes
void UBaseAnimInstance::NativeUpdateAnimation(float DeltaTime)
{
    Super::NativeUpdateAnimation(DeltaTime);
<<<<<<< HEAD

    if (!Character) return; // Early return if character is not cached

    UpdateMovementProperties();
    UpdateCharacterProperties(DeltaTime);
    UpdateWeaponProperties();
=======
    UpdateMovementProperties();

    
>>>>>>> 0bcdb22c66cd4a7c278cb80e5b52113ddf83a582
}

void UBaseAnimInstance::UpdateMovementProperties()
{
    /*
<<<<<<< HEAD
         set acceleration, movement speed, bIsInAir for base character which inherits to both Main and AI 
    
    */
=======
        set acceleration, movement speed, binair for base character which inherits to both Main and AI 
    
    */
    if(!Pawn) return;

>>>>>>> 0bcdb22c66cd4a7c278cb80e5b52113ddf83a582
    FVector Speed = Pawn->GetVelocity();
    FVector LateralSpeed = FVector(Speed.X, Speed.Y, 0.f);
    MovementSpeed = LateralSpeed.Size();

<<<<<<< HEAD
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
=======
    // Ensure the Movement Component is valid before accessing it
    if (Pawn->GetMovementComponent())
    {
        bIsInAir = Pawn->GetMovementComponent()->IsFalling();

        // Cast pawn to Character variable we can use
        ACharacter* Character = Cast<ACharacter>(Pawn);
        if (Character)
        {
            bIsAccelerating = Character->GetCharacterMovement()->GetCurrentAcceleration().Size() > 0;
        }
    }
>>>>>>> 0bcdb22c66cd4a7c278cb80e5b52113ddf83a582

}
