// Fill out your copyright notice in the Description page of Project Settings.

#include "Tile.h"
#include "Engine\Classes\Materials\MaterialInterface.h"
#include "Engine\Classes\Materials\MaterialInstanceDynamic.h"
#include "Engine\Classes\Engine\EngineTypes.h"
#include "Engine\Classes\Components\StaticMeshComponent.h"

ATile::ATile()
	: mTileType(ETileType::Grass)
	, mIsTraversable(true)
	, mHasBeenInteractedWith(false)
	, mIsUsed(false)
{
	PrimaryActorTick.bCanEverTick = true;
}

void ATile::BeginPlay()
{
	Super::BeginPlay();
}

void ATile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ATile::OnInteractWithObjectOnTile()
{
	mHasBeenInteractedWith = true;
}

void ATile::OnObjectSpawnOnTile()
{
	mIsUsed = true;
}

