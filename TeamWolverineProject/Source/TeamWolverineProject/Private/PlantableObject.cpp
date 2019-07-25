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

bool APlantableObject::SetMeshToMatchGrowingState()
{
	if (UStaticMeshComponent* meshComponent = FindComponentByClass<UStaticMeshComponent>())
	{
		if (mPlantableMeshes.Contains(mCurrentGrowingStage) && mPlantableMeshes[mCurrentGrowingStage] != nullptr)
		{
			meshComponent->SetStaticMesh(mPlantableMeshes[mCurrentGrowingStage]);
			return true;
		}
	}

	return false;
}

void APlantableObject::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (mCurrentGrowingStage < EGrowingStage::MAX && mPlantableMeshes.Num() > 0)
	{
		mTimeSpentInCurrentStage += DeltaTime;

		if (mTimeSpentInCurrentStage >= mTimeUntilNextGrowingStage)
		{
			Grow();
			mTimeSpentInCurrentStage = 0.f;
		}
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
	bool succeededToGrow = false;
	while (!succeededToGrow)
	{
		const uint8 nextStageAsInt = static_cast<uint8>(mCurrentGrowingStage) + 1;
		const uint8 maxEnumValueAsInt = static_cast<uint8>(EGrowingStage::MAX) - 1;

		if (nextStageAsInt > maxEnumValueAsInt)
			return;

		mCurrentGrowingStage = static_cast<EGrowingStage>(nextStageAsInt);

		succeededToGrow = SetMeshToMatchGrowingState();

		//send Grow-event to BPs, for playing event
	}
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

