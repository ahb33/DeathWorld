// Fill out your copyright notice in the Description page of Project Settings.


#include "MainMenuWidget.h"
#include "Blueprint/UserWidget.h"
#include "My_PlayerController.h"
#include "MultiplayerMenuWidget.h"
#include "Components/Button.h"
#include "Kismet/GameplayStatics.h"

void UMainMenuWidget::NativeConstruct()
{
    Super::NativeConstruct();

    InitializePlayerController();
    MenuSetup();
}

void UMainMenuWidget::InitializePlayerController()
{
    // Retrieve the PlayerController directly from the owning player
    playerController = Cast<AMy_PlayerController>(GetOwningPlayer());
}

void UMainMenuWidget::MenuSetup()
{
    AddToViewport();
    SetupInputMode();

    BindButtonEvents();
}

void UMainMenuWidget::SetupInputMode()
{
    if (playerController)
    {
        FInputModeUIOnly InputModeData;
        InputModeData.SetWidgetToFocus(TakeWidget());
        InputModeData.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
        
        playerController->SetInputMode(InputModeData);
        playerController->bShowMouseCursor = true;
    }
}

// Ensure that buttons are valid and not already bound to prevent multiple bindings.
void UMainMenuWidget::BindButtonEvents()
{
    if (SoloButton && !SoloButton->OnClicked.IsAlreadyBound(this, &UMainMenuWidget::OnSoloClicked))
    {
        SoloButton->OnClicked.AddDynamic(this, &UMainMenuWidget::OnSoloClicked);
    }

    if (MultiplayerButton && !MultiplayerButton->OnClicked.IsAlreadyBound(this, &UMainMenuWidget::OnMultiplayerClicked))
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
    // Remove the current MainMenu widget from the viewport
    RemoveFromParent();

    // Assuming the multiplayer widget is at index 1 in the MenuWidgetClasses array
    if (menuWidgetClasses.IsValidIndex(1))
    {
        UMultiplayerMenuWidget* MultiplayerMenuWidget = CreateWidget<UMultiplayerMenuWidget>(GetWorld(), menuWidgetClasses[1]);
        
        if (MultiplayerMenuWidget)
        {
            // Initialize and display the multiplayer menu
            MultiplayerMenuWidget->MultiplayerMenuSetup();
        }
    }
    else
    {
        UE_LOG(LogTemp, Warning, TEXT("Invalid index or MultiplayerMenuClass is not set!"));
    }
}


