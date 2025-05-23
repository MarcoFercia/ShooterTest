// © 2025 Marco Fernandez garcia <marcoferciatr@gmail.com>

#pragma once

#include "CoreMinimal.h"
#include "GAS/Abilities/BaseShootAbility.h"
#include "ProjectileShootAbility.generated.h"

class ABaseProjectile;


UCLASS()
class FPS_API UProjectileShootAbility : public UBaseShootAbility
{
	GENERATED_BODY()

	
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite,Category = "Weapon Configuration")
	TSubclassOf<ABaseProjectile> ProjectileClass;
	
protected:

private:

public:

protected:

	virtual void ShootProjectile(TArray<FHitResult>& _hits);

	void PrepareProjectile(ABaseProjectile* _projectile);
private:

	
	
	
	
};
