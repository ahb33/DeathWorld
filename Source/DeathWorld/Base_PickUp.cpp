// Fill out your copyright notice in the Description page of Project Settings.


#include "Base_PickUp.h"
#include "Components/SphereComponent.h"
#include "MainCharacter.h"


// Sets default values
ABase_PickUp::ABase_PickUp()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	bReplicates = true;

	/*
		Construct Sphere Collision
		Make it the root copnent
		Set properties of Sphere collision
		Construct pickup mesh
		Attach pick up mesh to sphere collision
		Set properties of Pickup Mesh
	
	*/
	AreaSphere = CreateDefaultSubobject<USphereComponent>("SphereCollision");
	RootComponent = AreaSphere;
	AreaSphere->SetGenerateOverlapEvents(true);
	AreaSphere->SetSphereRadius(100.f);
}

// Called when the game starts or when spawned
void ABase_PickUp::BeginPlay()
{
	Super::BeginPlay();

	AreaSphere->OnComponentBeginOverlap.AddDynamic(this, &ABase_PickUp::OnOverlapBegin);
	
}

void ABase_PickUp::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, 
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, 
	const FHitResult & SweepResult)
{
	// cast overlapping "Other Actor" to MainCharacter and set to const auto variable
	if(const auto Character = Cast<AMainCharacter>(OtherActor))
	{
		OnPickUp(Character);
	}
}

void ABase_PickUp::OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, 
    UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
    // Check if the overlapping actor is a character and execute desired logic
    if (const auto Character = Cast<AMainCharacter>(OtherActor))
    {
        // Logic when the character ends overlap with the pickup
        // Example: remove highlighting, reset state, etc.
    }
}

// Called every frame
void ABase_PickUp::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


//
void ABase_PickUp::OnPickUp_Implementation(AMainCharacter* OverlappingPlayer)
{
	//OverlappingPlayer->AddToInventory(this); // for future reference: this will be added later on

	    // Check if the OverlappingPlayer is valid
    if (OverlappingPlayer)
    {
        // // 1. Set the owner of the item to the OverlappingPlayer
        // SetOwner(OverlappingPlayer);

        // // 3. Play a pickup sound effect
        // // if (PickUpSound)
        // // {
        // //     UGameplayStatics::PlaySoundAtLocation(this, PickUpSound, GetActorLocation());
        // // }

        // // 5. Remove the item from the world
        // Destroy();
    }


}