// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/InteractiveDoor.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
AInteractiveDoor::AInteractiveDoor()
{
	StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMeshComponent->SetCollisionProfileName(TEXT("NoCollision"));
	StaticMeshComponent->SetupAttachment(RootComponent);

}






