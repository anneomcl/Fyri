// Fill out your copyright notice in the Description page of Project Settings.

#include "Animal.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/Actor.h"

void AAnimal::BeginPlay()
{
	Super::BeginPlay();

	mTraversalCount = 0;
	mMaxTraversalCount = 10;

	UGameplayStatics::GetAllActorsOfClass(this, ATargetPoint::StaticClass(), mWaypoints);

}

void AAnimal::Tick(float DeltaSeconds)
{
}

void AAnimal::OnSpawn()
{
	mCurrentState = EAnimalState::Spawn;
	OnTraverse();
}

void AAnimal::OnTraverse()
{
	mCurrentState = EAnimalState::Traverse;
	GoToRandomWaypoint();
}

// traversal transition
void AAnimal::OnMoveCompleted(FAIRequestID RequestID, const FPathFollowingResult& Result)
{
	OnIdle();
}

void AAnimal::OnIdle()
{
	// idle animation
	/*if (mAnimation != nullptr)
	{
		mAnimation->triggers
	}*/

	mCurrentState = EAnimalState::Idle;
	if (mTraversalCount >= mMaxTraversalCount)
	{
		OnExit();
	}
	else
	{
		OnTraverse();
	}
}

void AAnimal::OnExit()
{
	// go to exit waypoint
	// fade?
}

ATargetPoint* AAnimal::GetRandomWaypoint()
{
	if (mWaypoints.Num() > 0)
	{
		auto index = FMath::RandRange(0, mWaypoints.Num() - 1);
		return Cast<ATargetPoint>(mWaypoints[index]);
	}

	return nullptr;
}

void AAnimal::GoToRandomWaypoint()
{
	MoveToActor(GetRandomWaypoint());
}