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

	UFUNCTION(BlueprintCallable)
	void SetCurrentState(EAnimalState newState);

	UFUNCTION(BlueprintCallable)
	void OnSpawn();

	UFUNCTION(BlueprintCallable)
	void OnTraverse();

	UFUNCTION(BlueprintCallable)
	void OnIdle();

	UFUNCTION(BlueprintCallable)
	void OnExit();

	UFUNCTION(BlueprintCallable)
	EAnimalState GetCurrentState() const { return mCurrentState; }

	UFUNCTION(BlueprintCallable)
	EAnimalTransition GetAnimalTransition() const { return mCurrentTransition; }

private:
	UFUNCTION(BlueprintCallable)
	void GoToRandomWaypoint();

	UFUNCTION()
	ATargetPoint* GetRandomWaypoint();

	UPROPERTY()
	TArray<AActor*> mWaypoints;

	UPROPERTY(EditAnywhere)
	EAnimalState mCurrentState;

	UPROPERTY(EditAnywhere)
	EAnimalTransition mCurrentTransition;

	UPROPERTY()
	uint8 mTraversalCount;

	UPROPERTY(EditAnywhere, meta = (DisplayName = "Max Traversals"))
	uint8 mMaxTraversalCount;

	float mTimeSpentInIdle;
};
