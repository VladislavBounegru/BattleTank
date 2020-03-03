// Fill out your copyright notice in the Description page of Project Settings.

#include "TankBarrel.h"
#include "TankTrack.h"
#include "Projectile.h"
#include "TankAimingComponent.h"
#include "TankMovementComponent.h"
#include "Tank.h"

// Sets default values
ATank::ATank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;



	//TankMovementComponent = CreateDefaultSubobject<UTankMovementComponent>(FName("Movement Component"));
}

// Called every frame

void ATank::AimAt(FVector HitLocation)

{
	TankAimingComponent->AimAt(HitLocation, LaunchSpeed);
}


void ATank::Initialise(UTankBarrel* BarrelToSet, UTankTurret* TurretToSet)
{
	TankAimingComponent->Initialise(BarrelToSet, TurretToSet);
	Barrel = BarrelToSet;
}

void ATank::SetTrackReference(UTankTrack* TrackToSet) 
{

}

void ATank::Fire()
{
	bool isReloaded = (FPlatformTime::Seconds() - LastFireTime) > ReloadTimeInSeconds;
	if (Barrel && isReloaded)
	{
		FActorSpawnParameters SpawnInfo;
		auto Projectile = GetWorld()->SpawnActor<AProjectile>(
			ProjectileBlueprint,
			Barrel->GetSocketLocation(FName("Projectile")),
			Barrel->GetSocketRotation(FName("Projectile")),
			SpawnInfo
			);
		Projectile->LaunchProjectile(LaunchSpeed);
		// Spawn a projecti;e at the socket location;
		LastFireTime = FPlatformTime::Seconds();
	}
}