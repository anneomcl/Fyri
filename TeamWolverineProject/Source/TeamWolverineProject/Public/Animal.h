// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "Engine/TargetPoint.h"
#include "Animation/AnimInstance.h"
#include "Animal.generated.h"

UENUM(BlueprintType)
enum class EAnimalState : uint8
{
	Spawn,
	Traverse,
	Idle,
	Exit,
	Interact
};

UCLASS()
class TEAMWOLVERINEPROJECT_API AAnimal : public AAIController
{
	GENERATED_BODY()

public:
	void BeginPlay() override;
	virtual void Tick(float DeltaSeconds) override;

	virtual void OnMoveCompleted(FAIRequestID RequestID, const FPathFollowingResult& Result) override;

	UPROPERTY(BlueprintReadWrite)
	EAnimalState mCurrentState;

	UPROPERTY(BlueprintReadWrite)
	uint8 mTraversalCount;

	UPROPERTY(BlueprintReadWrite)
	uint8 mMaxTraversalCount;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	UAnimInstance* mAnimation;

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
