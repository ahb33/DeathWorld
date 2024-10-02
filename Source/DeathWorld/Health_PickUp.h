// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Base_PickUp.h"
#include "Health_PickUp.generated.h"

/**
 	delete later and sub with enum classes
 */
UCLASS()
class DEATHWORLD_API AHealth_PickUp : public ABase_PickUp
{
	GENERATED_BODY()

public:

	AHealth_PickUp();

private:

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Testing", meta = (AllowPrivateAccess = "true"))	
	TObjectPtr<class UStaticMeshComponent> PickUpMesh;
	
};
