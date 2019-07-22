// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "Engine/TargetPoint.h"
#include "Animal.generated.h"

/**
 * 
 */
UCLASS()
class TEAMWOLVERINEPROJECT_API AAnimal : public AAIController
{
	GENERATED_BODY()

public:
	void BeginPlay() override;

private:
	UPROPERTY()
		TArray<AActor*> Waypoints;

	UFUNCTION()
		ATargetPoint* GetRandomWaypoint();

	UFUNCTION()
		void GoToRandomWaypoint();
};
