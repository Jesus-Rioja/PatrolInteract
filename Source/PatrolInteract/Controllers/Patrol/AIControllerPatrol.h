// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIModule/Classes/Perception/AIPerceptionTypes.h"
#include "../AIControllerBase.h"
#include "AIControllerPatrol.generated.h"

class UAISenseConfig_Sight;

UCLASS()
class PATROLINTERACT_API AAIControllerPatrol : public AAIControllerBase
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditDefaultsOnly, Category = AI)
		UAISenseConfig_Sight* SightConfig;

	UFUNCTION(BlueprintCallable)
		const float GetCurrentAggro() const;
	UFUNCTION(BlueprintCallable)
		const float GetMaxAggro() const;
	AAIControllerPatrol();

protected:

	virtual void BeginPlay() override;

private:
	UFUNCTION()
		void OnTargetPerceptionUpdated(AActor* Actor, FAIStimulus Stimulus);

	void OnAggroIncrease();
	void OnAggroDecrease();

	float Aggro = 0.f;
	FTimerHandle AggroIncrease;
	FTimerHandle AggroDecrease;
};
