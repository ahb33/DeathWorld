// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameState.h"
#include "My_GameState.generated.h"

/**
	
	Holds game-wide data that persists across different levels or modes (e.g., player profiles, session settings, global settings).
	Can be used to manage transitions between game modes and levels, including saving and loading data.
	Interfaces with Custom_GameMode to initialize the appropriate game mode and pass relevant game-wide data.
 */
UCLASS()
class DEATHWORLD_API AMy_GameState : public AGameState
{
	GENERATED_BODY()
	
};
