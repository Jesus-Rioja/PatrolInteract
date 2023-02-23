// Fill out your copyright notice in the Description page of Project Settings.


#include "BehaviourTree/Tasks/BTTask_InteractWithObject.h"
#include "AIModule/Classes/AIController.h"
#include "AIModule/Classes/BehaviorTree/Blackboard/BlackboardKeyType_Vector.h"
#include "AIModule/Classes/BehaviorTree/BlackboardComponent.h"
#include "Characters/Patrol/ACharacterPatrol.h"
#include "Actors/InteractiveDoor.h"
#include "Actors/SmartObjects/SmartObjectBase.h"

UBTTask_InteractWithObject::UBTTask_InteractWithObject(const FObjectInitializer& ObjectInitializer)
{
	NodeName = "Interact With Object";
	bCreateNodeInstance = true;
}

EBTNodeResult::Type UBTTask_InteractWithObject::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
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

	AAInteractiveBase* InteractiveItem = Cast<AAInteractiveBase>(PatrolCharacter->GetCurrentInteractiveObject());

	if (!InteractiveItem)
	{
		return EBTNodeResult::Failed;
	}

	InteractiveItem->OnInteract();

	return EBTNodeResult::Succeeded;
}
