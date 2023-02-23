// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Tasks/BTTask_BlackboardBase.h"
#include "BTTask_GetLastBehaviourTree.generated.h"

/**
 * 
 */
UCLASS()
class PATROLINTERACT_API UBTTask_GetLastBehaviourTree : public UBTTask_BlackboardBase
{
	GENERATED_BODY()

public:
	UBTTask_GetLastBehaviourTree(const FObjectInitializer& ObjectInitializer);

protected:
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;

	
};
