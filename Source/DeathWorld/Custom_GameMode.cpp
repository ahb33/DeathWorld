// Fill out your copyright notice in the Description page of Project Settings.


#include "Custom_GameMode.h"
#include "My_GameState.h"


ACustom_GameMode::ACustom_GameMode()
{
    GameStateClass = AMy_GameState::StaticClass();
    PlayerStateClass = AGame_PlayerState::StaticClass();
    PlayerControllerClass = AMyPlayerController::StaticClass();

    static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/GameContent/MainCharacter/Blueprints/BP_MainCharacter"));
    

    if(PlayerPawnBPClass.Class != nullptr)
    {
        DefaultPawnClass = PlayerPawnBPClass.Class;
    }
}
