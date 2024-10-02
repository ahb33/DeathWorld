#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "Game_Interactable.generated.h"



/*
the UINTERFACE class is not the actual interface. 
It is an empty class that exists only for visibility to Unreal Engine's reflection system. 
The actual interface that will be inherited by other classes must have the same class name, 
but with the initial "U" changed to an "I".

*/
UINTERFACE(MinimalAPI, Blueprintable)
class UGame_Interactable : public UInterface
{
    GENERATED_BODY()
};

class DEATHWORLD_API IGame_Interactable
{
    GENERATED_BODY()

public:


    /*
        remember Functions using the BlueprintCallable specifier can be called in C++ or Blueprint 
        using a reference to an object that implements the interface.
    
    
    */
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Interaction", meta=(DisplayName= "Interact"))
    bool CanInteract(class ABaseCharacter* CharacterInstigator);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Interaction", meta=(DisplayName= "Interact"))
    void Interact(class ABaseCharacter* CharacterInstigator);



};