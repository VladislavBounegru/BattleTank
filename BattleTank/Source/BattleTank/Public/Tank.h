// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Tank.generated.h"

class UTankBarrel;
class AProjectile;


UCLASS()
class BATTLETANK_API ATank : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ATank();

	

	UFUNCTION(BlueprintCallable, Category = Firing)
	void Fire();

protected:
	virtual void BeginPlay()  override;
	



	

private:	

	// TODO remove once	FIRNIG IS MOVED TO AIMING component
	UPROPERTY(EditDefaultsOnly, Category = Firing)
	float LaunchSpeed = 4000; // TODO find sendible default

	UPROPERTY(EditDefaultsOnly, Category = Setup)
	TSubclassOf<AProjectile> ProjectileBlueprint;

	UPROPERTY(EditDefaultsOnly, Category = Firing)
	float ReloadTimeInSeconds = 3.f;

	// reference to spawn projectile
	UTankBarrel* Barrel = nullptr; // TODO remove

	

	double LastFireTime = 0;
};
