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

UENUM()
enum class SpawnTier
{
	Common,
	Fancy,
	Mythical
};

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

UCLASS()
class USpawnTierProbabilities : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere)
	uint8 mCommonProbability;

	UPROPERTY(EditAnywhere)
	uint8 mFancyProbability;

	UPROPERTY(EditAnywhere)
	uint8 mMythicalProbability;
};

UCLASS()
class UGameSpawnProbabilities : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere)
	USpawnTierProbabilities* mPlantProbabilities;

	UPROPERTY(EditAnywhere)
	USpawnTierProbabilities* mTreeProbabilities;

	UPROPERTY(EditAnywhere)
	USpawnTierProbabilities* mEdibleProbabilities;

	UPROPERTY(EditAnywhere)
	USpawnTierProbabilities* mAnimalProbabilities;
};

UCLASS()
class UPlantableInventory : public UDataAsset
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (DisplayName = "Common Plantable Inventory"))
		TArray<TSubclassOf<APlantableObject>> mCommonObjectInventory;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (DisplayName = "Fancy Plantable Inventory"))
		TArray<TSubclassOf<APlantableObject>> mFancyObjectInventory;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (DisplayName = "Mythical Plantable Inventory"))
		TArray<TSubclassOf<APlantableObject>> mMythicalObjectInventory;
};

UCLASS()
class UGameObjectInventory : public UDataAsset
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (DisplayName = "Plant Inventory"))
		UPlantableInventory* mPlantInventory;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (DisplayName = "Tree Inventory"))
		UPlantableInventory* mTreeInventory;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (DisplayName = "Edible Inventory"))
		UPlantableInventory* mEdibleInventory;
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

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (DisplayName = "Object Inventory"))
	UGameObjectInventory* mObjectInventory;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (DisplayName = "Game Spawn Probabilities"))
	UGameSpawnProbabilities* mSpawnProbabilities;

private:
	void GatherObjectIfIsNeighbor(TMap<ENeighborLocationType, TTuple<APlantableObject*, float>>& objects, APlantableObject* objectToCheckWith, const FVector& objectsDirection, const float distanceToObject) const;
	void DebugRenderObject(APlantableObject* objectToRender) const;

	const TMap<ENeighborLocationType, APlantableObject*> FindNeighborsForObject(APlantableObject* spawnedObject) const;
	FVector GetDirectionFromLocationType(ENeighborLocationType locationType) const;
	TSubclassOf<APlantableObject> GetObject() const;

	TArray<ATile*> mTiles;
	
	TSet<ATile*> mUsedTiles;

	TArray<APlantableObject*> mObjects;

	uint8 mObjectIndex;
};
