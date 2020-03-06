#include "Tank.h"
#include "Math/UnrealMathUtility.h"


float ATank::GetHealthPercent()
{
	return (float)CurrentHealth/(float)StartHealth;
}

// Sets default values
ATank::ATank()
{
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
}

void ATank::BeginPlay()
{
	Super::BeginPlay();
	CurrentHealth = StartHealth;
}
float ATank::TakeDamage(float DamageAmount, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser)
{
	Super::TakeDamage( DamageAmount,   DamageEvent,  EventInstigator,  DamageCauser);
	int32 DamagePoints = FPlatformMath::RoundToInt(DamageAmount);
	int32 DamageToApply = FMath::Clamp(DamagePoints, 0, CurrentHealth);
	CurrentHealth -= DamageToApply;
	if (CurrentHealth <= 0) 
	{ 
		OnDeath.Broadcast();
	}
	return DamageToApply;
}



