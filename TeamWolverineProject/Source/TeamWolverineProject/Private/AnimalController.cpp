// Fill out your copyright notice in the Description page of Project Settings.

#include "AnimalController.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/Actor.h"
#include "AnimalCharacter.h"
#include "DrawDebugHelpers.h"
#include "GameFramework/CharacterMovementComponent.h"

#define DEBUG_RENDER

void AAnimalController::BeginPlay()
{
	Super::BeginPlay();

	mTraversalCount = 0;

	UGameplayStatics::GetAllActorsOfClass(this, ATargetPoint::StaticClass(), mWaypoints);
}

void AAnimalController::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
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

void AAnimalController::SetCurrentState(EAnimalState newState)
{
	mCurrentState = newState;
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
	ATargetPoint* wayPoint = GetRandomWaypoint();
	MoveToActor(wayPoint);

	if (AAnimalCharacter* character = Cast<AAnimalCharacter>(GetCharacter()))
	{
		if (UCharacterMovementComponent* movementComponent = Cast<UCharacterMovementComponent>(character->GetMovementComponent()))
		{
			movementComponent->bOrientRotationToMovement = true;
		}
	}

#ifdef DEBUG_RENDER
	DrawDebugString(GetWorld(), wayPoint->GetActorLocation(), "waypoint", NULL, FColor::Green, 20.f);
	DrawDebugSphere(GetWorld(), wayPoint->GetActorLocation(), 10.f, 6, FColor::Green, false, 20.f);
#endif
}