// Fill out your copyright notice in the Description page of Project Settings.


#include "MainMenuWidget.h"
#include "Blueprint/UserWidget.h"
#include "My_PlayerController.h"
#include "Components/Button.h"
#include "Kismet/GameplayStatics.h"

void UMainMenuWidget::NativeConstruct()
{
    MenuSetup();
}



void UMainMenuWidget::MenuSetup()
{
    AddToViewport();

    playerController = Cast<AMy_PlayerController>(UGameplayStatics::GetPlayerController(this, 0));

    if(playerController)
    {
        FInputModeUIOnly InputModeData;

        // // Ensure the menu is focused and ready for input
        InputModeData.SetWidgetToFocus(TakeWidget());
        InputModeData.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
        playerController->SetInputMode(InputModeData);
        playerController->bShowMouseCursor = false;

    }

    // Bind buttons to their respective functions 
    if (SoloButton)
    {
        SoloButton->OnClicked.AddDynamic(this, &UMainMenuWidget::OnSoloClicked);
    }

    if (MultiplayerButton)
    {
        MultiplayerButton->OnClicked.AddDynamic(this, &UMainMenuWidget::OnMultiplayerClicked);
    }

}

void UMainMenuWidget::OnSoloClicked()
{
    // Transition to the Solo Level with specific GameMode
    UGameplayStatics::OpenLevel(this, FName("SoloLevel"));  
}

void UMainMenuWidget::OnMultiplayerClicked()
{
    UGameplayStatics::OpenLevel(this, FName("MultiPlayerLevel"));  
}


