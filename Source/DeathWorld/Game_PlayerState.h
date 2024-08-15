// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "Game_PlayerState.generated.h"

/**
 * 
 * 
 * 
 	Manages player-specific data, like health, score, and other player-related statistics.
	Should be able to interact with Custom_GameMode to retrieve or update player-specific information relevant to the current game mode.
	Might include logic for syncing player state across different game modes.
	It exists on both server and clients to ensure that all players have access to the same information
 */
UCLASS()
class DEATHWORLD_API AGame_PlayerState : public APlayerState
{
	GENERATED_BODY()
	
};
