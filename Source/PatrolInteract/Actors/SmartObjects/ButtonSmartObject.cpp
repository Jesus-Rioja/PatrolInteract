#include "Actors/SmartObjects/ButtonSmartObject.h"
#include "AIModule/Classes/BehaviorTree/Blackboard/BlackboardKeyType_Vector.h"
#include "AIModule/Classes/BehaviorTree/BlackboardComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Components/SphereComponent.h"
#include "Characters/ACharacterBase.h"
#include "Controllers/AIControllerBase.h"
#include "Actors/InteractiveDoor.h"

AButtonSmartObject::AButtonSmartObject() : Super()
{
	Activated = false;

	StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMeshComponent->SetupAttachment(RootComponent);

	ActionPoint = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ActionPoint"));
	ActionPoint->SetupAttachment(RootComponent);

	SphereComponent = CreateDefaultSubobject<USphereComponent>(TEXT("SPhere"));
	SphereComponent->SetupAttachment(RootComponent);
}

void AButtonSmartObject::BeginPlay()
{
	Super::BeginPlay();

	SphereComponent->OnComponentBeginOverlap.AddUniqueDynamic(this, &AButtonSmartObject::OnComponentBeginOverlap);
}

void AButtonSmartObject::OnComponentBeginOverlap(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (Activated)
	{
		return;
	}
	AACharacterBase* CharacterBase = Cast<AACharacterBase>(OtherActor);

	if (CharacterBase)
	{
		AAIControllerBase* ControllerBase = Cast<AAIControllerBase>(CharacterBase->GetController());

		if (ControllerBase)
		{
			if (InteractiveDoor != nullptr)
			{
				Activated = true;
				CharacterBase->SetCurrentInteractiveObject(InteractiveDoor);
				CharacterBase->SetPrevSmartObject(CharacterBase->GetCurrentSmartObject());
				CharacterBase->SetCurrentSmartObject(this);
				ControllerBase->SetSmartObjectTree();

				FTransform ParentTransform = this->GetTransform();
				FTransform ActionTransform = ActionPoint->GetRelativeTransform();

				FVector ActionLocation = ParentTransform.GetLocation() + ActionTransform.GetLocation();

				UBlackboardComponent* OwnerBlackboard = ControllerBase->GetBlackboardComponent();
				OwnerBlackboard->SetValue<UBlackboardKeyType_Vector>("MoveToLocation", ActionLocation);
			}
		}
	}
}
