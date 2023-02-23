// Fill out your copyright notice in the Description page of Project Settings.


#include "Controllers/Patrol/AIControllerPatrol.h"
#include "AIModule/Classes/BehaviorTree/Blackboard/BlackboardKeyType_Vector.h"
#include "AIModule/Classes/BehaviorTree/BlackboardComponent.h"
#include "AIModule/Classes/Perception/AIPerceptionComponent.h"
#include "AIModule/Classes/Perception/AIPerceptionSystem.h"
#include "AIModule/Classes/Perception/AISenseConfig_Sight.h"

namespace AAIControllerPatrol_Consts
{
	constexpr float MAX_AGGRO = 100.f;
	constexpr float AGGRO_INC_VALUE = 10.f;
}

const float AAIControllerPatrol::GetCurrentAggro() const
{
	return Aggro;
}

const float AAIControllerPatrol::GetMaxAggro() const
{
	return AAIControllerPatrol_Consts::MAX_AGGRO;
}

AAIControllerPatrol::AAIControllerPatrol() : Super()
{
	PerceptionComponent = CreateDefaultSubobject<UAIPerceptionComponent>(TEXT("PerceptionComponent"));
	SightConfig = CreateDefaultSubobject<UAISenseConfig_Sight>(TEXT("Sight Config"));

	SightConfig->SightRadius = 500.f;
	SightConfig->LoseSightRadius = SightConfig->SightRadius + 20.f;
	SightConfig->PeripheralVisionAngleDegrees = 45.f;
	SightConfig->DetectionByAffiliation.bDetectEnemies = true;
	SightConfig->DetectionByAffiliation.bDetectFriendlies = true;
	SightConfig->DetectionByAffiliation.bDetectNeutrals = true;

	PerceptionComponent->ConfigureSense(*SightConfig);
	PerceptionComponent->SetDominantSense(SightConfig->GetSenseImplementation());
}

void AAIControllerPatrol::BeginPlay()
{
	Super::BeginPlay();
	PerceptionComponent->OnTargetPerceptionUpdated.AddUniqueDynamic(this, &AAIControllerPatrol::OnTargetPerceptionUpdated);
}

void AAIControllerPatrol::OnTargetPerceptionUpdated(AActor* Actor, FAIStimulus Stimulus)
{
	if (UAIPerceptionSystem::GetSenseClassForStimulus(this, Stimulus) == UAISense_Sight::StaticClass())
	{
		if (Stimulus.WasSuccessfullySensed())
		{
			if (!AggroIncrease.IsValid())
			{
				GetWorldTimerManager().SetTimer(AggroIncrease, this, &AAIControllerPatrol::OnAggroIncrease, 0.5f, true);
			}

			if (AggroDecrease.IsValid())
			{
				GetWorldTimerManager().ClearTimer(AggroDecrease);
			}
		}
		else
		{
			if (AggroIncrease.IsValid())
			{
				GetWorldTimerManager().ClearTimer(AggroIncrease);
			}

			if (!AggroDecrease.IsValid())
			{
				GetWorldTimerManager().SetTimer(AggroDecrease, this, &AAIControllerPatrol::OnAggroDecrease, 0.5f, true);
			}
		}
	}
}

void AAIControllerPatrol::OnAggroIncrease()
{
	if (Aggro < AAIControllerPatrol_Consts::MAX_AGGRO)
	{
		Aggro += AAIControllerPatrol_Consts::AGGRO_INC_VALUE;
	}
}

void AAIControllerPatrol::OnAggroDecrease()
{
	if (Aggro >= 0.f)
	{
		Aggro -= AAIControllerPatrol_Consts::AGGRO_INC_VALUE;
	}
	else
	{
		Aggro = 0.f;
	}
}
