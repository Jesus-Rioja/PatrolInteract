// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "ACharacterBase.generated.h"

class UBehaviorTree;
class ASmartObjectBase;
class AAInteractiveBase;

UCLASS()
class PATROLINTERACT_API AACharacterBase : public ACharacter
{
	GENERATED_BODY()

public:
	ASmartObjectBase* PrevSmartObject = nullptr;

	UBehaviorTree* GetBehaviorTree() const;
	ASmartObjectBase* GetCurrentSmartObject() const;
	ASmartObjectBase* GetPrevSmartObject() const;

	void SetCurrentSmartObject(ASmartObjectBase* SmartObject);
	void SetPrevSmartObject(ASmartObjectBase* SmartObject);

	AAInteractiveBase* GetCurrentInteractiveObject() const;
	void SetCurrentInteractiveObject(AAInteractiveBase* InteractiveObject);

protected:
	UPROPERTY(EditAnywhere, Category = AI)
		UBehaviorTree* BehaviorTree = nullptr;
	UPROPERTY(EditAnywhere, Category = AI)
		ASmartObjectBase* CurrentSmartObject = nullptr;
	UPROPERTY(EditAnywhere, Category = AI)
		AAInteractiveBase* CurrentInteractiveObject = nullptr;

};
