// Fill out your copyright notice in the Description page of Project Settings.

#include "MultiplayerSessions.h"
#include "OnlineSubsystem.h"

UMultiplayerSessions::UMultiplayerSessions() : CreateSessionCompleteDelegate(FOnCreateSessionCompleteDelegate::CreateUObject(this, &ThisClass::OnCreateSessionComplete)),
	FindSessionsCompleteDelegate(FOnFindSessionsCompleteDelegate::CreateUObject(this, &ThisClass::OnFindSessionComplete)),
	JoinSessionCompleteDelegate(FOnJoinSessionCompleteDelegate::CreateUObject(this, &ThisClass::OnJoinSessionComplete)),
	DestroySessionCompleteDelegate(FOnDestroySessionCompleteDelegate::CreateUObject(this, &ThisClass::OnDestroySessionComplete)),
	StartSessionCompleteDelegate(FOnStartSessionCompleteDelegate::CreateUObject(this, &ThisClass::OnStartSessionComplete))
{
    // get online subsystem and store in variable
    // check if subsystem variable is valid
    // get session interface from subsystem variable and store in another variable

    IOnlineSubsystem* Subsystem = IOnlineSubsystem::Get(); // Get() retreives Get the online subsystem for a given service

    if (Subsystem)
    {
        sessionInterface = Subsystem->GetSessionInterface();

        if (sessionInterface)
        {
            // Perform additional setup if necessary
        }
        else
        {
            UE_LOG(LogTemp, Warning, TEXT("Session Interface is not valid."));
        }
    }
    else
    {
        UE_LOG(LogTemp, Warning, TEXT("Online Subsystem is not valid."));
    }

}

void UMultiplayerSessions::OnCreateSessionComplete(FName SessionName, bool bWasSuccessful)
{
    UE_LOG(LogTemp, Warning, TEXT("Create session called"));

}

void UMultiplayerSessions::OnFindSessionComplete(bool bWasSuccessful)
{
}

void UMultiplayerSessions::OnJoinSessionComplete(FName SessionName, EOnJoinSessionCompleteResult::Type Result)
{
    UE_LOG(LogTemp, Warning, TEXT("Testing python "));

}

void UMultiplayerSessions::OnDestroySessionComplete(FName SessionName, bool bWasSuccessful)
{
    
}

void UMultiplayerSessions:: OnStartSessionComplete(FName SessionName, bool bWasSuccessful)
{
    UE_LOG(LogTemp, Warning, TEXT("Testing python script"));

}

void UMultiplayerSessions::CreateSession(int32 NumPublicConnections, FString MatchType)
{
}

void UMultiplayerSessions::FindSessions(int32 MaxSearchResults)
{
}

void UMultiplayerSessions::JoinSession(const FOnlineSessionSearchResult& SessionResult)
{
}

void UMultiplayerSessions::DestroySession()
{
}

void UMultiplayerSessions::StartSession()
{
}


