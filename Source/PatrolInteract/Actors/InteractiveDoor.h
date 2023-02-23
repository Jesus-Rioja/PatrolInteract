// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AInteractiveBase.h"
#include "InteractiveDoor.generated.h"

class UStaticMeshComponent;

UCLASS()
class PATROLINTERACT_API AInteractiveDoor : public AAInteractiveBase
{
	GENERATED_BODY()
	
public:	
	
	AInteractiveDoor();

	UPROPERTY(EditAnywhere)
		UStaticMeshComponent* StaticMeshComponent = nullptr;


};
