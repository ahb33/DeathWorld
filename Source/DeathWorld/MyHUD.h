// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "MyHUD.generated.h"

/**
 * 
 */

USTRUCT(BlueprintType)
struct FHUDPackage
{
	GENERATED_BODY() ; // add generated so reflection system can work with this struct
public:
	class UTexture2D* CrosshairsCenter;
	UTexture2D* CrosshairsLeft;
	UTexture2D* CrosshairsRight;
	UTexture2D* CrosshairsTop;
	UTexture2D* CrosshairsBottom;
	float CrosshairSpread; // this will be changing dynamically in the game
	FLinearColor CrosshairsColor;
};

UCLASS()
class DEATHWORLD_API AMyHUD : public AHUD
{
	GENERATED_BODY()

public:

	virtual void DrawHUD() override;
	FORCEINLINE void SetHUDPackage(const FHUDPackage& Package) {HUDPackage = Package;}

	void DrawCrosshair(UTexture2D* Texture, FVector2D ViewportCenter, FVector2D Spread);

private:
	FHUDPackage HUDPackage;

	UPROPERTY(EditAnywhere)
	float CrosshairSpreadMax = 20.f;

protected:

	virtual void BeginPlay() override;



};
