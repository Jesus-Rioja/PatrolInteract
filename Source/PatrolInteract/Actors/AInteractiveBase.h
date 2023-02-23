// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AInteractiveBase.generated.h"

UCLASS()
class PATROLINTERACT_API AAInteractiveBase : public AActor
{
	GENERATED_BODY()
	
public:	

	virtual void OnInteract();

};
