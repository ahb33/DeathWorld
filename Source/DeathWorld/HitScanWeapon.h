// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseWeapon.h"
#include "HitScanWeapon.generated.h"

/**
 * 
 */
UCLASS()
class DEATHWORLD_API AHitScanWeapon : public ABaseWeapon
{
	GENERATED_BODY()

public:

	virtual void Fire(const FVector& HitTarget) override;

	void WeaponTraceHit(const FVector& TraceStart, const FVector& HitTarget, FHitResult& OutHit);

private:

	UPROPERTY(EditAnywhere)
	UParticleSystem* MuzzleFlash;

	FTransform SocketTransform;

	UPROPERTY(EditAnywhere)
	class UParticleSystem* ImpactParticles; // particles will be spawned if we get blocking hit

};
