// Copyright A.T. Chamillard. All Rights Reserved.

#include "GameHUD.h"

#include "Kismet/GameplayStatics.h"
#include "EventManagerActor.h"

/**
 * Called when the game starts or when spawned
*/
void AGameHUD::BeginPlay()
{
	Super::BeginPlay();

	// add to event manager
	TArray<AActor*> TaggedActors;
	UGameplayStatics::GetAllActorsWithTag(
		GetWorld(), "EventManager", TaggedActors);
	if (TaggedActors.Num() > 0)
	{
		AEventManagerActor* EventManager = Cast<AEventManagerActor>(
			TaggedActors[0]);
		EventManager->AddListener(this);
	}
}

/**
 * Draws the HUD
*/
void AGameHUD::DrawHUD()
{
	Super::DrawHUD();

	// draw kills
	DrawText(KillLabel + FString::FromInt(Kills),
		FLinearColor::White,
		LeftOffset, TopOffset, HudFont);
}

/**
 * Adds a kill to the kill count
*/
void AGameHUD::AddKill()
{
	Kills++;
}

/**
 * Adds this object to the given kill added event
 * @param KillAddedEvent kill added event
 * @return delegate handle
*/
FDelegateHandle AGameHUD::AddToKillAddedEvent(FKillAddedEvent& KillAddedEvent)
{
	return KillAddedEvent.AddUObject(this,
		&AGameHUD::AddKill);
}

/**
 * Called when actor is being removed from level
 * @param EndPlayReason why the actor is being removed
*/
void AGameHUD::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	// remove from event manager
	TArray<AActor*> TaggedActors;
	UGameplayStatics::GetAllActorsWithTag(
		GetWorld(), "EventManager", TaggedActors);
	if (TaggedActors.Num() > 0)
	{
		AEventManagerActor* EventManager = Cast<AEventManagerActor>(
			TaggedActors[0]);
		EventManager->RemoveListener(this);
	}
}
