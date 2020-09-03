// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseStation.h"
#include "Target.h"

// Sets default values
ABaseStation::ABaseStation()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	BeamParticle = CreateDefaultSubobject<UParticleSystemComponent>(FName(TEXT("BeamParticle")));

	for (int i = 0; i < 40; i++)
	{
		BeamVectorsArray.Add(FVector(1162.21228, 243.97435 - i * 50, 199.340195));
	}; //Fill BeamVectors Arrays with 40 (Hardcoded and Arbitrary) FVectors;

}

// Called when the game starts or when spawned
void ABaseStation::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABaseStation::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABaseStation::SpawnBeamTargets(FVector AntennaPosition, TArray<FVector> VectorsArray)
{
	if (ToSpawn) {
		UWorld* world = GetWorld();
		if (world) {
			FActorSpawnParameters spawnParameters;
			spawnParameters.Owner = this;
			FRotator rotator;
			for (int i = 0; i < VectorsArray.Num(); i++) {
				world->SpawnActor<ATarget>(ToSpawn, AntennaPosition + VectorsArray[i], rotator, spawnParameters);
			}
		}
	}
}

// Receives the Antenna GetWorldLocation [Using Blueprint] and the Array of Beams locations and Spawn Visible Actors in the Scenario.
void ABaseStation::SpawnBeamAtTarget(FVector AntennaPosition, TArray<FVector> VectorsArray)
{
	if (BeamIndex < VectorsArray.Num()) {
		BeamParticle->SetBeamSourcePoint(0, AntennaPosition, 0);
		BeamParticle->SetBeamTargetPoint(0, AntennaPosition + VectorsArray[BeamIndex], 0);
		BeamIndex++;
	}
	else { BeamIndex = 0; }
}
