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

protected:

    // Reference to the pawn and the character
    UPROPERTY(BlueprintReadOnly)
    APawn* Pawn;

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

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Animation,meta = (AllowPrivateAccess = "true"))
	bool bIsAccelerating; // this variable will check if the character is accelerating

    

	
};
