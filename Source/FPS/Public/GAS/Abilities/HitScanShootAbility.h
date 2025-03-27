// © 2025 Marco Fernandez garcia <marcoferciatr@gmail.com>

#pragma once

#include "CoreMinimal.h"
#include "GAS/Abilities/BaseShootAbility.h"
#include "HitScanShootAbility.generated.h"

/**
 * 
 */
UCLASS(Abstract)
class FPS_API UHitScanShootAbility : public UBaseShootAbility
{
	GENERATED_BODY()

	UHitScanShootAbility(const FObjectInitializer& ObjectInitializer);
	

public:

	UPROPERTY(EditAnywhere, Category = "Weapon Configuration")
	float WeaponTraceDistance = 1500.f;
	
protected:

private:

public:

UFUNCTION(BlueprintCallable)
	bool StartHitScan(FHitResult& Hit, FVector& HitDirection,FVector& StartPosition,FVector& EndPosition);
	
protected:

virtual void ShootProjectile(TArray<FHitResult>& _hits) override;
	
private:
	
	
};
