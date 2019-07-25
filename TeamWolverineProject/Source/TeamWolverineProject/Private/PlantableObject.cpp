// Fill out your copyright notice in the Description page of Project Settings.
#include "PlantableObject.h"
#include "Tile.h"
#include "Components/StaticMeshComponent.h"

APlantableObject::APlantableObject()
	: mObjectType(EPlantableObjectType::Plant)
	, mCurrentGrowingStage(EGrowingStage::Sprout)
	, mTimeUntilNextGrowingStage(60.f)
	, mTimeSpentInCurrentStage(0.f)
{
	PrimaryActorTick.bCanEverTick = true;
}

void APlantableObject::BeginPlay()
{
	Super::BeginPlay();

	SetMeshToMatchGrowingState();
}

void APlantableObject::SetMeshToMatchGrowingState()
{
	if (UStaticMeshComponent* meshComponent = FindComponentByClass<UStaticMeshComponent>())
	{
		if (mPlantableMeshes.Contains(mCurrentGrowingStage))
		{
			meshComponent->SetStaticMesh(mPlantableMeshes[mCurrentGrowingStage]);
		}
	}
}

void APlantableObject::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	mTimeSpentInCurrentStage += DeltaTime;

	if (mTimeSpentInCurrentStage >= mTimeUntilNextGrowingStage)
	{
		Grow();
		mTimeSpentInCurrentStage = 0.f;
	}
}

bool APlantableObject::HasInteractedWithNeighborBefore(ENeighborLocationType neighborLocationType) const
{
	return mNeighborsWeHaveHadInteractionWith.Contains(neighborLocationType);
}

bool APlantableObject::HasInteractedWithCurrentTileBefore() const
{
	return mCurrentTile->HasBeenInteractedWith();
}

ENeighborLocationType APlantableObject::GetOppositeLocationType(ENeighborLocationType originalType)
{
	if (originalType == ENeighborLocationType::Right)
		return ENeighborLocationType::Left;
	else if (originalType == ENeighborLocationType::Left)
		return ENeighborLocationType::Right;
	else if (originalType == ENeighborLocationType::Up)
		return ENeighborLocationType::Down;
	else //if (originalType == ENeighborLocationType::Down)
		return ENeighborLocationType::Up;
}

void APlantableObject::OnSpawn(ATile* closestTile, const TMap<ENeighborLocationType, APlantableObject*>& neighbors)
{
	mCurrentTile = closestTile;
	mNeighbors = neighbors;
}

void APlantableObject::SetNeighbor(APlantableObject* newNeighbor, ENeighborLocationType locationType)
{
	if (mNeighbors.Contains(locationType))
	{
		mNeighbors[locationType] = newNeighbor;
	}
	else
	{
		mNeighbors.Add(locationType, newNeighbor);
	}
}

void APlantableObject::Grow()
{
	uint8 nextStageAsInt = static_cast<uint8>(mCurrentGrowingStage) + 1;
	const uint8 maxEnumValueAsInt = static_cast<uint8>(EGrowingStage::AMOUNT) - 1;

	if (nextStageAsInt > maxEnumValueAsInt)
		nextStageAsInt = 0;

	mCurrentGrowingStage = static_cast<EGrowingStage>(nextStageAsInt);

	SetMeshToMatchGrowingState();

	//play grow VFX
}

void APlantableObject::OnInteractWithNeighbor(ENeighborLocationType locationTypeForNeighbor)
{
	mNeighborsWeHaveHadInteractionWith.Add(locationTypeForNeighbor);
}

void APlantableObject::OnInteractWithTile()
{
	mCurrentTile->OnInteractWithObjectOnTile();
}

ETileType APlantableObject::GetTileTypeForCurrentTile() const
{
	return mCurrentTile->GetTileType();
}

