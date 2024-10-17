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

<<<<<<< HEAD
    class USphereComponent* GetAreaSphere() const {return areaSphere;}

=======
>>>>>>> 0bcdb22c66cd4a7c278cb80e5b52113ddf83a582
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