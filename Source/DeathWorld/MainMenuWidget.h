// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MainMenuWidget.generated.h"

/**
 * 
 */
UCLASS()
class DEATHWORLD_API UMainMenuWidget : public UUserWidget
{
	GENERATED_BODY()
	
protected:
    virtual void NativeConstruct() override;


public:

    UFUNCTION(BlueprintCallable)
    virtual void MenuSetup(); // child classes will have their own implementation of menu setup

    /*
    //  if Solo button clicked transition to 2nd menu with solo related options
        create child class for solo menu later - game mode for solo mode
        would also be handled within child class as well as level transition 

    */
    UFUNCTION()
    void OnSoloClicked(); 

    /*
        if Solo button clicked transition to 2nd menu with solo related options
        create child class for multiplayer menu later   
    */
    UFUNCTION()
    void OnMultiplayerClicked(); 


private:

    UPROPERTY(meta = (BindWidget))
	class UButton* SoloButton;

    UPROPERTY(meta = (BindWidget))
	class UButton* MultiplayerButton;

    class AMy_PlayerController* playerController;

};
