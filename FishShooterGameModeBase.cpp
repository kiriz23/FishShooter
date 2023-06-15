// Copyright Epic Games, Inc. All Rights Reserved.


#include "FishShooterGameModeBase.h"

/**
 * Sets default values
*/
AFishShooterGameModeBase::AFishShooterGameModeBase()
{
	// set pawn and player controller
	ConstructorHelpers::FObjectFinder<UClass>
		PawnClass(TEXT("Class'/Game/FishShooter/Blueprints/BP_FishPawn.BP_FishPawn_C'"));
	if (PawnClass.Object != nullptr)
	{
		DefaultPawnClass = PawnClass.Object;
	}
	ConstructorHelpers::FObjectFinder<UClass>
		ControllerClass(TEXT("Class'/Game/FishShooter/Blueprints/BP_FishPlayerController.BP_FishPlayerController_C'"));
	if (ControllerClass.Object != nullptr)
	{
		PlayerControllerClass = ControllerClass.Object;
	}
}