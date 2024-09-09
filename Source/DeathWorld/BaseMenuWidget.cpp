// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseMenuWidget.h"

// Fill out your copyright notice in the Description page of Project Settings.



void UBaseMenuWidget::NativeConstruct()
{
    Super::NativeConstruct();


}

// void UBaseMenuWidget::TransitionToMenu(FName MenuName)
// {
//     UE_LOG(LogTemp, Warning, TEXT("TransitionToMenu called"));
    
//     // Store the result of the Find operation in a pointer to reduce redundant code
//     TSubclassOf<UUserWidget>* MenuClass = menuWidgetMap.Find(MenuName);
    
//     // Check if the MenuClass was found
//     if (MenuClass)
//     {
//         UUserWidget* NextMenu = CreateWidget<UUserWidget>(GetWorld(), *MenuClass);
//         if (NextMenu)
//         {
//             NextMenu->AddToViewport();
//             UE_LOG(LogTemp, Warning, TEXT("Successfully transitioned to: %s"), *MenuName.ToString());
//         }
//         else
//         {
//             UE_LOG(LogTemp, Error, TEXT("Failed to create widget for menu: %s"), *MenuName.ToString());
//         }
//     }
//     else
//     {
//         UE_LOG(LogTemp, Error, TEXT("Menu %s not found in map!"), *MenuName.ToString());
//     }
// }

void UBaseMenuWidget::TransitionToMenu(FName MenuName)
{
    UUserWidget** FoundWidget = menuWidgetMap.Find(MenuName);
    if (FoundWidget && *FoundWidget)
    {
        (*FoundWidget)->AddToViewport();
        UE_LOG(LogTemp, Log, TEXT("Transitioned to %s"), *MenuName.ToString());
        return;
    }

    TSubclassOf<UUserWidget> WidgetClass = GetWidgetClassForMenu(MenuName);
    if (!WidgetClass)
    {
        UE_LOG(LogTemp, Error, TEXT("No Widget Class found for %s"), *MenuName.ToString());
        return;
    }

    CreateAndStoreWidget(MenuName, WidgetClass);
    menuWidgetMap[MenuName]->AddToViewport();
    UE_LOG(LogTemp, Log, TEXT("Created and transitioned to %s"), *MenuName.ToString());

    SetupInputMode();  // Ensure input mode is set after transitioning
}

TSubclassOf<UUserWidget> UBaseMenuWidget::GetWidgetClassForMenu(FName MenuName)
{
    if (MenuName == "MainMenu")
    {
        return mainMenuWidgetClass;  // Define this subclass elsewhere
    }
    else if (MenuName == "MultiplayerMenu")
    {
        return multiplayerMenuWidgetClass;  // Define this subclass elsewhere
    }

    // Add more menu checks as needed
    return nullptr;  // If no matching widget class is found
}


void UBaseMenuWidget::CreateAndStoreWidget(FName MenuName, TSubclassOf<UUserWidget> WidgetClass)
{
    if (WidgetClass && !menuWidgetMap.Contains(MenuName))
    {
        UUserWidget* NewWidget = CreateWidget<UUserWidget>(GetWorld(), WidgetClass);
        if (NewWidget)
        {
            menuWidgetMap.Add(MenuName, NewWidget);
            UE_LOG(LogTemp, Log, TEXT("Created and stored widget: %s"), *MenuName.ToString());
        }
    }
}

void UBaseMenuWidget::MenuSetup()
{
    AddToViewport();
}

void UBaseMenuWidget::SetupInputMode()
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

