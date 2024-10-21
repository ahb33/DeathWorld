// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "MyPlayerController.h"
#include "My_GameInstance.generated.h"


/**
A GameInstance in Unreal Engine is a persistent class that exists for the entire duration of the game, 
remaining constant even when switching levels. 
Unlike GameMode or PlayerController, which can reset between levels, 
GameInstance is ideal for storing game-wide data such as player stats, settings, 
or references like PlayerController that need to be accessed across multiple levels or widgets.
 */
UCLASS()
class DEATHWORLD_API UMy_GameInstance : public UGameInstance
{
	GENERATED_BODY()

public:

    
	AMyPlayerController* GetPlayerController() const { return playerController; }
    void SetPlayerController(AMyPlayerController* Controller) { playerController = Controller; }


protected:


private:
    UPROPERTY()
    AMyPlayerController* playerController;	


};
