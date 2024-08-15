// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Base_PickUp.generated.h"

UCLASS()
class DEATHWORLD_API ABase_PickUp : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABase_PickUp();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	FORCEINLINE class USphereComponent* GetSphereCollision() const {return SphereCollision;}

	FORCEINLINE class UStaticMeshComponent* GetMesh() const { return PickUpMesh; }

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


	// Function to handle overlap events
	UFUNCTION()
	void OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, 
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, 
	const FHitResult & SweepResult);

	// The BlueprintNativeEvent specifier allows a C++ function to be overridden in Blueprints.
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void OnPickUp(class AMainCharacter* OverlappingPlayer);
	

private:

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<class USphereComponent> SphereCollision;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))	
	TObjectPtr<class UStaticMeshComponent> PickUpMesh;

};
