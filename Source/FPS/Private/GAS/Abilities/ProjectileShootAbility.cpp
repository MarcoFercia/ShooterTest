// © 2025 Marco Fernandez garcia <marcoferciatr@gmail.com>


#include "GAS/Abilities/ProjectileShootAbility.h"
#include "Projectiles/BaseProjectile.h"


void UProjectileShootAbility::ShootProjectile(TArray<FHitResult>& _hits)
{
	Super::ShootProjectile(_hits);
	ABaseProjectile* NewProjectile = GetWorld()->SpawnActor<ABaseProjectile>(ProjectileClass,GetWeaponSocketTransform());
	
	if (!NewProjectile)
	{
		return;
	}
	PrepareProjectile(NewProjectile);
	
}

void UProjectileShootAbility::PrepareProjectile(ABaseProjectile* _projectile)
{
	_projectile->SetEffectSpecHandle(MakeOutgoingGameplayEffectSpec(HitEffect,1));
	_projectile->SetAbilitySystemComponent(GetAbilitySystemComponentFromActorInfo_Ensured());
}
