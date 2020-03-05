// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "TankAimingComponent.h"
#include "GameFramework/Controller.h"
#include "Engine/World.h"
#include "Engine/EngineTypes.h"


void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	auto PlayerTank = GetWorld()->GetFirstPlayerController()->GetPawn();
	auto ControlledTank = GetPawn();
	if (!ensure(PlayerTank && ControlledTank)){ return;	}
	MoveToActor(PlayerTank, AcceptanceRadius); //TODO check radius in cm
	// TODO Move towards the player
	auto AimingComponent = ControlledTank->FindComponentByClass<UTankAimingComponent>();
	// Aim towards the player
	AimingComponent->AimAt(PlayerTank->GetActorLocation());


	//TODO fix firing

	if (AimingComponent->GetFiringState() == EFiringState::Locked)
	{
		AimingComponent->Fire(); // TODO limit firing rate
	}
}





