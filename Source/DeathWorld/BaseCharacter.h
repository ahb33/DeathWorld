#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "UObject/ConstructorHelpers.h"
#include "BaseCharacter.generated.h"



UCLASS()
class DEATHWORLD_API ABaseCharacter : public ACharacter
{
    GENERATED_BODY()

public:
    // Sets default values for this character's properties
    ABaseCharacter();

<<<<<<< HEAD
    /*
	Allow actors to initialize themselves on the C++ side after all of their components have been initialized, 
	only called during gameplay */
    virtual void PostInitializeComponents() override; 

=======
>>>>>>> 0bcdb22c66cd4a7c278cb80e5b52113ddf83a582
    // Called every frame
    virtual void Tick(float DeltaTime) override;

    // Called to bind functionality to input
    virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

<<<<<<< HEAD
=======
    // main character can only call this function by pressing equip button which the AI wont need
    UFUNCTION(BlueprintCallable, Category = "Weapon")
    virtual void EquipWeapon(class ABaseWeapon* WeaponToEquip);

>>>>>>> 0bcdb22c66cd4a7c278cb80e5b52113ddf83a582
    bool isInteracting();

    bool IsCrouched();

<<<<<<< HEAD
    bool IsAiming();

    bool IsWeaponEquipped();

=======
>>>>>>> 0bcdb22c66cd4a7c278cb80e5b52113ddf83a582
    void SetOverlappingWeapon(TWeakObjectPtr<class ABaseWeapon> Weapon);

    // Getter function for overlappingWeapon
    TWeakObjectPtr<class ABaseWeapon> GetOverlappingWeapon() const {return overlappingWeapon;}

    TWeakObjectPtr<class ABaseWeapon> GetCurrentWeapon() const { return myWeapon; }

<<<<<<< HEAD
    void SetCurrentWeapon(TWeakObjectPtr<ABaseWeapon> NewWeapon);

    // UFUNCTION()
    // void OnRep_MyWeapon();
=======

>>>>>>> 0bcdb22c66cd4a7c278cb80e5b52113ddf83a582
    UFUNCTION()
	void OnRep_OverlappingWeapon(); // Called when overlappingWeapon is updated

    UFUNCTION()
	void OnRep_CurrentWeapon(); // Called when myWeapon is updated


<<<<<<< HEAD
    /*
        In Unreal Engine, only the player’s owned actors can call Server RPCs. 
        weapons are not typically owned by the player but by the server or BaseCharacter in our instance
        WithValidation: Adds a validation step on the client to check if the function call is legitimate before it's sent to the server, 
        allowing you to implement security or input checks in the _Validate function.
    
    */
    UFUNCTION(Server, Reliable, WithValidation)
	void ServerSetAiming(bool bIsAiming);

    UFUNCTION(Server, Reliable, WithValidation)
    void ServerSetFiring(bool bFire);



=======
>>>>>>> 0bcdb22c66cd4a7c278cb80e5b52113ddf83a582
protected:
    // Called when the game starts or when spawned
    virtual void BeginPlay() override;

    void Move(const struct FInputActionValue& Value);
    void Look(const struct FInputActionValue& Value);
    void Interact(const FInputActionValue& Value);

<<<<<<< HEAD
    // Shared logic for handling the firing state
    virtual void SetFiringState(bool bFire);

=======
>>>>>>> 0bcdb22c66cd4a7c278cb80e5b52113ddf83a582
    UFUNCTION(Server, Reliable)
	void Interact_Server();

    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    
private:

    // Pointer to the overlapping pickup, set by the pickup itself
    TWeakObjectPtr<class ABase_PickUp> overlappingPickup; 

    UPROPERTY(ReplicatedUsing = OnRep_OverlappingWeapon)
    TWeakObjectPtr<class ABaseWeapon> overlappingWeapon;

    UPROPERTY(ReplicatedUsing = OnRep_CurrentWeapon)
    TWeakObjectPtr<class ABaseWeapon> myWeapon;

    // add reference to actor that will be interacted with
	UPROPERTY()
	AActor* InteractableActor;
   
    // TObjectPtr automatically tracks references to UObject instances, 
    // which helps the garbage collector keep track of objects that are still in use.
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
    TObjectPtr<class USpringArmComponent> CameraBoom;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
    TObjectPtr<class UCameraComponent> FollowCamera;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
    TObjectPtr<class UInputMappingContext> DefaultMappingContext;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
    TObjectPtr<class UInputAction> MoveAction;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
    TObjectPtr<class UInputAction> LookAction;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
    TObjectPtr<class UInputAction> InteractAction;

    // Replicated properties
    UPROPERTY(Replicated, EditAnywhere, BlueprintReadOnly, Category = Stats, meta = (AllowPrivateAccess = "true"))
    float Health;

    /*

        consolidate code for speed and accleration 
    */
    
};