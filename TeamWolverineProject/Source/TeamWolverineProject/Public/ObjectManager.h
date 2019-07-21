// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine\Classes\Engine\DataAsset.h"
#include "PlantableObject.h"
#include "Engine\Classes\Components\ActorComponent.h"
#include "ObjectManager.generated.h"

class ATile;
class APlantableObject;
class UAnimInstance;
class UParticleSystem;

UCLASS()
class UInteractionResult : public UDataAsset
{
	GENERATED_BODY()

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

	UPROPERTY(EditAnywhere)
	EObjectType mTypeA;

	UPROPERTY(EditAnywhere)
	EObjectType mTypeB;

	UPROPERTY(EditAnywhere)
	UInteractionResult* mInteractionResult;
};

/**
 * 
 */
UCLASS(meta=(BlueprintSpawnableComponent))
class TEAMWOLVERINEPROJECT_API UObjectManagerComponent : public UActorComponent
{
	GENERATED_BODY()
public:
	UObjectManagerComponent();
	~UObjectManagerComponent();

	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable)
	void Init(TArray<ATile*> tiles);

	UFUNCTION(BlueprintCallable)
	void SpawnObject();

private:
	//UPROPERTY(EditAnywhere, meta = (DisplayName = "Tiles"))
	TArray<ATile*> mTiles;

	//UPROPERTY(EditAnywhere, meta = (DisplayName = "Objects"))
	TArray<APlantableObject*> mObjects;

	UPROPERTY(EditAnywhere, meta = (DisplayName = "Object Interactions"))
	TArray<UObjectInteraction*> mObjectInteractions;

	UPROPERTY(EditAnywhere, meta = (DisplayName = "Object Inventory"))
	TArray<UObject*> mObjectInventory;
};
