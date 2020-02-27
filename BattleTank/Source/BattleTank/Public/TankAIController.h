// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "TankPlayerController.h"
#include "GameFramework/Controller.h"
#include "AIController.h"
#include "Engine/World.h"
#include "Engine/EngineTypes.h"
#include "TankAIController.generated.h"

class ATank;

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankAIController : public AAIController
{
	GENERATED_BODY()
	
private:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;


	ATank* GetAITank() const;

	ATank* GetPlayerTank() const;

	


	UPROPERTY(EditAnywhere)
		float CrossHairXLocation = 0.5f;

	UPROPERTY(EditAnywhere)
		float CrossHairYLocation = 0.33333f;
};
