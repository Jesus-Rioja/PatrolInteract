#pragma once

#include "CoreMinimal.h"
#include "Actors/SmartObjects/SmartObjectBase.h"
#include "SplineSmartObject.generated.h"

class USplineComponent;


UCLASS()
class PATROLINTERACT_API ASplineSmartObject : public ASmartObjectBase
{
	GENERATED_BODY()
	
public:

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Patrol AI")
	USplineComponent* SplineComponent = nullptr;

	ASplineSmartObject();

	void FillSplinePoints();
	const TArray<FVector>& GetSplinePoints() const;

protected:
	virtual void BeginPlay() override;

private:

	UPROPERTY()
	TArray<FVector> SplinePoints;

};
