// Copyright Epic Games, Inc. All Rights Reserved.

#include "TFDGameMode.h"
#include "Character/TFDCharacter.h"
#include "UObject/ConstructorHelpers.h"

ATFDGameMode::ATFDGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
