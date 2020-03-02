// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankTrack.generated.h"

/**
 * TankTrack is used to set amximum driving force, and to move the tank
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTankTrack : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable, Category = Setup)
	void SetThrottle(float Throttle);

	// Max force per track, in Newtons
	UPROPERTY(EditDefaultsOnly)
		float TrackMaxDrivingForce = 4000000.f; // assume 40 tonne tank, and 1g accelleration
};
