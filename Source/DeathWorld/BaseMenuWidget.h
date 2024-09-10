// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "My_PlayerController.h"
#include "BaseMenuWidget.generated.h"

/**
 * 
 */
UCLASS()
class DEATHWORLD_API UBaseMenuWidget : public UUserWidget
{
	GENERATED_BODY()

protected:
    virtual void NativeConstruct() override;

    // Create and store the widget
    void CreateAndStoreWidget(FName MenuName, TSubclassOf<UUserWidget> WidgetClass);

    class AMy_PlayerController* playerController;

public:
    virtual void TransitionToMenu(FName MenuName);
    virtual void MenuSetup();

    void SetupInputMode();

protected: 
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Widgets")
    TMap<FName, UUserWidget*> menuWidgetMap;  // A map that stores widget instances

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Widgets")
    TSubclassOf<UUserWidget> mainMenuWidgetClass;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Widgets")
    TSubclassOf<UUserWidget> multiplayerMenuWidgetClass;

};
