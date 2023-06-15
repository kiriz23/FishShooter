// Copyright A.T. Chamillard. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "FishPlayerController.generated.h"

/**
 * A fish player controller
 */
UCLASS()
class FISHSHOOTER_API AFishPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	/**
	 * Called to bind functionality to input
	*/
	virtual void SetupInputComponent() override;

	/**
	 * Moves the fish horizontally
	 * @param input input on Horizontal axis
	*/
	void MoveHorizontally(float input);

	/**
	 * Shoots the fish
	*/
	void ShootFish();
};
