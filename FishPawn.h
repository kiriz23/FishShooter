// Copyright A.T. Chamillard. All Rights Reserved.

#pragma once

#include "ConfigurationDataActor.h"

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "FishPawn.generated.h"

/**
 * A fish pawn
*/
UCLASS()
class FISHSHOOTER_API AFishPawn : public APawn
{
	GENERATED_BODY()

private:
	//const float MoveAmountPerSecond{ 100 };
	float HalfCollisionWidth;
	float HalfCollisionHeight;
	//const float ForceMagnitude{ 300 };
	bool WasShot{ false };
	int Damage{ 100 };

	// saved for efficiency
	UStaticMeshComponent* StaticMeshComponent;
	AConfigurationDataActor* ConfigurationData;

public:
	/**
	 * Sets default values for this pawn's properties
	*/
	AFishPawn();

protected:
	/**
	 * Called when the game starts or when spawned
	*/
	virtual void BeginPlay() override;

public:	
	/**
	 * Called every frame
	 * @param DeltaTime Game time elapsed during last frame modified by the time dilation
	*/
	virtual void Tick(float DeltaTime) override;

	/**
	 * Called when the fish overlaps with something else
	*/
	UFUNCTION()
		void OnOverlapBegin(class UPrimitiveComponent* OverlappedComp,
			class AActor* OtherActor, class UPrimitiveComponent* OtherComp,
			int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	/**
	 * Gets the damage inflicted by the fish
	 * @return damage
	*/
	int GetDamage();

	/**
	 * Sets the damage inflicted by the fish
	 * @param FishDamage damage
	*/
	void SetDamage(int FishDamage);

	/**
	 * Moves the fish horizontally
	 * @param moveScale scale factor for movement
	*/
	void MoveHorizontally(float moveScale);

	/**
	 * Shoots the fish
	*/
	void Shoot();

private:
	/**
	 * Resets the fish to its start state
	*/
	void ResetToStartState();
};
