
#include "MainMenuWidget.h"
#include "Blueprint/UserWidget.h"
#include "My_PlayerController.h"
#include "MultiplayerMenuWidget.h"
#include "Kismet/GameplayStatics.h"

void UMainMenuWidget::NativeConstruct()
{
    Super::NativeConstruct();
    // Only create the widget instance if it's not already in the array

    UE_LOG(LogTemp, Warning, TEXT("MainMenu native construct called"));

    MenuSetup();
}


void UMainMenuWidget::MenuSetup()
{
    Super::MenuSetup();
    
    BindButtonEvents();
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
    UE_LOG(LogTemp, Warning, TEXT("MultiplayerClicked"));
    // Ensure widget creation before attempting transition
    FName MultiplayerMenu = "MultiplayerMenu";

    auto multiplayerMenuWidgetRef = GetMultiplayerMenuWidgetClass();

    if (!menuWidgetMap.Contains(MultiplayerMenu))
    {
        UE_LOG(LogTemp, Log, TEXT("Creating MultiplayerMenu widget."));
        Super::CreateAndStoreWidget(MultiplayerMenu, multiplayerMenuWidgetRef);
    }

    TransitionToMenu(MultiplayerMenu);
}



