// Copyright A.T. Chamillard. All Rights Reserved.

#pragma once

#include "DelegateDeclarations.h"

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "GameHUD.generated.h"

/**
 * The HUD
 */
UCLASS()
class FISHSHOOTER_API AGameHUD : public AHUD
{
	GENERATED_BODY()

private:
	const int LeftOffset{ 75 };
	const int TopOffset{ 50 };
	const FString KillLabel{ "Kills: " };
	int Kills{ 0 };

protected:
	/**
	 * Called when the game starts or when spawned
	*/
	virtual void BeginPlay() override;

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite,
		Category = HUDFont)
		UFont* HudFont;

	/**
	 * Draws the HUD
	*/
	virtual void DrawHUD() override;

	/**
	 * Adds a kill to the kill count
	*/
	UFUNCTION()
		void AddKill();

	/**
	 * Adds this object to the given kill added event
	 * @param KillAddedEvent kill added event
	 * @return delegate handle
	*/
	FDelegateHandle AddToKillAddedEvent(FKillAddedEvent& KillAddedEvent);

	/**
	 * Called when actor is being removed from level
	 * @param EndPlayReason why the actor is being removed
	*/
	UFUNCTION()
		virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
};
