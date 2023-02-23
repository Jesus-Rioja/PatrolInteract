// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "AIControllerBase.generated.h"

class UBehaviorTreeComponent;
class AACharacterBase;

UCLASS()
class PATROLINTERACT_API AAIControllerBase : public AAIController
{
	GENERATED_BODY()

public:
	AAIControllerBase();

	void SetSmartObjectTree();

	void ReturnToPrevSmartObjectTree();

	UBlackboardComponent* GetBlackboardComponent() const;

protected:
	UPROPERTY()
		UBehaviorTreeComponent* BehaviorTreeComponent = nullptr;
	UPROPERTY()
		UBlackboardComponent* BlackboardComponent = nullptr;
	UPROPERTY()
		AACharacterBase* CurrentTarget = nullptr;

	virtual void BeginPlay() override;
	virtual void OnPossess(APawn* InPawn) override;
	
};
