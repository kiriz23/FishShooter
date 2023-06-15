// Copyright A.T. Chamillard. All Rights Reserved.


#include "ConfigurationDataActor.h"

/**
 * Sets default values
*/
AConfigurationDataActor::AConfigurationDataActor()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

}

/**
 * Called when the game starts or when spawned
*/
void AConfigurationDataActor::BeginPlay()
{
	Super::BeginPlay();

	// retrieve configuration data from data table
	FString ContextString;
	ConfigurationDataRow =
		ConfigurationDataTable->FindRow<FConfigurationDataStruct>(
			"ConfigData", ContextString);
}

/**
 * Called every frame
 * @param DeltaTime Game time elapsed during last frame modified by the time dilation
*/
void AConfigurationDataActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

/**
 * Gets the fish move amount per second
 * @return fish move amount per second
*/
float AConfigurationDataActor::GetFishMoveAmountPerSecond()
{
	return ConfigurationDataRow->FishMoveAmountPerSecond;
}

/**
 * Gets the fish force magnitude
 * @return fish force magnitude
*/
float AConfigurationDataActor::GetFishForceMagnitude()
{
	return ConfigurationDataRow->FishForceMagnitude;
}

/**
 * Gets the teddy move amount per second
 * @return teddy move amount per second
*/
float AConfigurationDataActor::GetTeddyMoveAmountPerSecond()
{
	return ConfigurationDataRow->TeddyMoveAmountPerSecond;
}

/**
 * Gets the min spawn delay seconds
 * @return min spawn delay seconds
*/
float AConfigurationDataActor::GetMinSpawnDelaySeconds()
{
	return ConfigurationDataRow->MinSpawnDelaySeconds;
}

/**
 * Gets the max spawn delay seconds
 * @return max spawn delay seconds
*/
float AConfigurationDataActor::GetMaxSpawnDelaySeconds()
{
	return ConfigurationDataRow->MaxSpawnDelaySeconds;
}