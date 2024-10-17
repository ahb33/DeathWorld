// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseCharacter.h"
#include "GameFramework/Character.h"
#include "UObject/ConstructorHelpers.h"
#include "MainCharacter.generated.h"

UCLASS()
class DEATHWORLD_API AMainCharacter : public ABaseCharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMainCharacter();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

<<<<<<< HEAD
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

	void Equip();

    // call on client and execute on server; use reliable sparingly and never in tick function
    UFUNCTION(Server, Reliable)
    void ServerEquipButtonPressed();


=======
>>>>>>> 0bcdb22c66cd4a7c278cb80e5b52113ddf83a582
	// FORCEINLINE USpringArmComponent* GetCameraBoom() const {return CameraBoom; }

	// FORCEINLINE UCameraComponent* GetFollowCamera() const {return FollowCamera; }

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void SprintStart(const FInputActionValue& Value);
	void SprintEnd(const FInputActionValue& Value);

	void JumpStart(const FInputActionValue& Value);
	void JumpEnd(const FInputActionValue& Value);

	void EquipButtonPressed(const FInputActionValue& Value);
<<<<<<< HEAD
	void FireButtonPressed(const FInputActionValue& Value);
	void FireButtonReleased(const FInputActionValue& Value);
	void AimButtonPressed();
	void AimButtonReleased();
=======
	void Equip();
>>>>>>> 0bcdb22c66cd4a7c278cb80e5b52113ddf83a582


	UFUNCTION(Server, Reliable)
	void SprintStart_Server();

	UFUNCTION(Server, Reliable)
	void SprintEnd_Server();

	/*
		this function will be used to check if a player is interacting with another object and
		will be called every frame
		
	*/
	bool isInteracting();

private:

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<class UInputAction> SprintAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<class UInputAction> JumpAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<class UInputAction> EquipAction;

<<<<<<< HEAD
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<class UInputAction> FireAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<class UInputAction> AimAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Movement, meta = (AllowPrivateAccess = "true"))
    float speedMultiplier;

=======
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Movement, meta = (AllowPrivateAccess = "true"))
    float speedMultiplier;




>>>>>>> 0bcdb22c66cd4a7c278cb80e5b52113ddf83a582
};
