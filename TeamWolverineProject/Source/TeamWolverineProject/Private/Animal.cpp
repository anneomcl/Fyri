// Fill out your copyright notice in the Description page of Project Settings.

#include "Animal.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/Actor.h"

void AAnimal::BeginPlay()
{
	Super::BeginPlay();

	UGameplayStatics::GetAllActorsOfClass(this, ATargetPoint::StaticClass(), Waypoints);

	GoToRandomWaypoint();
}

ATargetPoint* AAnimal::GetRandomWaypoint()
{
	auto index = FMath::RandRange(0, Waypoints.Num() - 1);
	return Cast<ATargetPoint>(Waypoints[index]);
}

void AAnimal::GoToRandomWaypoint()
{
	MoveToActor(GetRandomWaypoint());
}