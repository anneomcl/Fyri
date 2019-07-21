// Fill out your copyright notice in the Description page of Project Settings.


#include "PlantableObject.h"

APlantableObject::APlantableObject()
{
	PrimaryActorTick.bCanEverTick = true;
}

void APlantableObject::BeginPlay()
{
	Super::BeginPlay();
}

void APlantableObject::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
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

