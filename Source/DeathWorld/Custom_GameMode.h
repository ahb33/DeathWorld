// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameMode.h"
#include "Game_PlayerState.h"
#include "My_PlayerController.h"
#include "MainCharacter.h"
#include "UObject/ConstructorHelpers.h"
#include "Custom_GameMode.generated.h"

/**
 * 
 */
UCLASS()
class DEATHWORLD_API ACustom_GameMode : public AGameMode
{
	GENERATED_BODY()
	
public:
	ACustom_GameMode();
};
