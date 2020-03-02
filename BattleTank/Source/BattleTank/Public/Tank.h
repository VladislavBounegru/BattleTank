// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Tank.generated.h"

class UTankBarrel;
class UTankAimingComponent;
class AProjectile;
class UTankTrack;
class UTankMovementComponent;


UCLASS()
class BATTLETANK_API ATank : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ATank();

	void AimAt(FVector HitLocation);

	UFUNCTION(BlueprintCallable,Category = Setup)
	void SetBarrelReference(UTankBarrel* BarrelToSet);

	UFUNCTION(BlueprintCallable, Category = Setup)
	void SetTurretReference(UTankTurret* TurretToSet);

	UFUNCTION(BlueprintCallable, Category = Setup)
	void SetTrackReference(UTankTrack* TrackToSet);

	UFUNCTION(BlueprintCallable, Category = Firing)
	void Fire();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(BlueprintReadOnly)
	UTankMovementComponent* TankMovementComponent = nullptr;

	UTankAimingComponent* TankAimingComponent = nullptr;

	

private:	
	// Called every frame

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;


	UPROPERTY(EditDefaultsOnly, Category = Firing)
	float LaunchSpeed = 4000; // TODO find sendible default

	UPROPERTY(EditDefaultsOnly, Category = Setup)
	TSubclassOf<AProjectile> ProjectileBlueprint;

	UPROPERTY(EditDefaultsOnly, Category = Firing)
	float ReloadTimeInSeconds = 3.f;

	// reference to spawn projectile
	UTankBarrel* Barrel = nullptr;

	

	double LastFireTime = 0;
};
