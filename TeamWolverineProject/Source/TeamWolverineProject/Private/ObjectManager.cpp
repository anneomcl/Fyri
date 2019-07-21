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

UObjectManagerComponent::UObjectManagerComponent()
{
	mObjectIndex = 0;
}

UObjectManagerComponent::~UObjectManagerComponent()
{
}

void UObjectManagerComponent::BeginPlay()
{
	Super::BeginPlay();
}

void UObjectManagerComponent::Init(TArray<ATile*> tiles)
{
	mTiles = tiles;
}

void UObjectManagerComponent::UpdateCurrentObject(int objectIndex)
{
	mObjectIndex = objectIndex;
}

void UObjectManagerComponent::SpawnObject()
{
	TSubclassOf<APlantableObject> PlantableObject;

	//TODO: Pick the right object from inventory
	if (UBlueprint* blueprint = Cast<UBlueprint>(mObjectInventory[mObjectIndex]))
	{
		PlantableObject = blueprint->GeneratedClass;

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

			if (closestTile != nullptr)
			{
				FActorSpawnParameters SpawnInfo;
				if (APlantableObject* spawnedObject = GetWorld()->SpawnActor<APlantableObject>(PlantableObject, closestTile->GetActorLocation(), { 0.0f, 0.0f, 0.0f }, SpawnInfo))
				{
					mObjects.Add(spawnedObject);
					spawnedObject->OnSpawn(closestTile);

					//todo: calculate neighbours
				}
			}
		}
	}
}