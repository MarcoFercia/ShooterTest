// © 2025 Marco Fernandez garcia <marcoferciatr@gmail.com>


#include "GAS/Abilities/BaseFPSAbility.h"

#include "AbilitySystemComponent.h"
#include "Core/TagsMacros.h"
#include "GAS/AbilityTask/FerciaTickTask.h"



#if WITH_EDITOR
void UBaseFPSAbility::PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent)
{
	Super::PostEditChangeProperty(PropertyChangedEvent);
	ProcessConfiguration();
	
}

void UBaseFPSAbility::PostCDOCompiled(const FPostCDOCompiledContext& Context)
{
	Super::PostCDOCompiled(Context);
	ProcessConfiguration();
}

void UBaseFPSAbility::ProcessConfiguration()
{
	ProcessTagConfiguration(RequiredWeaponToActivate,ActivationRequiredTags,GET_TAG(HAS_WEAPON_TAG));
	ProcessTagConfiguration(BlockAbilityOnDeath,ActivationBlockedTags,GET_TAG(DEATH_TAG));	
}

void UBaseFPSAbility::ProcessTagConfiguration(bool& _bValue, FGameplayTagContainer& _ContainerToManipulate, FGameplayTag _Tag)
{
	if (_bValue && !_ContainerToManipulate.HasTag(_Tag))
	{
		_ContainerToManipulate.AddTag(_Tag);
	}
	else if (!_bValue && _ContainerToManipulate.HasTag(_Tag))
	{
		_ContainerToManipulate.RemoveTag(_Tag);
	}
}

#endif

UBaseFPSAbility::UBaseFPSAbility(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) 
{
	
}

void UBaseFPSAbility::OnGiveAbility(const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilitySpec& Spec)
{
	Super::OnGiveAbility(ActorInfo, Spec);
	
	if (AbilityPolicy == Passive)
	{
		GetAbilitySystemComponentFromActorInfo()->TryActivateAbility(CurrentSpecHandle);
		return;
	}	
}

void UBaseFPSAbility::ActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, const FGameplayEventData* TriggerEventData)
{
	Super::ActivateAbility(Handle, ActorInfo, ActivationInfo, TriggerEventData);

	if (bNeedTick)
	{
		TickTask = UFerciaTickTask::TickTask(this,0.f,0.016f);
		TickTask->GetTickDelegate().AddDynamic(this,&UBaseFPSAbility::OnAbilityTick);
		TickTask->ReadyForActivation();
	}
}

void UBaseFPSAbility::OnRemoveAbility(const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilitySpec& Spec)
{
	Super::OnRemoveAbility(ActorInfo, Spec);
}

void UBaseFPSAbility::OnAbilityTick_Implementation(float elapsedTime, float DeltaTime)
{
	
}



