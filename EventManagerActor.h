// Copyright A.T. Chamillard. All Rights Reserved.

#pragma once

#include "TeddyBear.h"
#include "GameHud.h"
#include "Delegates/DelegateInstanceInterface.h"

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "EventManagerActor.generated.h"

/**
 * An event manager
*/
UCLASS()
class FISHSHOOTER_API AEventManagerActor : public AActor
{
	GENERATED_BODY()
	
private:
	UPROPERTY()
		TArray<ATeddyBear*> KillAddedEventInvokers;
	TMap<AGameHUD*, TMap<ATeddyBear*, FDelegateHandle>> KillAddedEventListeners;

public:	
	/**
	 * Sets default values for this actor's properties
	*/
	AEventManagerActor();

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
	 * Adds the given invoker as an invoker of the message event
	 * @param Invoker invoker
	*/
	void AddInvoker(ATeddyBear* Invoker);

	/**
	 * Removes the given invoker as an invoker of the message event
	 * @param Invoker invoker
	*/
	void RemoveInvoker(ATeddyBear* Invoker);

	/**
	 * Adds the given listener as a listener for the message event
	 * @param Listener listener
	*/
	void AddListener(AGameHUD* Listener);

	/**
	 * Removes the given listener as a listener for the message event
	 * @param Listener listener
	*/
	void RemoveListener(AGameHUD* Listener);
};
