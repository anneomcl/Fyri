// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine\Classes\Engine\DataAsset.h"
#include "PlantableObject.h"
#include "Engine\Classes\Components\ActorComponent.h"
#include "GameFramework\Actor.h"
#include "ObjectManager.generated.h"

class ATile;
class APlantableObject;
class UAnimInstance;
class UParticleSystem;

UCLASS()
class UInteractionResult : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere)
	UAnimInstance* mAnimation;

	UPROPERTY(EditAnywhere)
	USoundBase* mSound;

	UPROPERTY(EditAnywhere)
	UParticleSystem* mParticleEffect;
};

UCLASS()
class UObjectInteraction : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere)
	EObjectType mTypeA;

	UPROPERTY(EditAnywhere)
	EObjectType mTypeB;

	UPROPERTY(EditAnywhere)
	UInteractionResult* mInteractionResult;
};

UCLASS(meta=(BlueprintSpawnableComponent))
class TEAMWOLVERINEPROJECT_API AObjectManagerComponent : public AActor
{
	GENERATED_BODY()
public:
	AObjectManagerComponent();
	~AObjectManagerComponent();

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaSeconds) override;

	UFUNCTION(BlueprintCallable)
	void Init(TArray<ATile*> tiles);

	UFUNCTION(BlueprintCallable)
	void SpawnObject();

	UFUNCTION(BlueprintCallable)
	void UpdateCurrentObject(uint8 objectIndex);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(DisplayName = "Object Interactions"))
	TArray<UObjectInteraction*> mObjectInteractions;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(DisplayName = "Object Inventory"))
	TArray<TSubclassOf<APlantableObject>> mObjectInventory;

private:
	void GatherObjectIfIsNeighbor(TMap<ENeighborLocationType, TTuple<APlantableObject*, float>>& objects, APlantableObject* objectToCheckWith, const FVector& objectsDirection, const float distanceToObject) const;
	void DebugRenderObject(APlantableObject* objectToRender) const;

	const TMap<ENeighborLocationType, APlantableObject*> FindNeighborsForObject(APlantableObject* spawnedObject) const;
	FVector GetDirectionFromLocationType(ENeighborLocationType locationType) const;

	TArray<ATile*> mTiles;
	TArray<APlantableObject*> mObjects;

	uint8 mObjectIndex;
};
