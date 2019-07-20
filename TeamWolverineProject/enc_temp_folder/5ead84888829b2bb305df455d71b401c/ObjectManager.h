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
class UParticleSystemComponent;

class UInteractionResult : public UDataAsset
{
	UAnimInstance* mAnimation;
	USoundBase* mSound;
	UParticleSystemComponent* mParticleEffect;
};

class UObjectInteraction : public UDataAsset
{
	EObjectType mTypeA;

	EObjectType mTypeB;

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

private:
	TArray<ATile*> mTiles;

	TArray<APlantableObject*> mObjects;

	TArray<UObjectInteraction*> mObjectInteractions;
};
