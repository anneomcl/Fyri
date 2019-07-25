// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine\Classes\Engine\DataAsset.h"
#include "PlantableObject.h"
#include "Engine\Classes\Components\ActorComponent.h"
#include "GameFramework\Actor.h"
#include "GameData.h"
#include "AnimalController.h"
#include "AnimalCharacter.h"
#include "ObjectManager.generated.h"

class ATile;
class APlantableObject;
class UAnimInstance;
class UParticleSystem;

USTRUCT(BlueprintType)
struct FSpawnTierProbabilities
{
	GENERATED_BODY()

public:
	FSpawnTierProbabilities();

	UPROPERTY(EditAnywhere, meta = (DisplayName = "Object Type"))
	EPlantableObjectType mObjectType;

	UPROPERTY(EditAnywhere, meta = (DisplayName = "Common Probability"))
	uint8 mCommonProbability;

	UPROPERTY(EditAnywhere, meta = (DisplayName = "Fancy Probability"))
	uint8 mFancyProbability;

	UPROPERTY(EditAnywhere, meta = (DisplayName = "Mythical Probability"))
	uint8 mMythicalProbability;
};

UCLASS()
class UInteractionResult : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta = (DisplayName = "Animation"))
	UAnimInstance* mAnimation;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta = (DisplayName = "Sound"))
	USoundBase* mSound;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta = (DisplayName = "Particle Effect"))
	UParticleSystem* mParticleEffect;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta = (DisplayName = "Animal"))
	TSubclassOf<AAnimalCharacter> mAnimal;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta = (DisplayName = "Should Change Spawn Probabilities"))
	bool mShouldChangeSpawnProbabilities;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta = (DisplayName = "Spawn Probabilities", EditCondition = "mShouldChangeSpawnProbabilities"))
	FSpawnTierProbabilities mSpawnProbabilities;
};

UCLASS()
class UObjectInteraction : public UDataAsset
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, meta=(DisplayName = "Type A"))
	EPlantableObjectType mTypeA;

	UPROPERTY(EditAnywhere, meta = (DisplayName = "Object Type"))
	EObjectType mObjectType;

	UPROPERTY(EditAnywhere, meta = (DisplayName = "Plantable Object Type"))
	EPlantableObjectType mPlantableObjectType;

	UPROPERTY(EditAnywhere, meta = (DisplayName = "Terrain Type"))
	ETileType mTerrainType;

	UPROPERTY(EditAnywhere, meta = (DisplayName = "Required Amount"))
	uint8 mRequiredAmount;

	UPROPERTY(EditAnywhere, meta = (DisplayName = "Interaction Result"))
	UInteractionResult* mInteractionResult;

	UPROPERTY(EditAnywhere, meta = (DisplayName = "Required Amount Reached Result"))
	UInteractionResult* mRequiredAmountReachedResult;

	UPROPERTY(EditAnywhere, meta = (DisplayName = "Interaction Name"))
	FName mInteractionName;

#if WITH_EDITOR
	virtual bool CanEditChange(const UProperty* InProperty) const override;
#endif
};

USTRUCT()
struct FGameSpawnProbabilities
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, meta = (DisplayName = "Plant Probabilities"))
	FSpawnTierProbabilities mPlantProbabilities;

	UPROPERTY(EditAnywhere, meta = (DisplayName = "Tree Probabilities"))
	FSpawnTierProbabilities mTreeProbabilities;

	UPROPERTY(EditAnywhere, meta = (DisplayName = "Edible Probabilities"))
	FSpawnTierProbabilities mEdibleProbabilities;
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


	UFUNCTION(BlueprintImplementableEvent, Category = "Interaction")
	void OnInteractionStart(UInteractionResult* interactionResult, const FVector& interactionLocation, const FString& interactionName);
	
	UFUNCTION(BlueprintImplementableEvent, Category = "Interaction")
	void OnInteractionReachedRequiredAmount(UInteractionResult* requiredAmountReachedResult, const FVector& interactionLocation, const FString& interactionName);

	UFUNCTION(BlueprintImplementableEvent, Category = "Spawn")
	void OnObjectSpawned(APlantableObject* spawnedObject);

	UFUNCTION(BlueprintImplementableEvent, Category = "Spawn")
	void OnAnimalSpawned(ACharacter* spawnedObject);

	UFUNCTION(BlueprintCallable)
	void Init(TArray<ATile*> tiles);

	UFUNCTION(BlueprintCallable)
	void SpawnAnimal(TSubclassOf<AAnimalCharacter> animal);

	UFUNCTION(BlueprintCallable, Category = "Spawn")
	void SpawnObject();

	UFUNCTION(BlueprintCallable)
	void UpdateCurrentlySelectedPlantableObject(EPlantableObjectType objectType);

	UFUNCTION(BlueprintCallable, Category = "Spawn Probability")
	void ChangeSpawnProbability(FSpawnTierProbabilities newSpawnProbabilities);

	UFUNCTION(BlueprintCallable, Category = "Spawn Probability", meta = (Tooltip = "Will check if has reached the required amount on this interaction"))
	bool HasReachedRequiredInteractionAmount(UObjectInteraction* interaction) const;

	UPROPERTY(BlueprintReadOnly, meta = (DisplayName = "Discovered Objects"))
	TSet<FString> mDiscoveredTypes;

	UPROPERTY(EditAnywhere, meta = (DisplayName = "Journal Page Mappings"))
	TMap<FString, UTexture2D*> mJournalPageMappings;

private:
	void GatherObjectIfIsNeighbor(TMap<ENeighborLocationType, TTuple<APlantableObject*, float>>& objects, APlantableObject* objectToCheckWith, const FVector& objectsDirection, const float distanceToObject) const;
	void DebugRenderObject(APlantableObject* objectToRender) const;

	const TMap<ENeighborLocationType, APlantableObject*> FindNeighborsForObject(APlantableObject* spawnedObject) const;
	FVector GetDirectionFromLocationType(ENeighborLocationType locationType) const;
	TSubclassOf<APlantableObject> GetObject() const;

	UPROPERTY(EditAnywhere, meta = (DisplayName = "Object Interactions"))
	TArray<UObjectInteraction*> mObjectInteractions;

	UPROPERTY(EditAnywhere, meta = (DisplayName = "Object Inventory"))
	UGameObjectInventory* mObjectInventory;

	UPROPERTY(EditAnywhere, meta = (DisplayName = "Game Spawn Probabilities"))
	FGameSpawnProbabilities mSpawnProbabilities;

	UPROPERTY(EditAnywhere, meta = (DisplayName = "Animal Inventory"))
	TArray<TSubclassOf<AAnimalCharacter>> mAnimalInventory;

	TMap<FString, uint8> mPlantedAmounts;

	TArray<ATile*> mTiles;
	TArray<APlantableObject*> mObjects;
	TArray<AAnimalCharacter*> mAnimals;

	EPlantableObjectType mCurrentlySelectedPlantableObject;
};
