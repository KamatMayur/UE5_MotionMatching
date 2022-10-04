// Copyright Epic Games, Inc. All Rights Reserved.

#include "MotionMatchingGameMode.h"
#include "MotionMatchingCharacter.h"
#include "UObject/ConstructorHelpers.h"

AMotionMatchingGameMode::AMotionMatchingGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
