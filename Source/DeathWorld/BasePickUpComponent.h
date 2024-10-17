#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "BasePickUpComponent.generated.h"

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class DEATHWORLD_API UBasePickUpComponent : public UActorComponent
{
    GENERATED_BODY()

public:    
    UBasePickUpComponent();

    class USphereComponent* GetAreaSphere() const {return areaSphere;}

protected:
    virtual void BeginPlay() override;

    UFUNCTION()
    void OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

    UFUNCTION()
    void OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void OnPickUp(class ABaseCharacter* OverlappingPlayer);

private:
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
    class USphereComponent* areaSphere; // Encapsulated sphere component



};