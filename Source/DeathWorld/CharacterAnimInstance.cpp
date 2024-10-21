// Fill out your copyright notice in the Description page of Project Settings.


#include "CharacterAnimInstance.h"
#include "MainCharacter.h"

void UCharacterAnimInstance::NativeInitializeAnimation()
{
    Super::NativeInitializeAnimation();
    CacheCharacter();
}

void UCharacterAnimInstance::NativeUpdateAnimation(float DeltaTime)
{
    Super::NativeUpdateAnimation(DeltaTime);
    UpdateMovementProperties();

}

void UCharacterAnimInstance::UpdateMovementProperties()
{
    Super::UpdateMovementProperties();
}

void UCharacterAnimInstance::CacheCharacter()
{
    // Use the template function to cast to AEnemyCharacter
    MainCharacter = CachePawn<AMainCharacter>();
}