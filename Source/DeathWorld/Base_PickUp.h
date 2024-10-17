// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Base_PickUp.generated.h"

UCLASS(Abstract) // Making the class abstract
class DEATHWORLD_API ABase_PickUp : public AActor
{
	GENERATED_BODY()
	
public:	
	ABase_PickUp();

	virtual void Tick(float DeltaTime) override;

	FORCEINLINE class USphereComponent* GetAreaSphere() const { return AreaSphere.Get(); }

protected:
	virtual void BeginPlay() override;

	// Pure virtual function to initialize specific mesh components
	virtual void InitializeMesh() PURE_VIRTUAL(ABase_PickUp::InitializeMesh, );

	virtual void ShowWidget() { };

	UFUNCTION()
	virtual void OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult);

	UFUNCTION()
	virtual void OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void OnPickUp(class AMainCharacter* OverlappingPlayer);

private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<class USphereComponent> AreaSphere;
};