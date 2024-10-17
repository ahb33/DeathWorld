// Fill out your copyright notice in the Description page of Project Settings.


#include "Custom_GameMode.h"
#include "My_GameState.h"


ACustom_GameMode::ACustom_GameMode()
{
    GameStateClass = AMy_GameState::StaticClass();
    PlayerStateClass = AGame_PlayerState::StaticClass();
    PlayerControllerClass = AMyPlayerController::StaticClass();

<<<<<<< HEAD
    static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/GameContent/MainCharacter/Blueprints/BP_MainCharacter"));
=======
    static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/Blueprints/BP_MainCharacter"));
>>>>>>> 0bcdb22c66cd4a7c278cb80e5b52113ddf83a582
    

    if(PlayerPawnBPClass.Class != nullptr)
    {
        DefaultPawnClass = PlayerPawnBPClass.Class;
    }
}
