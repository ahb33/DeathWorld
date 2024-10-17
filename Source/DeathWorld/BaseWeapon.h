// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "WeaponTypes.h"
<<<<<<< HEAD
#include "Kismet/GameplayStatics.h"
#include "MyHUD.h"
#include "WeaponState.h"
#include "BaseWeapon.generated.h"

#define Trace_Length 10000.f


=======
#include "BaseWeapon.generated.h"

>>>>>>> 0bcdb22c66cd4a7c278cb80e5b52113ddf83a582
UCLASS()
class DEATHWORLD_API ABaseWeapon : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABaseWeapon();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

<<<<<<< HEAD
	/* Returns the properties used for network replication, 
	this needs to be overridden by all actor classes with native replicated properties*/ 
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

	void SetFiringState(bool bFire); // declaring this function as virtual so that child classes can override it

	/*
		this will be a virtual function child classes can override	
	*/
	virtual void Fire(const FVector& Hit);

	FVector CrossHairTrace(FHitResult& TraceHitResult); /*Structure containing information about one hit of a trace
	such as point of impact and surface normal at that point.*/ 


=======
	/*Returns the properties used for network replication, 
	this needs to be overridden by all actor classes with native replicated properties*/ 
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

>>>>>>> 0bcdb22c66cd4a7c278cb80e5b52113ddf83a582

	/*
		this will be parent class of 2 types of weapon: hitscan and projectile weapons
		all common functionality like equipping, swapping, and firing should be handled here
	
	
	*/

	void EquipWeapon(TWeakObjectPtr<class ABaseWeapon> currentWeapon); /* this function take a pointer reference to the
	Weapon class and will be responsible for equipping the weapon */


	void EquipPrimaryWeapon(TWeakObjectPtr<class ABaseWeapon> FirstWeapon); /* this function take a pointer reference to the
	Weapon class and will be responsible for equipping the primary weapon */

	void EquipSecondaryWeapon(TWeakObjectPtr<class ABaseWeapon> SecondWeapon); /* this function take a pointer reference to the
	Weapon class and will be responsible for equipping the secondary weapon */

	// void SetCharacter(TWeakObjectPtr<class ABaseCharacter> NewCharacter) { baseCharacter = NewCharacter;}
	
	UFUNCTION()
	void OnRep_EquippedWeapon();

	UFUNCTION()	
	void OnRep_SecondaryWeapon();

	virtual void OnRep_Owner();

	void SwapWeapons();

<<<<<<< HEAD

	void AttachWeaponToWeaponSocket(AActor* WeaponToAttach);

	void AttachActorToSocketByName(AActor* WeaponToAttach, FName SocketName);

=======
	void AttachActorToRightHand(AActor* ActorToAttach);

	void AttachWeaponToWeaponSocket(AActor* WeaponToAttach);

	void AttachActorToSocket(AActor* ActorToAttach, AActor* TargetActor);	

	void AttachActorToSocketByName(AActor* WeaponToAttach, FName SocketName);

	void HandleAttachToSocket();

>>>>>>> 0bcdb22c66cd4a7c278cb80e5b52113ddf83a582
	FName DetermineSocketNameBasedOnWeaponType() const;

	// FVector CrossHairTrace(FHitResult& TraceHitResult); /*Structure containing information about one hit of a trace
	// such as point of impact and surface normal at that point.*/ 

	/*Set Cross hair based on weapon we are using; crosshairs will be dynamic - they will be changing
	based on character's velocity and firing which will involve interpolation so pass DeltaTime 
	function will also be virtual so each child class sets its own crosshair*/
	virtual void SetHUDCrosshairs(float DeltaTime);

	void SetAiming(bool bIsAiming);

<<<<<<< HEAD
    bool IsAiming() const { return bAiming;} 


	EWeaponType GetWeaponType() const {return WeaponType;}

	void SetWeaponState(EWeaponState State);

	UFUNCTION()
	void OnRep_WeaponState(); // This function will run on clients when WeaponState changes

	void HandleWeaponState();

	void PrimaryEquippedState();
	
	void SecondaryEquippedState();

	void ConfigureDroppedState();

	void SetBaseCharacter(class ABaseCharacter* NewCharacter) { baseCharacter = NewCharacter; }	

	class ABaseCharacter* GetBaseCharacter() const {return baseCharacter; }

    ABaseWeapon* GetEquippedWeapon() const { return equippedWeapon.Get(); }

	// Useful for accessing the actual mesh of the weapon itself
	FORCEINLINE USkeletalMeshComponent* GetWeaponMesh() const {return weaponMesh;}


	// function will return true if weapon is empty and will not fire
	bool WeaponIsEmpty() const;


=======
	UFUNCTION(Server, Reliable)
	void ServerSetAiming(bool bIsAiming);

	EWeaponType GetWeaponType() const {return WeaponType;}

	// TWeakObjectPtr<class ABaseCharacter> GetBaseCharacter();
>>>>>>> 0bcdb22c66cd4a7c278cb80e5b52113ddf83a582

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	
	UFUNCTION()
	virtual void OnSphereOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	
	// you only want overlap events to happen on the server
	UFUNCTION()
	virtual void OnSphereEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

<<<<<<< HEAD
private:

	UPROPERTY(ReplicatedUsing = OnRep_EquippedWeapon)
    TWeakObjectPtr<class ABaseWeapon> equippedWeapon; // need a getter for this 
=======

private:

	UPROPERTY(ReplicatedUsing = OnRep_EquippedWeapon)
    TWeakObjectPtr<class ABaseWeapon> equippedWeapon;
>>>>>>> 0bcdb22c66cd4a7c278cb80e5b52113ddf83a582
	
	UPROPERTY(ReplicatedUsing = OnRep_EquippedWeapon)
	TWeakObjectPtr<class ABaseWeapon> primaryWeapon; // variable that will store primary weapon

	UPROPERTY(ReplicatedUsing = OnRep_SecondaryWeapon)
	TWeakObjectPtr<class ABaseWeapon> secondaryWeapon; // variable that will store secondary weapon

<<<<<<< HEAD
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Testing", meta = (AllowPrivateAccess = "true"))	
	TObjectPtr<class USkeletalMeshComponent> weaponMesh;

=======
>>>>>>> 0bcdb22c66cd4a7c278cb80e5b52113ddf83a582
	UPROPERTY()
	class ABaseCharacter* baseCharacter;

	UPROPERTY()
	class AMyPlayerController* playerController;

	TWeakObjectPtr<class ABaseCharacter> ownerCharacter;

<<<<<<< HEAD
=======
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Testing", meta = (AllowPrivateAccess = "true"))	
	TObjectPtr<class USkeletalMeshComponent> weaponMesh;

>>>>>>> 0bcdb22c66cd4a7c278cb80e5b52113ddf83a582
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
    class UBasePickUpComponent* basePickUpComponent;

	UPROPERTY(VisibleAnywhere, Category = Weapon)
	class UWidgetComponent* pickupWidget;

	UPROPERTY(EditAnywhere, Category = Crosshairs)
	class UTexture2D* CrosshairsCenter;

	UPROPERTY(EditAnywhere, Category = Crosshairs)
	class UTexture2D* CrosshairsLeft;

	UPROPERTY(EditAnywhere, Category = Crosshairs)
	class UTexture2D* CrosshairsRight;

	UPROPERTY(EditAnywhere, Category = Crosshairs)
	class UTexture2D* CrosshairsTop;

	UPROPERTY(EditAnywhere, Category = Crosshairs)
	class UTexture2D* CrosshairsBottom;

	UPROPERTY(VisibleAnywhere)
	FVector LocalHitTarget;

	UPROPERTY(EditAnywhere)
	EWeaponType WeaponType;
<<<<<<< HEAD

	UPROPERTY(VisibleAnywhere, ReplicatedUsing = OnRep_WeaponState)
	EWeaponState WeaponState;

	bool bFireButtonPressed;

	// In BaseWeapon.h
	UPROPERTY(Replicated)
	bool bIsFiring;
		
	UPROPERTY(Replicated)
	bool bAiming = false;

	class AMyHUD* HUD; 

	FHUDPackage HUDPackage;

	UPROPERTY(Replicated)
	float CrosshairVelocityFactor; // this will contribute to crosshair spread based on velocity
	


=======
>>>>>>> 0bcdb22c66cd4a7c278cb80e5b52113ddf83a582
	
	
};
