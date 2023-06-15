// Copyright A.T. Chamillard. All Rights Reserved.


#include "EventManagerActor.h"

/**
 * Sets default values
*/
AEventManagerActor::AEventManagerActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

/**
 * Called when the game starts or when spawned
*/
void AEventManagerActor::BeginPlay()
{
	Super::BeginPlay();
	
}

/**
 * Called every frame
 * @param DeltaTime Game time elapsed during last frame modified by the time dilation
*/
void AEventManagerActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

/**
 * Adds the given invoker as an invoker of the message event
 * @param Invoker invoker
*/
void AEventManagerActor::AddInvoker(ATeddyBear* Invoker)
{
	// add new invoker and add all listeners for new invoker
	KillAddedEventInvokers.Add(Invoker);
	for (auto& Element : KillAddedEventListeners)
	{
		FDelegateHandle DelegateHandle = Element.Key->AddToKillAddedEvent(
			Invoker->GetKillAddedEvent());
		Element.Value.Add(Invoker, DelegateHandle);
	}
}

/**
 * Removes the given invoker as an invoker of the message event
 * @param Invoker invoker
*/
void AEventManagerActor::RemoveInvoker(ATeddyBear* Invoker)
{
	// remove all listeners from invoker
	for (auto& Element : KillAddedEventListeners)
	{
		if (Element.Value.Contains(Invoker))
		{
			Invoker->GetKillAddedEvent().Remove(
				Element.Value[Invoker]);
			Element.Value.Remove(Invoker);
		}
	}

	// remove invoker
	KillAddedEventInvokers.Remove(Invoker);
}

/**
 * Adds the given listener as a listener for the message event
 * @param Listener listener
*/
void AEventManagerActor::AddListener(AGameHUD* Listener)
{
	// add new listener and add new listener to all invokers
	KillAddedEventListeners.Add(Listener);
	for (auto& Element : KillAddedEventInvokers)
	{
		FDelegateHandle DelegateHandle = Listener->AddToKillAddedEvent(
			Element->GetKillAddedEvent());
		KillAddedEventListeners[Listener].Add(Element, DelegateHandle);
	}
}

/**
 * Removes the given listener as a listener for the message event
 * @param Listener listener
*/
void AEventManagerActor::RemoveListener(AGameHUD* Listener)
{
	// remove listener from all invokers
	for (auto& Element : KillAddedEventInvokers)
	{
		if (KillAddedEventListeners[Listener].Contains(Element))
		{
			Element->GetKillAddedEvent().Remove(
				KillAddedEventListeners[Listener][Element]);
			KillAddedEventListeners[Listener].Remove(Element);
		}
	}

	// remove listener
	KillAddedEventListeners.Remove(Listener);
}