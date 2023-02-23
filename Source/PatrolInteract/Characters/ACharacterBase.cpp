#include "Characters/ACharacterBase.h"
#include "BehaviorTree/BehaviorTree.h"
#include "Actors/SmartObjects/SmartObjectBase.h"
#include "../Actors/AInteractiveBase.h"

UBehaviorTree* AACharacterBase::GetBehaviorTree() const
{
	return BehaviorTree;
}

ASmartObjectBase* AACharacterBase::GetCurrentSmartObject() const
{
	return CurrentSmartObject;
}

ASmartObjectBase* AACharacterBase::GetPrevSmartObject() const
{
	return PrevSmartObject;
}

void AACharacterBase::SetCurrentSmartObject(ASmartObjectBase* SmartObject)
{
	CurrentSmartObject = SmartObject;
}

void AACharacterBase::SetPrevSmartObject(ASmartObjectBase* SmartObject)
{
	PrevSmartObject = SmartObject;
}

AAInteractiveBase* AACharacterBase::GetCurrentInteractiveObject() const
{
	return CurrentInteractiveObject;
}

void AACharacterBase::SetCurrentInteractiveObject(AAInteractiveBase* InteractiveObject)
{
	CurrentInteractiveObject = InteractiveObject;
}

