// © 2025 Marco Fernandez garcia <marcoferciatr@gmail.com>

#pragma once

#include "CoreMinimal.h"
#include "GAS/Abilities/BasePlayerAbility.h"
#include "BaseShootAbility.generated.h"

/**
 * 
 */
class UAbilityTask_WaitDelay;

UCLASS(Abstract)
class FPS_API UBaseShootAbility : public UBasePlayerAbility
{
	GENERATED_BODY()
	
public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite,Category = "Weapon Configuration")
	FGameplayTagContainer CuesToActivate;

	UPROPERTY(EditAnywhere, BlueprintReadWrite,Category = "Weapon Configuration")
	float TimeBetweenShots = 0.2f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite,Category = "Weapon Configuration")
	TSubclassOf<UGameplayEffect> HitEffect;

protected:
	
private:
	UPROPERTY()
	TObjectPtr<UAbilityTask_WaitDelay> DelayTask;
	
public:

	virtual void ActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, const FGameplayEventData* TriggerEventData) override;
	virtual bool CommitAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, FGameplayTagContainer* OptionalRelevantTags = nullptr) override;
	virtual void EndAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, bool bReplicateEndAbility, bool bWasCancelled) override;

	

	
protected:

	//Inside this function you should call ExecuteCues to play VFX
	virtual void ShootProjectile(TArray<FHitResult>& _hits);
	
	UFUNCTION(BlueprintNativeEvent)
	void ExecuteCues(FVector _StartPos, FVector _EndPos);

	UFUNCTION(BlueprintNativeEvent)
	void OnTimerFinish();

	void ApplyDamageEffect(TArray<FHitResult>& _hits);
	void ApplyDamageEffectToTarget(FHitResult& _hit);

	FTransform GetWeaponSocketTransform();	
	
private:
	
};

