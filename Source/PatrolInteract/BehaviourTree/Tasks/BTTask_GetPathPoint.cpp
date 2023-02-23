#include "BehaviourTree/Tasks/BTTask_GetPathPoint.h"
#include "AIModule/Classes/AIController.h"
#include "AIModule/Classes/BehaviorTree/Blackboard/BlackboardKeyType_Vector.h"
#include "AIModule/Classes/BehaviorTree/BlackboardComponent.h"
#include "Characters/Patrol/ACharacterPatrol.h"
#include "Actors/SmartObjects/SplineSmartObject.h"

UBTTask_GetPathPoint::UBTTask_GetPathPoint(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	NodeName = "Get Path Point";
	bCreateNodeInstance = true;
}

EBTNodeResult::Type UBTTask_GetPathPoint::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	UBlackboardComponent* OwnerBlackboard = OwnerComp.GetBlackboardComponent();
	AAIController* OwnerController = OwnerComp.GetAIOwner();
	if (!OwnerBlackboard || !OwnerController)
	{
		return EBTNodeResult::Failed;
	}

	AACharacterPatrol* PatrolCharacter = Cast<AACharacterPatrol>(OwnerController->GetPawn());
	if (!PatrolCharacter)
	{
		return EBTNodeResult::Failed;
	}

	ASplineSmartObject* SplineSmartObject = Cast<ASplineSmartObject>(PatrolCharacter->GetCurrentSmartObject());

	if (!SplineSmartObject)
	{
		return EBTNodeResult::Failed;
	}

	const TArray<FVector>& SplinePoints = SplineSmartObject->GetSplinePoints();

	if (CurrentSplineIndex > SplinePoints.Num())
	{
		return EBTNodeResult::Failed;
	}

	OwnerBlackboard->SetValue<UBlackboardKeyType_Vector>("MoveToLocation", SplinePoints[CurrentSplineIndex]);

	if (CurrentSplineIndex < SplinePoints.Num() - 1)
	{
		++CurrentSplineIndex;
		return EBTNodeResult::Succeeded;
 	}

	CurrentSplineIndex = 0;
	return EBTNodeResult::Succeeded;
}
