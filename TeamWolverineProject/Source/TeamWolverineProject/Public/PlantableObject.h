// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PlantableObject.generated.h"
class ATile;

UENUM()
enum class EObjectType
{
	Flower,
	Food,
	Tree
};

UCLASS()
class TEAMWOLVERINEPROJECT_API APlantableObject : public AActor
{
	GENERATED_BODY()
	public:	
		// Sets default values for this actor's properties
		APlantableObject();

		// Called every frame
		virtual void Tick(float DeltaTime) override;

		UFUNCTION(BlueprintCallable)
		void OnSpawn(ATile* closestTile);

	protected:
		// Called when the game starts or when spawned
		virtual void BeginPlay() override;

	private:
		TArray<APlantableObject*> mNeighbors;

		EObjectType mObjectType;

		ATile* mCurrentTile;
};
