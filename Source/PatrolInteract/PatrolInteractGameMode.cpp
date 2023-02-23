// Copyright Epic Games, Inc. All Rights Reserved.

#include "PatrolInteractGameMode.h"
#include "PatrolInteractCharacter.h"
#include "UObject/ConstructorHelpers.h"

APatrolInteractGameMode::APatrolInteractGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
