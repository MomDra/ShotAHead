// Copyright Epic Games, Inc. All Rights Reserved.

#include "ShotAHeadGameMode.h"
#include "ShotAHeadCharacter.h"
#include "UObject/ConstructorHelpers.h"

AShotAHeadGameMode::AShotAHeadGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
