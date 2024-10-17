// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseAnimInstance.h"
#include "CharacterAnimInstance.generated.h"

/**
 * 
 */
UCLASS()
class DEATHWORLD_API UCharacterAnimInstance : public UBaseAnimInstance
{
	GENERATED_BODY()


public:
    virtual void NativeInitializeAnimation() override; 
    virtual void NativeUpdateAnimation(float DeltaTime) override;

	virtual void UpdateMovementProperties() override;

    virtual void CacheCharacter() override;


private:

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Animation, meta = (AllowPrivateAccess = "true"))
	class AMainCharacter* MainCharacter;



	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Animation, meta = (AllowPrivateAccess = "true"))
	bool bIsCrouched;


	
};
