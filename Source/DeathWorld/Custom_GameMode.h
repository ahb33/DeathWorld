// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameMode.h"
#include "Game_PlayerState.h"
#include "MyPlayerController.h"
#include "MainCharacter.h"
#include "UObject/ConstructorHelpers.h"
#include "Custom_GameMode.generated.h"

/**
 * 
 */
UCLASS()
class DEATHWORLD_API ACustom_GameMode : public AGameMode
{
    // include a reference to the My_GameInstance and My_GameState for managing game-wide state and data.
	GENERATED_BODY()
	
public:
	ACustom_GameMode();
};

/*

USTRUCT(BlueprintType)
struct FDifficultySettings
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Difficulty")
    float EnemyHealthMultiplier;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Difficulty")
    float EnemyDamageMultiplier;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Difficulty")
    float EnemySpawnRate;
};

// Example usage in ASinglePlayerGameMode
void ASinglePlayerGameMode::SetDifficulty(EGameDifficulty NewDifficulty)
{
    Super::SetDifficulty(NewDifficulty);

    switch (NewDifficulty)
    {
        case EGameDifficulty::Easy:
            DifficultySettings = {0.5f, 0.5f, 1.0f}; // Easy settings
            break;
        case EGameDifficulty::Medium:
            DifficultySettings = {1.0f, 1.0f, 1.0f}; // Medium settings
            break;
        case EGameDifficulty::Hard:
            DifficultySettings = {2.0f, 2.0f, 1.0f}; // Hard settings
            break;
    }

    // Apply settings to existing enemies if necessary
}


*/