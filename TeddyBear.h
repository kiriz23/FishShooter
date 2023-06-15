// Copyright A.T. Chamillard. All Rights Reserved.

#pragma once

#include "ConfigurationDataActor.h"
#include "DelegateDeclarations.h"

#include "Sound/SoundCue.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TeddyBear.generated.h"

/**
 * A teddy bear
*/
UCLASS()
class FISHSHOOTER_API ATeddyBear : public AActor
{
	GENERATED_BODY()
	
private:
	//const float MoveAmountPerSecond{ 60 };
	float HalfCollisionHeight;
	int Health{ 100 };

	// saved for efficiency
	AConfigurationDataActor* ConfigurationData;
	
	// event support
	FKillAddedEvent KillAddedEvent;

public:	
	UPROPERTY(EditAnywhere, BlueprintReadWrite,
		Category = "Sound")
		USoundCue* AudioCue;

	/**
	 * Sets default values for this actor's properties
	*/
	ATeddyBear();

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
	 * Called when the teddy bear overlaps with something else
	*/
	UFUNCTION()
		void OnOverlapBegin(class UPrimitiveComponent* OverlappedComp,
			class AActor* OtherActor, class UPrimitiveComponent* OtherComp,
			int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	/**
	 * Gets the kill added event for this teddy bear
	 * @return kill added event
	*/
	FKillAddedEvent& GetKillAddedEvent();

	/**
	 * Called when actor is being removed from level
	 * @param EndPlayReason why the actor is being removed
	*/
	UFUNCTION()
		virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
};
