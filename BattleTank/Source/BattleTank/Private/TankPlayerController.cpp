// Fill out your copyright notice in the Description page of Project Settings.


#include "TankPlayerController.h"
#include "Tank.h"
#include "TankBarrel.h"
void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();
	auto ControlledTank = GetControlledTank(); 
	if (!ControlledTank) 
	{
		UE_LOG(LogTemp, Warning, TEXT("PlayerController not possessing a tank"));
	} 
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("PlayerController  possessing %s"), *ControlledTank->GetName());
	}
	UE_LOG(LogTemp, Warning, TEXT("PlayerController Begin Play"));
}

void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	Aimtowardscrosshair();
}


ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}
void ATankPlayerController::Aimtowardscrosshair()
{
	if (!GetControlledTank()) { return; }

	FVector HitLocation;
	if(GetSightRayHitLocation(HitLocation))
	{
		GetControlledTank()->AimAt(HitLocation);
	}
		// TODO Tell controll tank to aim at this point
}

bool ATankPlayerController::GetSightRayHitLocation(FVector& OutHitLocation) const
{
	int32 ViewportSizeX, ViewportSizeY;	
	GetViewportSize(ViewportSizeX, ViewportSizeY);
	auto ScreenLocation =  FVector2D(ViewportSizeX * CrossHairXLocation, ViewportSizeY * CrossHairYLocation);

	FVector LookDirection;
	if (GetLookDirection(ScreenLocation, LookDirection))
	{
		GetLookVectorHitLocation(OutHitLocation, LookDirection);
	}

	return true;	
}

bool ATankPlayerController::GetLookDirection(FVector2D ScreenLocation,FVector& LookDirection) const
{
	FVector CameraWorldLocation;
	return DeprojectScreenPositionToWorld(
		ScreenLocation.X,
		ScreenLocation.Y,
		CameraWorldLocation,
		LookDirection
	);
	
	 
}
bool ATankPlayerController::GetLookVectorHitLocation(FVector & HitLocation,FVector LookDirection) const
{
	FHitResult Hit;
	auto StartLocation = PlayerCameraManager->GetCameraLocation();
	auto EndLocation = StartLocation + (LookDirection * LineTraceRange);
	if (GetWorld()->LineTraceSingleByChannel(
		Hit,
		StartLocation,
		EndLocation,
		ECollisionChannel::ECC_Visibility)) {
		HitLocation = Hit .Location;
		return true;
	}
	HitLocation = FVector(0);
	return false;
}