#include "Actors/SmartObjects/SmartObjectBase.h"
#include "Components/BillboardComponent.h"
#include "Components/ArrowComponent.h"
#include "Components/SceneComponent.h"
#include "AIModule/Classes/BehaviorTree/BehaviorTree.h"

ASmartObjectBase::ASmartObjectBase()
{
	PrimaryActorTick.bCanEverTick = true;

	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));

	BillboardComponent = CreateDefaultSubobject<UBillboardComponent>(TEXT("BillboardComponent"));
	BillboardComponent->SetupAttachment(RootComponent);

	ArrowComponent = CreateDefaultSubobject<UArrowComponent>(TEXT("ArrowComponent"));
	ArrowComponent->SetupAttachment(RootComponent);

}


UBehaviorTree* ASmartObjectBase::GetBehaviourTree() const
{
	return BehaviourTree;
}

