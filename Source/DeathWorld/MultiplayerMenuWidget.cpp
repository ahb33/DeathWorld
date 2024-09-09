// Fill out your copyright notice in the Description page of Project Settings.


#include "MultiplayerMenuWidget.h"
#include "MultiplayerSessions.h"
#include "Components/Button.h"
#include "My_GameInstance.h"


void UMultiplayerMenuWidget::NativeConstruct()
{
    Super::NativeConstruct();
    
    if (multiplayerMenuWidgetClass)
    {
        Super::CreateAndStoreWidget("MultiplayerMenu", multiplayerMenuWidgetClass);
        UE_LOG(LogTemp, Log, TEXT("MultiplayerMenu widget created and stored."));
    }
    else
    {
        UE_LOG(LogTemp, Error, TEXT("multiplayerMenuWidgetClass is not set."));
    }
    // Only bind multiplayer menu buttons
    if (HostButton)
    {
        HostButton->OnClicked.AddDynamic(this, &UMultiplayerMenuWidget::OnHostClicked);
    }

    if (JoinButton)
    {
        JoinButton->OnClicked.AddDynamic(this, &UMultiplayerMenuWidget::OnJoinClicked);
    }

    if (BackButton)
    {
        BackButton->OnClicked.AddDynamic(this, &UMultiplayerMenuWidget::OnBackClicked);
    }
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

    RemoveFromParent();
    // Ensure widget creation before attempting transition
    FName MainMenu = "MainMenu";

    if (!menuWidgetMap.Contains(MainMenu))
    {
        UE_LOG(LogTemp, Log, TEXT("Creating MainMenu widget."));
        Super::CreateAndStoreWidget(MainMenu, mainMenuWidgetClass);
    }
    
    TransitionToMenu(MainMenu);

    
    // Ensure input is correctly focused on the Main Menu
    if (playerController)
    {
        FInputModeUIOnly InputModeData;
        InputModeData.SetWidgetToFocus(menuWidgetMap[MainMenu]->TakeWidget());
        InputModeData.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);

        playerController->SetInputMode(InputModeData);
        playerController->bShowMouseCursor = true;
    }
}

 
