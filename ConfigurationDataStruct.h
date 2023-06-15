// Copyright A.T. Chamillard. All Rights Reserved.

#pragma once 

#include "Engine/DataTable.h"

#include "ConfigurationDataStruct.generated.h"

USTRUCT(BlueprintType)
struct FConfigurationDataStruct : public FTableRowBase
{
	GENERATED_USTRUCT_BODY()

public:

	FConfigurationDataStruct()
		: FishMoveAmountPerSecond(100)
		, FishForceMagnitude(300)
		, TeddyMoveAmountPerSecond(60)
		, MinSpawnDelaySeconds(2)
		, MaxSpawnDelaySeconds(4)
	{}

	UPROPERTY(EditAnywhere, BlueprintReadWrite,
		Category = "Configuration Data Struct")
		float FishMoveAmountPerSecond;
	UPROPERTY(EditAnywhere, BlueprintReadWrite,
		Category = "Configuration Data Struct")
		float FishForceMagnitude;
	UPROPERTY(EditAnywhere, BlueprintReadWrite,
		Category = "Configuration Data Struct")
		float TeddyMoveAmountPerSecond;
	UPROPERTY(EditAnywhere, BlueprintReadWrite,
		Category = "Configuration Data Struct")
		float MinSpawnDelaySeconds;
	UPROPERTY(EditAnywhere, BlueprintReadWrite,
		Category = "Configuration Data Struct")
		float MaxSpawnDelaySeconds;
};