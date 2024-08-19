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

	// FORCEINLINE USpringArmComponent* GetCameraBoom() const {return CameraBoom; }

	// FORCEINLINE UCameraComponent* GetFollowCamera() const {return FollowCamera; }

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void SprintStart(const FInputActionValue& Value);
	void SprintEnd(const FInputActionValue& Value);

	void Interact(const FInputActionValue& Value);

	UFUNCTION(Server, Reliable)
	void Interact_Server();

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
	TObjectPtr<class UInputAction> InteractAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Movement, meta = (AllowPrivateAccess = "true"))
    float speedMultiplier;

	// add refence to actor that will be interacted with
	UPROPERTY()
	AActor* InteractableActor;



};
