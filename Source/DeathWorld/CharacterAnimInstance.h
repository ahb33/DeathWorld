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

<<<<<<< HEAD
	virtual void UpdateMovementProperties() override;
=======
	    virtual void UpdateMovementProperties() override;
>>>>>>> 0bcdb22c66cd4a7c278cb80e5b52113ddf83a582

    virtual void CacheCharacter() override;


private:

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Animation, meta = (AllowPrivateAccess = "true"))
	class AMainCharacter* MainCharacter;

<<<<<<< HEAD

=======
	UPROPERTY(BlueprintReadOnly, Category = Animation, meta = (AllowPrivateAccess = "true"))
	bool bIsPlayerReloading;

	UPROPERTY(VisibleAnywhere,BlueprintReadOnly, Category = Animation, meta = (AllowPrivateAccess = "true"))
	bool bFireWeapon;
>>>>>>> 0bcdb22c66cd4a7c278cb80e5b52113ddf83a582

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Animation, meta = (AllowPrivateAccess = "true"))
	bool bIsCrouched;

<<<<<<< HEAD

=======
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Animation,meta = (AllowPrivateAccess = "true"))
	bool bWeaponEquipped;

	UPROPERTY(VisibleAnywhere,BlueprintReadOnly, Category = Animation, meta = (AllowPrivateAccess = "true"))
	bool bAiming;
>>>>>>> 0bcdb22c66cd4a7c278cb80e5b52113ddf83a582
	
};
