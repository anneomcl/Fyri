// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PlantableObject.generated.h"
class ATile;

UENUM()
enum class EObjectType
{
	Plant,
	Food,
	Tree
};

enum class ENeighborLocationType 
{ 
	Left, 
	Right, 
	Up, 
	Down 
};

UCLASS()
class TEAMWOLVERINEPROJECT_API APlantableObject : public AActor
{
	GENERATED_BODY()
	public:	
		APlantableObject();

		virtual void Tick(float DeltaTime) override;

		void OnSpawn(ATile* closestTile, const TMap<ENeighborLocationType, APlantableObject*>& neighbors);
		void SetNeighbor(APlantableObject* newNeighbor, ENeighborLocationType locationType);

		EObjectType GetObjectType() const { return mObjectType; }
		const TMap<ENeighborLocationType, APlantableObject*>& GetNeighbors() { return mNeighbors; }
		static ENeighborLocationType GetOppositeLocationType(ENeighborLocationType originalType);

	protected:
		virtual void BeginPlay() override;

	private:
		TMap<ENeighborLocationType, APlantableObject*> mNeighbors;
		ATile* mCurrentTile;

		UPROPERTY(EditAnywhere, meta=(DisplayName = "Object Type"))
		EObjectType mObjectType;
};
