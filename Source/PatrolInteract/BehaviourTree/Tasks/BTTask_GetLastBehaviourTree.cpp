// Fill out your copyright notice in the Description page of Project Settings.


#include "BehaviourTree/Tasks/BTTask_GetLastBehaviourTree.h"
#include "AIModule/Classes/AIController.h"
#include "AIModule/Classes/BehaviorTree/Blackboard/BlackboardKeyType_Vector.h"
#include "AIModule/Classes/BehaviorTree/BlackboardComponent.h"
#include "Characters/Patrol/ACharacterPatrol.h"
#include "Controllers/AIControllerBase.h"


UBTTask_GetLastBehaviourTree::UBTTask_GetLastBehaviourTree(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	NodeName = "Return To Last BT";
	bCreateNodeInstance = true;
}

EBTNodeResult::Type UBTTask_GetLastBehaviourTree::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
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

	AAIControllerBase* PatrolControler = Cast<AAIControllerBase>(OwnerController);
	if (!PatrolControler)
	{
		return EBTNodeResult::Failed;
	}

	PatrolCharacter->SetCurrentSmartObject(PatrolCharacter->GetPrevSmartObject());
	PatrolControler->SetSmartObjectTree();


	return EBTNodeResult::Succeeded;
}
