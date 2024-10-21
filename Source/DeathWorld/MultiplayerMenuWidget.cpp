// Fill out your copyright notice in the Description page of Project Settings.


#include "MultiplayerMenuWidget.h"
#include "Kismet/GameplayStatics.h"
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

    UGameInstance* GameInstance = GetGameInstance();
    if (GameInstance)
    {
        multiplayerSessionPtr = GameInstance->GetSubsystem<UMultiplayerSessions>();
    
    }

    if(multiplayerSessionPtr)
    {
        // For dynamic multicast delegates (AddDynamic and RemoveDynamic):
        multiplayerSessionPtr->MultiplayerOnCreateSessionComplete.RemoveDynamic(this, &ThisClass::OnCreateSession);
        multiplayerSessionPtr->MultiplayerOnCreateSessionComplete.AddDynamic(this, &ThisClass::OnCreateSession);

        // For non-dynamic multicast delegates (AddUObject and Clear):
        multiplayerSessionPtr->MultiplayerOnFindSessionComplete.Clear();  // Clear all bindings
        multiplayerSessionPtr->MultiplayerOnFindSessionComplete.AddUObject(this, &UMultiplayerMenuWidget::OnFindSessions);

        multiplayerSessionPtr->MultiplayerOnJoinSessionComplete.Clear();  // Clear all bindings
        multiplayerSessionPtr->MultiplayerOnJoinSessionComplete.AddUObject(this, &UMultiplayerMenuWidget::OnJoinSession);

        // For dynamic multicast delegates (AddDynamic and RemoveDynamic):
        multiplayerSessionPtr->MultiplayerOnDestroySessionComplete.RemoveDynamic(this, &UMultiplayerMenuWidget::OnDestroySession);
        multiplayerSessionPtr->MultiplayerOnDestroySessionComplete.AddDynamic(this, &UMultiplayerMenuWidget::OnDestroySession);

        multiplayerSessionPtr->MultiplayerOnStartSessionComplete.RemoveDynamic(this, &UMultiplayerMenuWidget::OnStartSession);
        multiplayerSessionPtr->MultiplayerOnStartSessionComplete.AddDynamic(this, &UMultiplayerMenuWidget::OnStartSession);
    }
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
    // clicking host should take you to separate menu to select game mode 
    // Death match
    // battle royale

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

void UMultiplayerMenuWidget::OnCreateSession(bool bWasSuccessful)
{
    if (bWasSuccessful)
    {
        if (GEngine)
        {
            GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TEXT("BWasSuccessful, OnCreateSession being called"));
        }
        UGameplayStatics::OpenLevel(this, FName("SoloLevel"));  // Replace with actual level name
    }
    else
    {
        if (GEngine)
        {
            GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TEXT("BWasSuccessful failed"));
        }
    }
    // travel to lobby
}


void UMultiplayerMenuWidget::OnFindSessions(const TArray<FOnlineSessionSearchResult> &SessionResults, bool bWasSuccessful)
{
}

void UMultiplayerMenuWidget::OnJoinSession(EOnJoinSessionCompleteResult::Type Result)
{
}

void UMultiplayerMenuWidget::OnDestroySession(bool bWasSuccessful)
{
}

void UMultiplayerMenuWidget::OnStartSession(bool bWasSuccessful)
{
}
