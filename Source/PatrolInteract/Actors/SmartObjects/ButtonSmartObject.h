#pragma once

#include "CoreMinimal.h"
#include "SmartObjectBase.h"
#include "ButtonSmartObject.generated.h"

class UStaticMeshComponent;
class USphereComponent;
class AInteractiveDoor;	

UCLASS()
class PATROLINTERACT_API AButtonSmartObject : public ASmartObjectBase
{
	GENERATED_BODY()

public:

	AButtonSmartObject();

	UPROPERTY(EditAnywhere)
		UStaticMeshComponent* StaticMeshComponent = nullptr;
	UPROPERTY(EditAnywhere)
		UStaticMeshComponent* ActionPoint = nullptr;
	UPROPERTY(EditAnywhere)
		USphereComponent* SphereComponent = nullptr;

	UPROPERTY(EditAnywhere)
		AInteractiveDoor* InteractiveDoor = nullptr;

protected:
	
	bool Activated = false;

	virtual void BeginPlay() override;

private:

	UFUNCTION()
		void OnComponentBeginOverlap(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	
};
