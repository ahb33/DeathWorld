// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MainMenuWidget.h"
#include "MultiplayerMenuWidget.generated.h"

/**
 * 
 */
UCLASS()
class DEATHWORLD_API UMultiplayerMenuWidget : public UUserWidget
{
	GENERATED_BODY()

public:

    virtual void NativeConstruct() override;
    void MultiplayerMenuSetup();
  
    void BindButtonEvents();

    UFUNCTION()
    void OnHostClicked();

    UFUNCTION()
    void OnJoinClicked();

    UFUNCTION()
    void OnBackClicked();
	
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
