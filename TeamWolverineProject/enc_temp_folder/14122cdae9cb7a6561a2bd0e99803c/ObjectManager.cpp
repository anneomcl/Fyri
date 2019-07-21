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


UObjectManagerComponent::UObjectManagerComponent()
{
	if (GetWorld() != nullptr)
	{
		for (TActorIterator<ATile> ActorItr(GetWorld()); ActorItr; ++ActorItr)
		{
			mTiles.Add(*ActorItr);
		}
	}
}

UObjectManagerComponent::~UObjectManagerComponent()
{
}

void UObjectManagerComponent::BeginPlay()
{
	Super::BeginPlay();
	SetupInput();
}

void UObjectManagerComponent::SetupInput()
{
	AActor* owner = GetOwner();
	if (owner != nullptr)
	{
		if (UWorld* world = GetWorld())
		{
			APlayerController* playerController = world->GetFirstPlayerController();

			owner->EnableInput(playerController);
			
			if (owner->InputComponent != nullptr)
			{
				owner->InputComponent->BindAction("LeftClick", IE_Released, this, &UObjectManagerComponent::SpawnObject);
			}
		}
	}
}

void UObjectManagerComponent::SpawnObject()
{
	TSubclassOf<APlantableObject> PlantableObject;
	if (UBlueprint* blueprint = Cast<UBlueprint>(mObjectInventory[0]))
	{
		PlantableObject = blueprint->GeneratedClass;
		FVector mouseLocationWorld;
		FVector mouseDirecionWorld;
		GetWorld()->GetFirstPlayerController()->DeprojectMousePositionToWorld(mouseLocationWorld, mouseDirecionWorld);

		ATile* closestTile = nullptr;
		float closestDistance = 99999999.f;

		for (ATile* a : mTiles)
		{
			const float distance = FVector::Distance(a->GetActorLocation(), mouseLocationWorld);

			if (distance < closestDistance)
			{
				closestDistance = distance;
				closestTile = a;
			}
		}

		if (closestTile != nullptr)
		{
			FActorSpawnParameters SpawnInfo;
			if (APlantableObject* spawnedObject = GetWorld()->SpawnActor<APlantableObject>(PlantableObject, closestTile->GetActorLocation(), { 0.0f, 0.0f, 0.0f }, SpawnInfo))
			{
				spawnedObject->OnSpawn(closestTile);

				mObjects.Add(spawnedObject);

				//todo: calculate neighbours
			}
		}
	}
}