// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameData.h"

#include "Tile.generated.h"

UCLASS()
class TEAMWOLVERINEPROJECT_API ATile : public AActor
{
	GENERATED_BODY()
	
public:	
	ATile();

	virtual void Tick(float DeltaTime) override;

	void OnInteractWithObjectOnTile();

	ETileType GetTileType() const { return mTileType; }
	bool HasBeenInteractedWith() const { return mHasBeenInteractedWith; }
	bool IsTraversable() const { return mIsTraversable; }

protected:
	virtual void BeginPlay() override;

private:	

	UPROPERTY(EditAnywhere, Meta = (DisplayName="Tile Type"))
	ETileType mTileType;

	bool mIsTraversable;
	bool mHasBeenInteractedWith;

};
