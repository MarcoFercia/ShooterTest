// © 2025 Marco Fernandez garcia <marcoferciatr@gmail.com>

#pragma once

#include "CoreMinimal.h"
#include "GAS/Abilities/BaseFireAbility.h"
#include "BaseHitscanShootAbility.generated.h"

/**
 * 
 */
UCLASS(Abstract)
class FPS_API UBaseHitscanShootAbility : public UBaseFireAbility
{
	GENERATED_BODY()

	UBaseHitscanShootAbility(const FObjectInitializer& ObjectInitializer);
	

public:

UPROPERTY(EditAnywhere, Category = "Weapon Configuration")
	float WeaponTraceDistance = 1500.f;
	
protected:

private:


public:

UFUNCTION(BlueprintCallable)
	bool StartHitScan(FHitResult& Hit, FVector& HitDirection,FVector& StartPosition,FVector& EndPosition);
	
protected:

private:

	FVector GetWeaponSocketLocation();
	
	
};
