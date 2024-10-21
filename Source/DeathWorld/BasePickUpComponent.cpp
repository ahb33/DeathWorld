#include "BasePickUpComponent.h"
#include "Components/SphereComponent.h"
#include "BaseWeapon.h"
#include "BaseCharacter.h"
#include "GameFramework/Actor.h"

UBasePickUpComponent::UBasePickUpComponent()
{
    PrimaryComponentTick.bCanEverTick = false;
    
        
    // Initialize the sphere component
    areaSphere = CreateDefaultSubobject<USphereComponent>(TEXT("areaSphere"));
    areaSphere->SetSphereRadius(100.f);
    areaSphere->SetGenerateOverlapEvents(true);
    areaSphere->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
    areaSphere->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Overlap);
}

void UBasePickUpComponent::BeginPlay()
{
    Super::BeginPlay();

    if (GetOwner() && GetOwner()->GetRootComponent())
    {
        // Use AttachToComponent instead of SetupAttachment
        areaSphere->AttachToComponent(GetOwner()->GetRootComponent(), FAttachmentTransformRules::KeepRelativeTransform);
    }
    if (areaSphere)
    {
        areaSphere->OnComponentBeginOverlap.AddDynamic(this, &UBasePickUpComponent::OnOverlapBegin);
        areaSphere->OnComponentEndOverlap.AddDynamic(this, &UBasePickUpComponent::OnOverlapEnd);
    }
}

void UBasePickUpComponent::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
    if (const auto Character = Cast<ABaseCharacter>(OtherActor))
    {
        if (const auto Weapon = Cast<ABaseWeapon>(GetOwner()))
        {
            if (Character->HasAuthority()) // Ensure server authority
            {
                Character->SetOverlappingWeapon(Weapon);
                Character->SetCurrentWeapon(Weapon);
                Weapon->SetBaseCharacter(Character);
                UE_LOG(LogTemp, Warning, TEXT("OnOverlapBegin: Weapon Set to %s"), *Weapon->GetName());
            }
        }
    }
}

void UBasePickUpComponent::OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
    if (const auto Character = Cast<ABaseCharacter>(OtherActor))
    {
        if (const auto Weapon = Cast<ABaseWeapon>(GetOwner()))
        {
            if (Character->HasAuthority()) // Ensure server authority
            {
                Character->SetOverlappingWeapon(nullptr);
                // Character->SetCurrentWeapon(nullptr);

                UE_LOG(LogTemp, Warning, TEXT("OnOverlapEnd: Weapon Cleared"));
            }
        }
    }
}



void UBasePickUpComponent::OnPickUp_Implementation(ABaseCharacter* OverlappingPlayer)
{
	//OverlappingPlayer->AddToInventory(this); // for future reference: this will be added later on

	    // Check if the OverlappingPlayer is valid
    if (OverlappingPlayer)
    {
        UE_LOG(LogTemp, Warning, TEXT("Player is overlapping base pick up component"));
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