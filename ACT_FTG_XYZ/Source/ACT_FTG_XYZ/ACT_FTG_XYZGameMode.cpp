// Copyright Epic Games, Inc. All Rights Reserved.

#include "ACT_FTG_XYZGameMode.h"
#include "ACT_FTG_XYZCharacter.h"
#include "UObject/ConstructorHelpers.h"

AACT_FTG_XYZGameMode::AACT_FTG_XYZGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
