// Fill out your copyright notice in the Description page of Project Settings.

#include "Tile.h"
#include "Engine\Classes\Materials\MaterialInterface.h"
#include "Engine\Classes\Materials\MaterialInstanceDynamic.h"
#include "Engine\Classes\Engine\EngineTypes.h"
#include "Engine\Classes\Components\StaticMeshComponent.h"

// Sets default values
ATile::ATile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ATile::BeginPlay()
{
	Super::BeginPlay();

	if (UMeshComponent* mesh = FindComponentByClass<UMeshComponent>())
	{
		if (UMaterialInterface* material = mesh->GetMaterial(0))
		{
			if (UMaterialInstanceDynamic* materialInstance = mesh->CreateDynamicMaterialInstance(0, material))
			{
				materialInstance->SetVectorParameterValue("_BodyColor", mColor);
			}
		}
	}
}

// Called every frame
void ATile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

