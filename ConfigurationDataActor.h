// Copyright A.T. Chamillard. All Rights Reserved.

#pragma once

#include "Engine/DataTable.h"
#include "ConfigurationDataStruct.h"

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ConfigurationDataActor.generated.h"

/**
 *
*/
UCLASS()
class FISHSHOOTER_API AConfigurationDataActor : public AActor
{
	GENERATED_BODY()

private:
	// saved for efficiency
	FConfigurationDataStruct* ConfigurationDataRow;

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite,
		Category = "Configuration Data Table")
		UDataTable* ConfigurationDataTable;

	/**
	 * Sets default values for this actor's properties
	*/
	AConfigurationDataActor();

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
	 * Gets the fish move amount per second
	 * @return fish move amount per second
	*/
	float GetFishMoveAmountPerSecond();

	/**
	 * Gets the fish force magnitude
	 * @return fish force magnitude
	*/
	float GetFishForceMagnitude();

	/**
	 * Gets the teddy move amount per second
	 * @return teddy move amount per second
	*/
	float GetTeddyMoveAmountPerSecond();

	/**
	 * Gets the min spawn delay seconds
	 * @return min spawn delay seconds
	*/
	float GetMinSpawnDelaySeconds();

	/**
	 * Gets the max spawn delay seconds
	 * @return max spawn delay seconds
	*/
	float GetMaxSpawnDelaySeconds();
};
