// Fill out your copyright notice in the Description page of Project Settings.


#include "HitScanWeapon.h"
#include "Engine/World.h" 
#include "Engine/SkeletalMeshSocket.h" 
#include "Kismet/GameplayStatics.h"

void AHitScanWeapon::Fire(const FVector& HitTarget)
{
    Super::Fire(HitTarget);

    const USkeletalMeshSocket* MuzzleFlashSocket = GetWeaponMesh()->GetSocketByName(FName("MuzzleFlash"));

    if(HasAuthority())
    {
        if (MuzzleFlashSocket && !WeaponIsEmpty())
        {
            UE_LOG(LogTemp, Warning, TEXT("MuzzleFlashSocket is valid and weapon is not empty"));
            SocketTransform = MuzzleFlashSocket->GetSocketTransform(GetWeaponMesh());
            FVector MuzzleLocation = SocketTransform.GetLocation();

            FHitResult CameraHit;
            FVector AdjustedHitTarget = CrossHairTrace(CameraHit);

            FVector Direction = (AdjustedHitTarget - MuzzleLocation).GetSafeNormal();
            FVector End = MuzzleLocation + Direction * Trace_Length;

            FHitResult FireHit;
            WeaponTraceHit(MuzzleLocation, End, FireHit);

            if (ImpactParticles)
            {
                UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), ImpactParticles, FireHit.ImpactPoint, FireHit.ImpactNormal.Rotation());
            }

            // UAISense_Hearing::ReportNoiseEvent(this, MuzzleLocation, 1.0f, InstigatorPawn, 2000.0f, TEXT("WeaponFire"));
            UE_LOG(LogTemp, Warning, TEXT("Noise event reported at location %s"), *MuzzleLocation.ToString());
            
            DrawDebugLine(GetWorld(), MuzzleLocation, End, FColor::Red, false, 1.0f, 0, 1.0f);
            DrawDebugPoint(GetWorld(), FireHit.ImpactPoint, 10, FColor::Green, false, 1.0f);

            UE_LOG(LogTemp, Warning, TEXT("Firing weapon at %s"), *AdjustedHitTarget.ToString());
        }
        else
        {
            UE_LOG(LogTemp, Warning, TEXT("Failed to fire weapon: MuzzleFlashSocket invalid or weapon is empty"));
        }
    }


}

void AHitScanWeapon::WeaponTraceHit(const FVector& TraceStart, const FVector& TraceEnd, FHitResult& FireHit)
{
    UWorld* World = GetWorld();
    if (World)
    {
        World->LineTraceSingleByChannel(FireHit, TraceStart, TraceEnd, ECollisionChannel::ECC_Visibility);

        if (FireHit.bBlockingHit)
        {
            // AEnemyCharacter* HitEnemy = Cast<AEnemyCharacter>(FireHit.GetActor());
            // if (HitEnemy)
            // {
            //     HitEnemy->EnemyDamage(GetDamage());
            // }
        }

        DrawDebugPoint(GetWorld(), FireHit.ImpactPoint, 10, FColor::Green, false, 1.0f);
    }
}

