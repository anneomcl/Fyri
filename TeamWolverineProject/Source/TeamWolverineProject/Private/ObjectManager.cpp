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

AObjectManagerComponent::AObjectManagerComponent()
	:mObjectIndex(0)
{
	
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

void AObjectManagerComponent::UpdateCurrentObject(uint8 objectIndex)
{
	mObjectIndex = objectIndex;
}

void AObjectManagerComponent::SpawnObject()
{
	if (!mObjectInventory.IsValidIndex(mObjectIndex))
		return;

	FHitResult hit;
	GetWorld()->GetFirstPlayerController()->GetHitResultUnderCursor(ECollisionChannel::ECC_WorldStatic, false, hit);

	if (hit.GetActor() != nullptr)
	{
		ATile* closestTile = nullptr;
		float closestDistance = 99999999.f;

		for (ATile* tile : mTiles)
		{
			const FVector actorLocation = tile->GetActorLocation();
			const float distance = FVector::Distance(actorLocation, hit.Location);

			if (distance < closestDistance)
			{
				closestDistance = distance;
				closestTile = tile;
			}
		}

		if (closestTile != nullptr && !mUsedTiles.Contains(closestTile))
		{
			TSubclassOf<APlantableObject> plantableObject = mObjectInventory[mObjectIndex];
			FActorSpawnParameters spawnInfo;

			if (APlantableObject* spawnedObject = GetWorld()->SpawnActor<APlantableObject>(plantableObject, closestTile->GetActorLocation(), { 0.0f, 0.0f, 0.0f }, spawnInfo))
			{
					mUsedTiles.Add(closestTile);
					mObjects.Add(spawnedObject);
					spawnedObject->OnSpawn(closestTile);
			}

			//todo: calculate neighbours
		}
	}
}