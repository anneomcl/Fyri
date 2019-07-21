// Fill out your copyright notice in the Description page of Project Settings.

#include "ObjectManager.h"
#include "Engine\Classes\Components\InputComponent.h"
#include "Engine/World.h"
#include "Tile.h"
#include "Components/ActorComponent.h"
#include "GameFramework/PlayerController.h"
#include "Kismet/GameplayStatics.h"
#include "UObjectIterator.h"
#include "EngineUtils.h"
#include "DrawDebugHelpers.h"
#include "PlantableObject.h"
#include "Engine/Engine.h"
#include <Experimental/Chaos/Public/Chaos/Pair.h>

#define BIG_FLOAT 99999999999.f

#define DEBUG_RENDER false

AObjectManagerComponent::AObjectManagerComponent()
	:mObjectIndex(0)
{
	PrimaryActorTick.bCanEverTick = true;
	PrimaryActorTick.bStartWithTickEnabled = true;
}

AObjectManagerComponent::~AObjectManagerComponent()
{
}

void AObjectManagerComponent::BeginPlay()
{
	Super::BeginPlay();
}

void AObjectManagerComponent::Init(TArray<ATile*> tiles)
{
	mTiles = tiles;
}

void AObjectManagerComponent::Tick(float DeltaSeconds)
{
	for (APlantableObject* object : mObjects)
	{
#ifdef DEBUG_RENDER //TODO.PKH: make this changeable in runtime instead!
		DebugRenderObject(object);
#endif

		for (const TPair<ENeighborLocationType, APlantableObject*>& neighbor : object->GetNeighbors())
		{
			for (UObjectInteraction* interaction : mObjectInteractions)
			{
				if (interaction != nullptr)
				{
					const bool isObjectInteraction = ((object->GetObjectType() == interaction->mTypeA && neighbor.Value->GetObjectType() == interaction->mTypeB) || object->GetObjectType() == interaction->mTypeB && neighbor.Value->GetObjectType() == interaction->mTypeA);

					if (isObjectInteraction && interaction->mInteractionResult != nullptr)
					{
						if (interaction->mInteractionResult->mAnimation != nullptr)
						{
							//TODO.PKH: play animation through bps
						}
						if (interaction->mInteractionResult->mSound != nullptr)
						{
							UGameplayStatics::PlaySoundAtLocation(this, interaction->mInteractionResult->mSound, object->GetActorLocation());
						}
						if (interaction->mInteractionResult->mParticleEffect != nullptr)
						{
							UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), interaction->mInteractionResult->mParticleEffect, object->GetActorLocation());
						}
					}
				}
			}
		}
	}
}

void AObjectManagerComponent::UpdateCurrentObject(uint8 objectIndex)
{
	mObjectIndex = objectIndex;
}

const TMap<ENeighborLocationType, APlantableObject*> AObjectManagerComponent::FindNeighborsForObject(APlantableObject* spawnedObject) const
{
	TMap<ENeighborLocationType, TTuple<APlantableObject*, float>> potentialNeighbors;

	//Find potential neighbors
	for (APlantableObject* objectToCheckWith : mObjects)
	{
		if (spawnedObject == objectToCheckWith)
			continue;

		const float distance = FVector::Distance(spawnedObject->GetActorLocation(), objectToCheckWith->GetActorLocation());
		const FVector direction = spawnedObject->GetActorLocation() - objectToCheckWith->GetActorLocation();

		GatherObjectIfIsNeighbor(potentialNeighbors, objectToCheckWith, direction, distance);
	}

	const TMap<ENeighborLocationType, APlantableObject*>& spawnedObjectsNeighbors = spawnedObject->GetNeighbors();
	TMap<ENeighborLocationType, APlantableObject*> neighbors;

	//Check which potential neighbors should become neighbors.
	for (TPair<ENeighborLocationType, TTuple<APlantableObject*, float>>& potentialNeighborData : potentialNeighbors)
	{
		const ENeighborLocationType closeObjectLocationType = potentialNeighborData.Key;
		APlantableObject* closeObject = potentialNeighborData.Value.Key;
		
		if (spawnedObjectsNeighbors.Contains(closeObjectLocationType))
		{
			//..If has neighbor at same location type, check that this one is closer.
			if (const APlantableObject* const currentObjectToTheLeft = spawnedObjectsNeighbors.FindRef(ENeighborLocationType::Right))
			{
				const float distanceToCurrentLeftObject = FVector::Distance(spawnedObject->GetActorLocation(), currentObjectToTheLeft->GetActorLocation());
				const float distanceToCloseObject = potentialNeighborData.Value.Value;

				if (distanceToCloseObject < distanceToCurrentLeftObject)
				{
					neighbors.Add(closeObjectLocationType, closeObject);
				}
			}
		}
		else
		{
			//..If a neighbor at this location type doesn't exist, just add it.
			neighbors.Add(closeObjectLocationType, closeObject);
		}
	}

	return neighbors;
}

void AObjectManagerComponent::GatherObjectIfIsNeighbor(TMap<ENeighborLocationType, TTuple<APlantableObject*, float>>& objects, APlantableObject* objectToCheckWith, const FVector& objectsDirection, const float distanceToObject) const
{
	const ENeighborLocationType INVALID_LOCATIONTYPE = static_cast<ENeighborLocationType>(-1);
	ENeighborLocationType closestLocationType = INVALID_LOCATIONTYPE;
	float biggestDotResult = -BIG_FLOAT;

	for (const ENeighborLocationType& locationType : { ENeighborLocationType::Left, ENeighborLocationType::Right, ENeighborLocationType::Up, ENeighborLocationType::Down })
	{
		const FVector targetDirection = GetDirectionFromLocationType(locationType);
		const float dotResult = FVector::DotProduct(objectsDirection, targetDirection);

		if (dotResult > 0.f && dotResult > biggestDotResult)
		{
			closestLocationType = locationType;
			biggestDotResult = dotResult;
		}
	}

	if (closestLocationType != INVALID_LOCATIONTYPE)
	{
		const float tileSize = 110.f; //TODO.PKH: calculate this instead
		if (objects.Contains(closestLocationType))
		{
			const TTuple<APlantableObject*, float> oldLeft = objects.FindRef(closestLocationType);
			if (distanceToObject < oldLeft.Value)
			{
				objects[closestLocationType] = MakeTuple(objectToCheckWith, distanceToObject);
			}
		}
		else if (distanceToObject < tileSize)
		{
			objects.Add(closestLocationType, MakeTuple(objectToCheckWith, distanceToObject));
		}
	}
}

void AObjectManagerComponent::DebugRenderObject(APlantableObject* objectToRender) const
{
	if (GEngine)
	{
		const TMap<ENeighborLocationType, APlantableObject*> neighbors = objectToRender->GetNeighbors();

		FString upText = "Up: -\n";
		FString downText = "Down: -\n";
		FString leftText = "Left: -\n";
		FString rightText = "Right: -\n";

		FColor colorToUse = FColor::Red;

		if (neighbors.Contains(ENeighborLocationType::Up))
		{
			upText = "Up: " + neighbors[ENeighborLocationType::Up]->GetName() + "\n";
			colorToUse = FColor::Green;
		}
		if (neighbors.Contains(ENeighborLocationType::Down))
		{
			downText = "Down: " + neighbors[ENeighborLocationType::Down]->GetName() + "\n";
			colorToUse = FColor::Green;
		}
		if (neighbors.Contains(ENeighborLocationType::Left))
		{
			leftText = "Left: " + neighbors[ENeighborLocationType::Left]->GetName() + "\n";
			colorToUse = FColor::Green;
		}
		if (neighbors.Contains(ENeighborLocationType::Right))
		{
			rightText = "Right: " + neighbors[ENeighborLocationType::Right]->GetName() + "\n";
			colorToUse = FColor::Green;
		}

		const FString neighborText = "Neighbors:\n" + upText + downText + leftText + rightText;
		DrawDebugString(GetWorld(), objectToRender->GetActorLocation() + (FVector::UpVector * 5.f), neighborText, NULL, colorToUse);
	}
}

FVector AObjectManagerComponent::GetDirectionFromLocationType(ENeighborLocationType locationType) const
{
	if (locationType == ENeighborLocationType::Right)
		return FVector::LeftVector;
	else if (locationType == ENeighborLocationType::Left)
		return -FVector::LeftVector;
	else if (locationType == ENeighborLocationType::Up)
		return -FVector::ForwardVector;
	else //if (originalType == ENeighborLocationType::Down)
		return FVector::ForwardVector;
}

void AObjectManagerComponent::SpawnObject()
{
	if (!mObjectInventory.IsValidIndex(mObjectIndex))
		return;

	FHitResult hitResult;
	GetWorld()->GetFirstPlayerController()->GetHitResultUnderCursor(ECollisionChannel::ECC_WorldStatic, false, hitResult);

	if (hitResult.GetActor() != nullptr)
	{
		ATile* closestTile = nullptr;
		float closestDistance = BIG_FLOAT;

		//Find closest tile
		for (ATile* tile : mTiles)
		{
			const FVector actorLocation = tile->GetActorLocation();
			const float distance = FVector::Distance(actorLocation, hitResult.Location);

			if (distance < closestDistance)
			{
				closestDistance = distance;
				closestTile = tile;
			}
		}

		if (closestTile != nullptr)
		{
			FActorSpawnParameters spawnInfo;

			//Spawn new object
			if (APlantableObject* spawnedObject = GetWorld()->SpawnActor<APlantableObject>(mObjectInventory[mObjectIndex], closestTile->GetActorLocation(), { 0.0f, 0.0f, 0.0f }, spawnInfo))
			{
				mObjects.Add(spawnedObject);

				//Find Neighbors for newly spawned object
				const TMap<ENeighborLocationType, APlantableObject*> newNeighbors = FindNeighborsForObject(spawnedObject);

				//Also add the the newly spawned object as a neighbour to its neighbor
				for (const TPair<ENeighborLocationType, APlantableObject*>& neighbor : newNeighbors)
				{
					neighbor.Value->SetNeighbor(spawnedObject, APlantableObject::GetOppositeLocationType(neighbor.Key));
				}

				spawnedObject->OnSpawn(closestTile, newNeighbors);
			}
		}
	}
}