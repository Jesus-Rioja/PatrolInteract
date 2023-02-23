// Fill out your copyright notice in the Description page of Project Settings.


#include "AIControllerBase.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "../Characters/ACharacterBase.h"
#include "Actors/SmartObjects/SmartObjectBase.h"
#include "Characters/ACharacterBase.h"

AAIControllerBase::AAIControllerBase() : Super()
{
	BehaviorTreeComponent = CreateDefaultSubobject<UBehaviorTreeComponent>(TEXT("Behavior Tree Component"));
	BlackboardComponent = CreateDefaultSubobject<UBlackboardComponent>(TEXT("Blackboard Component"));
}

void AAIControllerBase::SetSmartObjectTree()
{
	AACharacterBase* CharacterBase = Cast<AACharacterBase>(GetPawn());
	if (!CharacterBase)
	{
		return;
	}

	ASmartObjectBase* SmartObject = CharacterBase->GetCurrentSmartObject();
	if (SmartObject)
	{
		FGameplayTag SubTag;
		BehaviorTreeComponent->SetDynamicSubtree(SubTag, SmartObject->GetBehaviourTree());
	}
}

void AAIControllerBase::ReturnToPrevSmartObjectTree()
{
	AACharacterBase* CharacterBase = Cast<AACharacterBase>(GetPawn());
	if (!CharacterBase)
	{
		return;
	}

	ASmartObjectBase* SmartObject = CharacterBase->GetPrevSmartObject();
	if (SmartObject)
	{
		FGameplayTag SubTag;
		BehaviorTreeComponent->SetDynamicSubtree(SubTag, SmartObject->GetBehaviourTree());
	}

}

UBlackboardComponent* AAIControllerBase::GetBlackboardComponent() const
{
	return BlackboardComponent;
}

void AAIControllerBase::BeginPlay()
{
	Super::BeginPlay();	

	SetSmartObjectTree();
}

void AAIControllerBase::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);

	AACharacterBase* CharacterBase = Cast<AACharacterBase>(InPawn);
	UBehaviorTree* CharacterBehaviorTree = CharacterBase ? CharacterBase->GetBehaviorTree() : nullptr;

	if (CharacterBehaviorTree)
	{
		BlackboardComponent->InitializeBlackboard(*CharacterBehaviorTree->BlackboardAsset);
		BehaviorTreeComponent->StartTree(*CharacterBehaviorTree);
	}
}
