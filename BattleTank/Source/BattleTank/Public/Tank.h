// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Tank.generated.h"

class UTankBarrel;
class AProjectile;

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FTankDelegate);


UCLASS()
class BATTLETANK_API ATank : public APawn
{
	GENERATED_BODY()
	// Sets default values for this pawn's properties
	
public:

	//Called by the engine when actor damage is dealt
	virtual float TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent, class AController* EventInstigator, AActor* DamageCauser) override;

	// return current health of a a percentage of starting health, between 0 and 1
	UFUNCTION(BlueprintPure, Category = Health)
	float GetHealthPercent();

	FTankDelegate OnDeath;

	

private:
	ATank();

	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly, Category = Setup)
	int32 StartHealth = 100;
	
	UPROPERTY(VisibleAnywhere, Category = Health)
	int32 CurrentHealth; //initialize when game starts

};

