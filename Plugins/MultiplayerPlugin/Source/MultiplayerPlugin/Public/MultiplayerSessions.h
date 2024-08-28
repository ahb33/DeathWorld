// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "Interfaces/OnlineSessionInterface.h"
#include "MultiplayerSessions.generated.h"

/**
 * 
 */
UCLASS()
class MULTIPLAYERPLUGIN_API UMultiplayerSessions : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	// constructor
	UMultiplayerSessions();

	/*
	
		There are 4 main operations we can use to handle a session

		Create Session : This is the starting point of the session process; 
		once session is created it becomes discoverable by other instances of the game

		Find Session : In this function you'll retreive a list of currently created and accessible
		game sessions


		Join Session : After finding a session the last step is to join the game-
		this function can be used to transition to the server's map

		Destroy Session : If you are hosting a session this function will 
		close it so thats its no longer available for dicovery and joining. It will
		disconnect any both client and host from the game
		
	*/

	// menu class in other games will call these- you can create pointer to MultiplayerSessions
	// Create session
	void CreateSession(int32 NumOfConnections, FString GameType); 
	// Find session
	void FindSessions(int32 MaxSearchResults);
	// Join session
	void JoinSession(const FOnlineSessionSearchResult& SessionResult);
	// Start session
	void StartSession();
	// Destroy session
	void DestroySession();


protected: 

	void OnCreateSessionComplete(FName SessionName, bool bWasSuccessful);

	void OnFindSessionComplete(bool bWasSuccessful);

	void OnJoinSessionComplete(FName SessionName, EOnJoinSessionCompleteResult::Type Result);

	void OnDestroySessionComplete(FName SessionName, bool bWasSuccessful);

	void OnStartSessionComplete(FName SessionName, bool bWasSuccessful);


private:

	
	// Online sybstystem session interface
	IOnlineSessionPtr sessionInterface;

	/**
		* Delegate fired when a session create request has completed
		*
		* @param SessionName the name of the session this callback is for
		* @param bWasSuccessful true if the async action completed without error, false if there was an error
 	*/
	FOnCreateSessionCompleteDelegate CreateSessionCompleteDelegate;
	FDelegateHandle CreateSessionCompleteDelegateHandle;

	FOnFindSessionsCompleteDelegate FindSessionsCompleteDelegate;
	FDelegateHandle FindSessionsCompleteDelegateHandle;

	FOnJoinSessionCompleteDelegate JoinSessionCompleteDelegate;
	FDelegateHandle JoinSessionCompleteDelegateHandle;

	FOnDestroySessionCompleteDelegate DestroySessionCompleteDelegate;
	FDelegateHandle DestroySessionCompleteDelegateHandle;

	FOnStartSessionCompleteDelegate StartSessionCompleteDelegate;
	FDelegateHandle StartSessionCompleteDelegateHandle;
	
};
