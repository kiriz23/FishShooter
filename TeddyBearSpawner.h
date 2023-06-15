// Copyright A.T. Chamillard. All Rights Reserved.

#pragma once

#include "TeddyBear.h"
#include "ConfigurationDataActor.h"

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TeddyBearSpawner.generated.h"

/**
 * A teddy bear spawner
*/
UCLASS()
class FISHSHOOTER_API ATeddyBearSpawner : public AActor
{
	GENERATED_BODY()

private:
	// spawn delay support
	const float MinSpawnDelaySeconds{ 2 };
	const float MaxSpawnDelaySeconds{ 4 };

	// spawn location support
	const float MinSpawnY{ -200 };
	const float MaxSpawnY{ 200 };
	const float SpawnZ{ 150 };

	// saved for efficiency
	AConfigurationDataActor* ConfigurationData;

	/**
	 * Starts the spawn timer
	*/
	void StartSpawnTimer();
public:
	UPROPERTY(EditAnywhere,
		meta = (MetaClass = "TeddyBear"),
		Category = TeddyBearBlueprints)
		TSubclassOf<ATeddyBear> UTeddyBear;

	/**
	 * Spawns a teddy bear
	*/
	UFUNCTION()
		void SpawnTeddyBear();

public:	
	/**
	 * Sets default values for this actor's properties
	*/
	ATeddyBearSpawner();

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

};
