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
    if (!Character) return; // Early return if character is not cached

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
    bWeaponEquipped = Character->IsWeaponEquipped();
    bAiming = Character->IsPlayerAiming();
    bIsCrouching = Character->bIsCrouched;
      
    AO_Yaw = Character->GetCharacterYaw();
    AO_Pitch = Character->GetCharacterPitch();



}


void UBaseAnimInstance::UpdateWeaponProperties()
{
    auto equippedWeapon = Character->GetCurrentWeapon();

    if(bWeaponEquipped && equippedWeapon.IsValid() && equippedWeapon->GetWeaponMesh() && Character->GetMesh())
    {
        /*

            get transform of socket we placed on weapon using GetSocketTransform(FName InSocketName, ERelativeTransformSpace TransformSpace)
            
            then we need to use TransformToBoneSpace which takes the following parameters 
            FName BoneName : name of bone on character 
            FVector InPosition : transform of LefthandTransform
            FRotator InRotation : 
            FVector& OutPosition 
            FRotator& OutRotation)
        
        
        */  
        LeftHandTransform = equippedWeapon->GetWeaponMesh()->GetSocketTransform(FName("LeftHandSocket"), ERelativeTransformSpace::RTS_World);

        FVector OutPosition;
        FRotator OutRotation;
        // Transform to bone space (hand_r) to set proper positioning        
        // TransformToBoneSpace transform LeftHandSocket on weapon into bonespace for bone on our character :
        // it converts a world-space position and rotation to the local space of a specific bone on the mesh.
        Character->GetMesh()->TransformToBoneSpace(FName("hand_r"), LeftHandTransform.GetLocation(), FRotator::ZeroRotator, OutPosition, OutRotation);
        
        LeftHandTransform.SetLocation(OutPosition);
        LeftHandTransform.SetRotation(FQuat(OutRotation));



        if(Character->IsLocallyControlled())
        {
            bLocallyControlled = true;
            FTransform RightHandTransform = equippedWeapon->GetWeaponMesh()->GetSocketTransform(FName("hand_r"), ERelativeTransformSpace::RTS_World);
            FRotator LookAtRotation = UKismetMathLibrary::FindLookAtRotation(RightHandTransform.GetLocation(), RightHandTransform.GetLocation() + (RightHandTransform.GetLocation() - Character->GetHitTarget()));
        }   
    }
}
