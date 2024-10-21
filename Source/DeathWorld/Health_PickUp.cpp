// Fill out your copyright notice in the Description page of Project Settings.


#include "Health_PickUp.h"
#include "Components/SphereComponent.h"
#include "Components/StaticMeshComponent.h"

AHealth_PickUp::AHealth_PickUp()
{
    PickUpMesh = CreateDefaultSubobject<UStaticMeshComponent>("PickUpMesh");
    PickUpMesh->SetupAttachment(Cast<USceneComponent>(GetAreaSphere()));    

}

