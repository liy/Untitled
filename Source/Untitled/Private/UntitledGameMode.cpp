// Copyright 1998-2014 Epic Games, Inc. All Rights Reserved.

#include "Untitled.h"
#include "CharacterController.h"
#include "UntitledGameMode.h"

AUntitledGameMode::AUntitledGameMode(const FObjectInitializer& objectInitializer)
	: Super(objectInitializer)
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/Blueprints/CharacterBP"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}

	static ConstructorHelpers::FClassFinder<APlayerController> ControllerClassObject(TEXT("/Game/Blueprints/CharacterControllerBP"));
	if (ControllerClassObject.Class != NULL)
	{
		PlayerControllerClass = ControllerClassObject.Class;
	}
}
