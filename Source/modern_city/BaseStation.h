// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Engine/World.h"
#include "ParticleHelper.h"
#include "Particles/ParticleSystem.h"
#include "Particles/ParticleSystemComponent.h"
#include "Components/SphereComponent.h"
#include "Components/StaticMeshComponent.h"
#include "BaseStation.generated.h"

UCLASS()
class MODERN_CITY_API ABaseStation : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABaseStation();
	// Array that helds all the FVector values for each Beam (X,Y,Z) float positions
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TArray<FVector> BeamVectorsArray;
	// Customizable ParticleSystemComponent that can be attached to the Visual Effect of Beam 
	// and used to create the Beam Shooting Animation
	UPROPERTY(EditAnywhere)
		UParticleSystemComponent* BeamParticle;

	// Definition of a custom BeamTarget class Actor that will be spawned at the scenario by 
	// SpawnBeamTargets method
	UPROPERTY(EditAnywhere)
		TSubclassOf<class ATarget> ToSpawn;

	// Starting BeamIndex of the BeamVectorsArray iteration 
	// (Used by SpawnBeamAtTarget method)
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int BeamIndex;

	// Responsible for Spawning BeamTarget Class Actors at the screen 
	// (This method should be triggered with Blueprints)	
	UFUNCTION(BlueprintCallable)
		void SpawnBeamTargets(FVector AntennaPosition, TArray<FVector> VectorsArray);

	// Responsible for setting the BeamTarget Position based on the Beam Array Vector position 

	// The current implementation of this method was made for testing and validation purposes 
	// only and can/will be changed.

	//(This method should be triggered with Blueprints)
	UFUNCTION(BlueprintCallable)
		void SpawnBeamAtTarget(FVector StartingPoint, TArray<FVector> VectorsArray);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
