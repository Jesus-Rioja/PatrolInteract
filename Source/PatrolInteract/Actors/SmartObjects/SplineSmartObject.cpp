// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/SmartObjects/SplineSmartObject.h"
#include "Components/SplineComponent.h"

ASplineSmartObject::ASplineSmartObject() : Super()
{
	SplineComponent = CreateDefaultSubobject<USplineComponent>(TEXT("SplineComponent"));
	SplineComponent->SetupAttachment(RootComponent);

	#if WITH_EDITOR
	SplineComponent->bDrawDebug = true;
	#endif

}

void ASplineSmartObject::FillSplinePoints()
{
	for (int32 i = 0; i <= SplineComponent->GetNumberOfSplinePoints(); ++i)
	{
		SplinePoints.Add(SplineComponent->GetLocationAtSplinePoint(i, ESplineCoordinateSpace::World));
	}
}

const TArray<FVector>& ASplineSmartObject::GetSplinePoints() const
{
	return SplinePoints;
}

void ASplineSmartObject::BeginPlay()
{
	Super::BeginPlay();

	FillSplinePoints();
}
