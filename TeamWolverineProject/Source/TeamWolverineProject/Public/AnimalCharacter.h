// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "GameData.h"
#include "AnimalCharacter.generated.h"

UCLASS()
class TEAMWOLVERINEPROJECT_API AAnimalCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AAnimalCharacter();

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	UParticleSystem* mParticleEffect;


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(EditAnywhere, meta = (DisplayName = "Spawn Tier"))
	ESpawnTier mSpawnTier;

	UPROPERTY(EditAnywhere, meta = (DisplayName = "Journal Index"))
	int32 mIndex;

private:
	uint8 mStoppedTimer;

};
