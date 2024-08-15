// Fill out your copyright notice in the Description page of Project Settings.


#include "MainCharacter.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"

// Sets default values
AMainCharacter::AMainCharacter()
{
    PrimaryActorTick.bCanEverTick = true;

    // Initialize specific input actions
    SprintAction = nullptr;
    InteractAction = nullptr;

    // static ConstructorHelpers::FObjectFinder<USkeletalMesh> SkeletalMeshAsset(TEXT("/Game/KayKit/Characters/rogue"));
    // if (SkeletalMeshAsset.Succeeded())
    // {
    //     GetMesh()->SetSkeletalMesh(SkeletalMeshAsset.Object);
    //     GetMesh()->SetRelativeLocation(FVector(0.f, 0.f, -91.f));
    // }
}

void AMainCharacter::BeginPlay()
{
    Super::BeginPlay();
}

void AMainCharacter::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}

void AMainCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
    Super::SetupPlayerInputComponent(PlayerInputComponent);

    if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerInputComponent))
    {
        EnhancedInputComponent->BindAction(SprintAction, ETriggerEvent::Triggered, this, &AMainCharacter::SprintStart);
        EnhancedInputComponent->BindAction(SprintAction, ETriggerEvent::Completed, this, &AMainCharacter::SprintEnd);
        EnhancedInputComponent->BindAction(InteractAction, ETriggerEvent::Triggered, this, &AMainCharacter::Interact);
    }
}

void AMainCharacter::SprintStart(const FInputActionValue& Value)
{
    SprintStart_Server();
}

void AMainCharacter::SprintStart_Server_Implementation()
{

    GetCharacterMovement()->MaxWalkSpeed *= speedMultiplier;
}



void AMainCharacter::SprintEnd(const FInputActionValue& Value)
{
    SprintEnd_Server();
}

void AMainCharacter::SprintEnd_Server_Implementation()
{

    GetCharacterMovement()->MaxWalkSpeed *= speedMultiplier;
}



void AMainCharacter::Interact(const FInputActionValue& Value)
{
    // Implement interact logic
}