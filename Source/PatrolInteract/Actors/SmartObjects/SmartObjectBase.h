#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SmartObjectBase.generated.h"

class UArrowComponent;
class UBillboardComponent;
class UBehaviorTree;

UCLASS()
class PATROLINTERACT_API ASmartObjectBase : public AActor
{
	GENERATED_BODY()
	
public:

	ASmartObjectBase();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UBillboardComponent* BillboardComponent = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UArrowComponent* ArrowComponent = nullptr;

	/*UPROPERTY(EditAnywhere, BlueprintReadWrite)
		II_InteractableObject* InteractiveActor = nullptr;*/

	UBehaviorTree* GetBehaviourTree() const;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = AI)
		UBehaviorTree* BehaviourTree;


};
