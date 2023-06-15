// Copyright A.T. Chamillard. All Rights Reserved.


#include "TeddyBearSpawner.h"

#include "Kismet/GameplayStatics.h"

/**
 * Sets default values
*/
ATeddyBearSpawner::ATeddyBearSpawner()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

}

/**
 * Called when the game starts or when spawned
*/
void ATeddyBearSpawner::BeginPlay()
{
	Super::BeginPlay();
	
	// save configuration data for efficiency
	TArray<AActor*> ConfigurationDataActors;
	UGameplayStatics::GetAllActorsWithTag(GetWorld(),
		"ConfigurationDataActor", ConfigurationDataActors);
	if (ConfigurationDataActors.Num() > 0)
	{
		ConfigurationData = (AConfigurationDataActor*)ConfigurationDataActors[0];
	}

	StartSpawnTimer();
}

/**
 * Called every frame
 * @param DeltaTime Game time elapsed during last frame modified by the time dilation
*/
void ATeddyBearSpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

/**
 * Spawns a teddy bear
*/
void ATeddyBearSpawner::SpawnTeddyBear()
{
	// generate random spawn location
	FVector SpawnLocation{ 0 };
	SpawnLocation.Y = FMath::RandRange(MinSpawnY, MaxSpawnY);
	SpawnLocation.Z = SpawnZ;

	// spawn the teddy bear
	GetWorld()->SpawnActor<ATeddyBear>(
		UTeddyBear, SpawnLocation,
		FRotator::ZeroRotator);

	// start the timer again
	StartSpawnTimer();
}

/**
 * Starts the spawn timer
*/
void ATeddyBearSpawner::StartSpawnTimer()
{
	// set random duration and start the timer
	float TimerDuration = FMath::RandRange(
		ConfigurationData->GetMinSpawnDelaySeconds(), 
		ConfigurationData->GetMaxSpawnDelaySeconds());
	FTimerHandle Timer;
	GetWorldTimerManager().SetTimer(Timer, this,
		&ATeddyBearSpawner::SpawnTeddyBear,
		TimerDuration);
}