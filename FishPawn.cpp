// Copyright A.T. Chamillard. All Rights Reserved.


#include "FishPawn.h"

#include "Kismet/GameplayStatics.h"
#include "ScreenConstants.h"

/**
 * Sets default values
*/
AFishPawn::AFishPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

/**
 * Called when the game starts or when spawned
*/
void AFishPawn::BeginPlay()
{
	Super::BeginPlay();
	
	// save bounds for pawn
	FVector Origin;
	FVector BoxExtent;
	GetActorBounds(true, Origin, BoxExtent);
	HalfCollisionWidth = BoxExtent.Y;
	HalfCollisionHeight = BoxExtent.Z;

	// save static mesh component for efficiency
	TArray<UStaticMeshComponent*> StaticMeshComponents;
	GetComponents(StaticMeshComponents);

	// make sure we found the static mesh
	if (StaticMeshComponents.Num() > 0)
	{
		// the mesh we want is at location 0 because there's only 1 mesh
		StaticMeshComponent = StaticMeshComponents[0];

		// set up delegate for collisions with something else
		StaticMeshComponent->OnComponentBeginOverlap.AddDynamic(this, &AFishPawn::OnOverlapBegin);
	}

	// save configuration data for efficiency
	TArray<AActor*> ConfigurationDataActors;
	UGameplayStatics::GetAllActorsWithTag(GetWorld(),
		"ConfigurationDataActor", ConfigurationDataActors);
	if (ConfigurationDataActors.Num() > 0)
	{
		ConfigurationData = (AConfigurationDataActor*)ConfigurationDataActors[0];
	}

	// reset to start state
	ResetToStartState();
}

/**
 * Called every frame
 * @param DeltaTime Game time elapsed during last frame modified by the time dilation
*/
void AFishPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// move pawn based on movement input
	FVector PendingMovementInput = ConsumeMovementInputVector();
	if (PendingMovementInput.Y != 0)
	{
		FVector NewLocation = GetActorLocation();
		NewLocation.Y += PendingMovementInput.Y *
			ConfigurationData->GetFishMoveAmountPerSecond() * DeltaTime;
		NewLocation.Y = FMath::Clamp(NewLocation.Y,
			ScreenConstants::Left + HalfCollisionWidth,
			ScreenConstants::Right - HalfCollisionWidth);
		SetActorLocation(NewLocation);
	}

	// reset to start state if above top of screen
	if (GetActorLocation().Z >
		ScreenConstants::Top + HalfCollisionHeight)
	{
		ResetToStartState();
	}
}

/**
 * Called when the fish overlaps with something else
*/
void AFishPawn::OnOverlapBegin(class UPrimitiveComponent* OverlappedComp,
	class AActor* OtherActor, class UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	// check for teddy bear
	if (OtherActor != nullptr &&
		OtherActor->ActorHasTag("TeddyBear"))
	{
		ResetToStartState();
	}
}

/**
 * Gets the damage inflicted by the fish
 * @return damage
*/
int AFishPawn::GetDamage()
{
	return Damage;
}

/**
 * Sets the damage inflicted by the fish
 * @param FishDamage damage
*/
void AFishPawn::SetDamage(int FishDamage)
{
	Damage = FishDamage;
}

/**
 * Moves the fish horizontally
 * @param moveScale scale factor for movement
*/
void AFishPawn::MoveHorizontally(float moveScale)
{
	moveScale = FMath::Clamp(moveScale, -1.0f, 1.0f);
	AddMovementInput(GetActorRightVector(),
		moveScale);
}

/**
 * Shoots the fish
*/
void AFishPawn::Shoot()
{
	// add impulse force to mesh
	if (!WasShot)
	{
		WasShot = true;
		FVector ForceVector{ 0, 0, ConfigurationData->GetFishForceMagnitude() };
		StaticMeshComponent->AddImpulse(ForceVector);
	}
}

/**
 * Resets the fish to its start state
*/
void AFishPawn::ResetToStartState()
{
	FVector Location{ 0 };
	Location.Z = ScreenConstants::Bottom +
		HalfCollisionHeight;
	SetActorLocation(Location);
	WasShot = false;
	
	// stop pawn
	StaticMeshComponent->SetAllPhysicsLinearVelocity(
		FVector::ZeroVector);
}