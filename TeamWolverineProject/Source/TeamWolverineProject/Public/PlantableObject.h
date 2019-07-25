// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameData.h"

#include "PlantableObject.generated.h"

class ATile;

UCLASS()
class TEAMWOLVERINEPROJECT_API APlantableObject : public AActor
{
	GENERATED_BODY()
	public:	
		APlantableObject();

		virtual void Tick(float DeltaTime) override;

		void OnSpawn(ATile* closestTile, const TMap<ENeighborLocationType, APlantableObject*>& neighbors);
		void SetNeighbor(APlantableObject* newNeighbor, ENeighborLocationType locationType);
		void OnInteractWithNeighbor(ENeighborLocationType locationTypeForNeighbor);
		void OnInteractWithTile();

		ETileType GetTileTypeForCurrentTile() const;
		EPlantableObjectType GetObjectType() const { return mObjectType; }
		const TMap<ENeighborLocationType, APlantableObject*>& GetNeighbors() { return mNeighbors; }
		bool HasInteractedWithNeighborBefore(ENeighborLocationType neighborLocationType) const;
		bool HasInteractedWithCurrentTileBefore() const;

		static ENeighborLocationType GetOppositeLocationType(ENeighborLocationType originalType);

		UPROPERTY(EditAnywhere, meta = (DisplayName = "Name"))
		FString mName;

	protected:
		virtual void BeginPlay() override;

	private:
		TMap<ENeighborLocationType, APlantableObject*> mNeighbors;
		ATile* mCurrentTile;

		TArray<ENeighborLocationType> mNeighborsWeHaveHadInteractionWith;

		UPROPERTY(EditAnywhere, meta=(DisplayName = "Object Type"))
			EPlantableObjectType mObjectType;
};
