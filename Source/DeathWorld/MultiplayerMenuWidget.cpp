// Fill out your copyright notice in the Description page of Project Settings.


#include "MultiplayerMenuWidget.h"
#include "MultiplayerSessions.h"
#include "Components/Button.h"
#include "My_GameInstance.h"


void UMultiplayerMenuWidget::NativeConstruct()
{
    Super::NativeConstruct();

    MultiplayerMenuSetup();

    // access subsytem through game instance -
    UGameInstance* GameInstance = GetGameInstance();
    
    if(GameInstance)
    {
        GameInstance->GetSubsystem<UMultiplayerSessions>();
    }
}


void UMultiplayerMenuWidget::BindButtonEvents()
{
    // Check if HostButton is vaid and not already bound and then bind it to OnHostClicked
    if (HostButton && !HostButton->OnClicked.IsAlreadyBound(this, &UMultiplayerMenuWidget::OnHostClicked))
    {
        HostButton->OnClicked.AddDynamic(this, &UMultiplayerMenuWidget::OnHostClicked);
    }

    // Check if MultiplayerButton is vaid and not already bound and then bind it to OnMultiplayerClicked
    if (JoinButton && !JoinButton->OnClicked.IsAlreadyBound(this, &UMultiplayerMenuWidget::OnMultiplayerClicked))
    {
        JoinButton->OnClicked.AddDynamic(this, &UMultiplayerMenuWidget::OnMultiplayerClicked);
    }
}

void UMultiplayerMenuWidget::MultiplayerMenuSetup()
{
    AddToViewport();

}

void UMultiplayerMenuWidget::OnHostClicked()
{

}

void UMultiplayerMenuWidget::OnHostClicked()
{
    // clicking host should create a session
}

void UMultiplayerMenuWidget::OnJoinClicked()
{

}

void UMultiplayerMenuWidget::OnBackClicked()
{
    
}
