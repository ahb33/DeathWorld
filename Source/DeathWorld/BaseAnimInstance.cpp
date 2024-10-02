// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseAnimInstance.h"
#include "GameFramework/CharacterMovementComponent.h" 
#include "Misc/App.h"
#include "Kismet/KismetMathLibrary.h"

void UBaseAnimInstance::NativeInitializeAnimation()
{
    Super::NativeInitializeAnimation();
    
}

// the base NativeUpdateAnimation should retreive the pawn for all inherited classes
void UBaseAnimInstance::NativeUpdateAnimation(float DeltaTime)
{
    Super::NativeUpdateAnimation(DeltaTime);
    UpdateMovementProperties();

    
}

void UBaseAnimInstance::UpdateMovementProperties()
{
    /*
        set acceleration, movement speed, binair for base character which inherits to both Main and AI 
    
    */
    if(!Pawn) return;

    FVector Speed = Pawn->GetVelocity();
    FVector LateralSpeed = FVector(Speed.X, Speed.Y, 0.f);
    MovementSpeed = LateralSpeed.Size();

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

}
