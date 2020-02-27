// Fill out your copyright notice in the Description page of Project Settings.


#include "TankAIController.h"
#include "Tank.h"


void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
	auto AITank = GetAITank();
	if (!AITank)
	{
		UE_LOG(LogTemp, Warning, TEXT("AIController not possessing a tank"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AIController  possessing %s"), *AITank->GetName());
	}
	auto PlayerTank = GetPlayerTank();
	if (!PlayerTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("AIController cant find player atynk"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AIController  found player: %s"), *PlayerTank->GetName());
	}
}

void ATankAIController::Tick(float DeltaTime)
{
	Super::BeginPlay();
	if (GetPlayerTank())
	{
		// move towards to player
		
		// aim towards player
		GetAITank()->AimAt(GetPlayerTank()->GetActorLocation());
		// fire if reasdy
	}
}

ATank* ATankAIController::GetAITank() const
{
		return Cast<ATank>(GetPawn());
}

ATank* ATankAIController::GetPlayerTank() const
{
	auto PlayerTank = GetWorld()->GetFirstPlayerController()->GetPawn();
	if (!PlayerTank) { return nullptr; }
	return Cast<ATank>(PlayerTank);
}


