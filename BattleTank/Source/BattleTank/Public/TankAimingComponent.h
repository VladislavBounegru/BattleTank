// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Components/StaticMeshComponent.h"
#include "TankAimingComponent.generated.h"

class UTankBarrel;

// Holds barrel's properties and Elevate method
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLETANK_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()




public:	
	UTankAimingComponent();

	void AimAt(FVector HitLocation, float LaunchSpeed);


	void GetProjectileVelocity(FVector HitLocation, float LaunchSpeed);

	// TODO add SetTurretReference

	void SetBarrelReference(UTankBarrel* BarrelToSet);

private:
	UTankBarrel* Barrel = nullptr;

	void MoveBarrelTowards(FVector AimDirection);

};