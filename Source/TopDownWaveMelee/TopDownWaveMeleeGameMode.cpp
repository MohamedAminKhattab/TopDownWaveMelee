// Copyright Epic Games, Inc. All Rights Reserved.

#include "TopDownWaveMeleeGameMode.h"
#include "TopDownWaveMeleePlayerController.h"
#include "TopDownWaveMeleeCharacter.h"
#include "UObject/ConstructorHelpers.h"

ATopDownWaveMeleeGameMode::ATopDownWaveMeleeGameMode()
{
	// use our custom PlayerController class
	PlayerControllerClass = ATopDownWaveMeleePlayerController::StaticClass();

	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/TopDownCPP/Blueprints/TopDownCharacter"));
	if (PlayerPawnBPClass.Class != nullptr)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}