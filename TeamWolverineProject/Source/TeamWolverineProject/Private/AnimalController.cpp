// Fill out your copyright notice in the Description page of Project Settings.

#include "AnimalController.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/Actor.h"
#include "AnimalCharacter.h"

void AAnimalController::BeginPlay()
{
	Super::BeginPlay();

	mTraversalCount = 0;

	UGameplayStatics::GetAllActorsOfClass(this, ATargetPoint::StaticClass(), mWaypoints);
}

void AAnimalController::Tick(float DeltaSeconds)
{
}

void AAnimalController::OnSpawn()
{
	mCurrentState = EAnimalState::Spawn;

	mCurrentTransition = EAnimalTransition::SpawnToTraverse;
	OnTraverse();
}

void AAnimalController::OnTraverse()
{
	mCurrentState = EAnimalState::Traverse;

	GoToRandomWaypoint();
}

// traversal transition
void AAnimalController::OnMoveCompleted(FAIRequestID RequestID, const FPathFollowingResult& Result)
{
	mTraversalCount++;
	mCurrentTransition = EAnimalTransition::TraverseToIdle;
	OnIdle();
}

void AAnimalController::OnIdle()
{
	mCurrentState = EAnimalState::Idle;

	if (mTraversalCount >= mMaxTraversalCount)
	{
		mCurrentTransition = EAnimalTransition::IdleToExit;
		OnExit();
	}
	else
	{
		mCurrentTransition = EAnimalTransition::IdleToTraverse;
		OnTraverse();
	}
}

void AAnimalController::OnExit()
{
	mCurrentState = EAnimalState::Exit;
}

ATargetPoint* AAnimalController::GetRandomWaypoint()
{
	if (mWaypoints.Num() > 0)
	{
		auto index = FMath::RandRange(0, mWaypoints.Num() - 1);
		return Cast<ATargetPoint>(mWaypoints[index]);
	}

	return nullptr;
}

void AAnimalController::GoToRandomWaypoint()
{
	MoveToActor(GetRandomWaypoint());
}