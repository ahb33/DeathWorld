// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MainMenuWidget.h"
#include "MultiplayerMenuWidget.generated.h"

/**
 * 
 */



UCLASS()
class DEATHWORLD_API UMultiplayerMenuWidget : public UMainMenuWidget
{
	GENERATED_BODY()

public:


    virtual void NativeConstruct() override;

    virtual void MenuSetup();
  
    void BindButtonEvents();

    UFUNCTION()
    void OnHostButtonClicked();

    UFUNCTION()
    void OnJoinButtonClicked();

    UFUNCTION()
    void OnBackButtonClicked();

protected:

	
private:

    // create pointer to OnlinePlugin class to access necessary funtion
    UPROPERTY(meta = (BindWidget))
    class UButton* HostButton;

    UPROPERTY(meta = (BindWidget))
    class UButton* JoinButton;

    UPROPERTY(meta = (BindWidget))
    class UButton* BackButton;

    class UMultiplayerSessions* multiplayerSessionPtr; // pointer to custom mutliplayer plugin class

};
