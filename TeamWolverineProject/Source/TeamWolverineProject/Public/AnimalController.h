// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "Engine/TargetPoint.h"
#include "Animation/AnimInstance.h"
#include "AnimalController.generated.h"


UENUM(BlueprintType)
enum class EAnimalState : uint8
{
	Spawn,
	Traverse,
	Idle,
	Exit,
	Kill,
	Interact
};

UENUM(BlueprintType)
enum class EAnimalTransition : uint8
{
	SpawnToTraverse,
	TraverseToIdle,
	IdleToTraverse,
	IdleToExit,
	Interact
};

UCLASS()
class TEAMWOLVERINEPROJECT_API AAnimalController : public AAIController
{
	GENERATED_BODY()

public:
	void BeginPlay() override;
	virtual void Tick(float DeltaSeconds) override;

	virtual void OnMoveCompleted(FAIRequestID RequestID, const FPathFollowingResult& Result) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EAnimalState mCurrentState;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EAnimalTransition mCurrentTransition;

	UPROPERTY()
	uint8 mTraversalCount;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (DisplayName = "Max Traversals"))
	uint8 mMaxTraversalCount;

	UFUNCTION(BlueprintCallable)
	void OnSpawn();

	UFUNCTION(BlueprintCallable)
	void OnTraverse();

	UFUNCTION(BlueprintCallable)
	void OnIdle();

	UFUNCTION(BlueprintCallable)
	void OnExit();

private:
	UPROPERTY()
		TArray<AActor*> mWaypoints;

	UFUNCTION()
		ATargetPoint* GetRandomWaypoint();

	UFUNCTION(BlueprintCallable)
		void GoToRandomWaypoint();
};
