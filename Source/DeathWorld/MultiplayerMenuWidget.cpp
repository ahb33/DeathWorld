// Fill out your copyright notice in the Description page of Project Settings.


#include "MultiplayerMenuWidget.h"
#include "MultiplayerSessions.h"
#include "Components/Button.h"
#include "My_GameInstance.h"


void UMultiplayerMenuWidget::NativeConstruct()
{
    Super::NativeConstruct();
    
    BindButtonEvents();
}

void UMultiplayerMenuWidget::MenuSetup()
{
    Super::MenuSetup();
    BindButtonEvents();

    
}


void UMultiplayerMenuWidget::BindButtonEvents()
{
    // Check if HostButton is valid and not already bound and then bind it to OnHostClicked
    if (HostButton && !HostButton->OnClicked.IsAlreadyBound(this, &UMultiplayerMenuWidget::OnHostClicked))
    {
        HostButton->OnClicked.AddDynamic(this, &UMultiplayerMenuWidget::OnHostClicked);
    }

    // Check if MultiplayerButton is valid and not already bound and then bind it to OnMultiplayerClicked
    if (JoinButton && !JoinButton->OnClicked.IsAlreadyBound(this, &UMultiplayerMenuWidget::OnJoinClicked))
    {
        JoinButton->OnClicked.AddDynamic(this, &UMultiplayerMenuWidget::OnJoinClicked);
    }

    // Check if BackButton is valid and not already bound and then bind it to OnMultiplayerClicked
    if(BackButton && !BackButton->OnClicked.IsAlreadyBound(this, &UMultiplayerMenuWidget::OnBackClicked))
    {
        BackButton->OnClicked.AddDynamic(this, &UMultiplayerMenuWidget::OnBackClicked);
    }

}



void UMultiplayerMenuWidget::OnHostClicked()
{
    // clicking host should create a session
    if(multiplayerSessionPtr)
    {
        multiplayerSessionPtr->CreateSession(4, FString("FreeForAll"));
    }
}

void UMultiplayerMenuWidget::OnJoinClicked()
{

}

void UMultiplayerMenuWidget::OnBackClicked()
{
    FName MainMenu = "MainMenu";

    // Check if MainMenu is already stored in the map
    if (menuWidgetMap.Contains(MainMenu))
    {
        // Transition to the existing instance in the map
        TransitionToMenu(MainMenu);
    }
    else
    {
        // Create the MainMenu widget only if it's not in the map
        UE_LOG(LogTemp, Log, TEXT("Creating MainMenu widget."));
        Super::CreateAndStoreWidget(MainMenu, mainMenuWidgetClass);
        TransitionToMenu(MainMenu);  // Transition after creation
    }
}

 
