// Fill out your copyright notice in the Description page of Project Settings.


#include "MultiplayerMenuWidget.h"
#include "MultiplayerSessions.h"
#include "My_GameInstance.h"


void UMultiplayerMenuWidget::NativeConstruct()
{
    Super::NativeConstruct();
    
    MenuSetup();
}

void UMultiplayerMenuWidget::MenuSetup()
{
    Super::MenuSetup();
    BindButtonEvents(); 
}


void UMultiplayerMenuWidget::BindButtonEvents()
{
    // Check if HostButton is valid and not already bound and then bind it to OnHostClicked
    if (HostButton && !HostButton->OnClicked.IsAlreadyBound(this, &UMultiplayerMenuWidget::OnHostButtonClicked))
    {
        HostButton->OnClicked.AddDynamic(this, &UMultiplayerMenuWidget::OnHostButtonClicked);
    }

    // Check if MultiplayerButton is valid and not already bound and then bind it to OnMultiplayerClicked
    if (JoinButton && !JoinButton->OnClicked.IsAlreadyBound(this, &UMultiplayerMenuWidget::OnJoinButtonClicked))
    {
        JoinButton->OnClicked.AddDynamic(this, &UMultiplayerMenuWidget::OnJoinButtonClicked);
    }

    // Check if BackButton is valid and not already bound and then bind it to OnMultiplayerClicked
    if(BackButton && !BackButton->OnClicked.IsAlreadyBound(this, &UMultiplayerMenuWidget::OnBackButtonClicked))
    {
        BackButton->OnClicked.AddDynamic(this, &UMultiplayerMenuWidget::OnBackButtonClicked);
    }

}



void UMultiplayerMenuWidget::OnHostButtonClicked()
{
    // clicking host should create a session
    if(multiplayerSessionPtr)
    {
        multiplayerSessionPtr->CreateSession(4, FString("FreeForAll"));
    }
}

void UMultiplayerMenuWidget::OnJoinButtonClicked()
{

}

void UMultiplayerMenuWidget::OnBackButtonClicked()
{
    UE_LOG(LogTemp, Warning, TEXT("MainMenuClicked"));
    // Ensure widget creation before attempting transition

    FName MainMenu = "MainMenu";

    auto mainMenuWidgetRef = GetMainMenuWidgetClass();

    if (!menuWidgetMap.Contains(MainMenu))
    {
        UE_LOG(LogTemp, Log, TEXT("Creating MultiplayerMenu widget."));
        Super::CreateAndStoreWidget(MainMenu, mainMenuWidgetRef);
    }

    TransitionToMenu(MainMenu);
}

 
