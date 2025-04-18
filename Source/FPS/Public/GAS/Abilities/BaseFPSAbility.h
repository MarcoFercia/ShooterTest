// © 2025 Marco Fernandez garcia <marcoferciatr@gmail.com>

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "BaseFPSAbility.generated.h"

/**
 * 
 */

class UFerciaTickTask;

UENUM(BlueprintType)
enum EAbilityActivationPolicy
{
	Passive  UMETA(DisplayName = "Passive"),
	Active    UMETA(DisplayName = "Active")
};



UCLASS(Abstract)
class FPS_API UBaseFPSAbility : public UGameplayAbility
{
public:
	


	GENERATED_BODY()

	UBaseFPSAbility(const FObjectInitializer& ObjectInitializer);
	
public:

//Confiuration Ability Tags
	UPROPERTY(EditAnywhere, Category = "Ability Configuration|Conditional Tags")
	bool RequiredWeaponToActivate = false;
	UPROPERTY(EditAnywhere, Category = "Ability Configuration|Conditional Tags")
	bool BlockAbilityOnDeath = false;
	UPROPERTY(EditAnywhere, Category = "Ability Configuration")
	bool bNeedTick = false;


	
	
protected:

	UPROPERTY(EditDefaultsOnly, Category = "Ability Configuration")
	TEnumAsByte<EAbilityActivationPolicy> AbilityPolicy = Active;
	
	

	
private:
	UPROPERTY()
	UFerciaTickTask* TickTask = nullptr;
	
	
public:

protected:

#if WITH_EDITOR
	virtual void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) override;
	virtual void PostCDOCompiled(const FPostCDOCompiledContext& Context) override;
	virtual void ProcessConfiguration();
	void ProcessTagConfiguration(bool& _bValue, FGameplayTagContainer& _ContainerToManipulate, FGameplayTag _Tag);
#endif

	virtual void OnGiveAbility(const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilitySpec& Spec) override;
	virtual void ActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, const FGameplayEventData* TriggerEventData) override;
	virtual void OnRemoveAbility(const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilitySpec& Spec) override;	

	UFUNCTION(BlueprintImplementableEvent)
	void OnGivenAbility(const FGameplayAbilityActorInfo& ActorInfo, const FGameplayAbilitySpec& Spec);
	
	UFUNCTION(BlueprintNativeEvent)
	void OnAbilityTick(float elapsedTime, float DeltaTime);
	
private:

	
	
	
};
