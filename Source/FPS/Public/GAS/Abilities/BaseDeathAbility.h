// © 2025 Marco Fernandez garcia <marcoferciatr@gmail.com>

#pragma once

#include "CoreMinimal.h"
#include "GAS/Abilities/BaseFPSAbility.h"
#include "BaseDeathAbility.generated.h"

/**
 * 
 */

class UAsyncTaskAttributeChanged;
class UAbilityTask_WaitDelay;
UCLASS()
class FPS_API UBaseDeathAbility : public UBaseFPSAbility
{
	GENERATED_BODY()
	
public:

protected:

	UPROPERTY()
	UAsyncTaskAttributeChanged* TaskAttributeListener;

	UPROPERTY()
	UAbilityTask_WaitDelay* TaskWaitDelay;
	
private:

public:
	virtual void OnGiveAbility(const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilitySpec& Spec) override;
	virtual void ActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, const FGameplayEventData* TriggerEventData) override;

protected:

	void TryDeath();
	
	void CreateDeathTimer();

	UFUNCTION()
	void OnHealthChange(FGameplayAttribute Attribute, float NewValue, float OldValue);

	UFUNCTION()
	void OnDelayEnded();
private:

	
	
};
