// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Animation/AnimInstance.h"
#include "BaseAnimInstance.generated.h"

/**
 * 
 */
UCLASS()
class DEATHWORLD_API UBaseAnimInstance : public UAnimInstance
{
	GENERATED_BODY()


public:
    virtual void NativeInitializeAnimation() override; 
    virtual void NativeUpdateAnimation(float DeltaTime) override;
    virtual void UpdateMovementProperties();
    virtual void UpdateCharacterProperties(float);
    virtual void UpdateWeaponProperties();

protected:

    // Reference to the pawn and the character
    UPROPERTY(BlueprintReadOnly)
    APawn* Pawn;

    class ABaseCharacter* Character; // Cached character pointer for reuse

    /*
        Common helper functions; update base movement properties below and a
        later customize for Main which will have weapon and aiming checks
    
    */

    // Template function to get and cast the Pawn
    template<typename T>
    T* CachePawn()
    {
        if (!Pawn)
        {
            Pawn = TryGetPawnOwner();
        }

        if (Pawn)
        {
            return Cast<T>(Pawn);
        }
        return nullptr;
    }

    virtual void CacheCharacter() PURE_VIRTUAL(UBaseAnimInstance::CacheCharacter, );

private:

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Animation, meta = (AllowPrivateAccess = "true"))
	float MovementSpeed; // we only want C++ to alter this variable
    
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Animation, meta = (AllowPrivateAccess = "true"))
	bool bIsInAir; // this variable will check if the character is  in the air

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Animation, meta = (AllowPrivateAccess = "true"))
	bool bIsAccelerating; // this variable will check if the character is accelerating

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Animation, meta = (AllowPrivateAccess = "true"))
	bool bIsCrouching;
 
    // both AI and mainchaaracter will need to update their animation based on weather weapon is equipped
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Animation, meta = (AllowPrivateAccess = "true"))
    bool bWeaponEquipped;

	UPROPERTY(VisibleAnywhere,BlueprintReadOnly, Category = Animation, meta = (AllowPrivateAccess = "true"))
	bool bFireWeapon;

	UPROPERTY(VisibleAnywhere,BlueprintReadOnly, Category = Animation, meta = (AllowPrivateAccess = "true"))
	bool bAiming;

    UPROPERTY(BlueprintReadOnly, Category = Animation, meta = (AllowPrivateAccess = "true"))
	bool bIsPlayerReloading;

    UPROPERTY(BlueprintReadOnly, Category = Movement, meta = (AllowPrivateAccess = "true"))
	bool bLocallyControlled;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Animation, meta = (AllowPrivateAccess = "true"))
	float YawOffset;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Animation, meta = (AllowPrivateAccess = "true"))
	float Lean;

    UPROPERTY(BlueprintReadOnly, Category = Animation, meta = (AllowPrivateAccess = "true"))
	float AO_Yaw;

	UPROPERTY(BlueprintReadOnly, Category = Animation, meta = (AllowPrivateAccess = "true"))
	float AO_Pitch;
    
    UPROPERTY(BlueprintReadOnly, Category = Animation, meta = (AllowPrivateAccess = "true"))
	FTransform LeftHandTransform; 

    UPROPERTY(BlueprintReadOnly, Category = Movement, meta = (AllowPrivateAccess = "true"))
	FRotator RightHandRotation;

    UPROPERTY(BlueprintReadOnly, Category = Animation, meta = (AllowPrivateAccess = "true"))
	bool bUseFABRIK;




};
