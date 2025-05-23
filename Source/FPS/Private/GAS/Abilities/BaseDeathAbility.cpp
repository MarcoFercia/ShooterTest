// © 2025 Marco Fernandez garcia <marcoferciatr@gmail.com>


#include "GAS/Abilities/BaseDeathAbility.h"

#include "Abilities/Tasks/AbilityTask_WaitDelay.h"
#include "Character/BaseFPSCharacter.h"
#include "GAS/AsyncTaskAttributeChanged.h"
#include "GAS/AttributeSets/HealthAttributes.h"
#include "Tasks/GameplayTask_WaitDelay.h"


void UBaseDeathAbility::OnGiveAbility(const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilitySpec& Spec)
{
	Super::OnGiveAbility(ActorInfo, Spec);
	TaskAttributeListener = UAsyncTaskAttributeChanged::ListenForAttributeChange(GetAbilitySystemComponentFromActorInfo(),UHealthAttributes::GetHealthAttribute());
	TaskAttributeListener->OnAttributeChanged.AddDynamic(this,&UBaseDeathAbility::OnHealthChange);
	TaskAttributeListener->Activate();	
}

void UBaseDeathAbility::ActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, const FGameplayEventData* TriggerEventData)
{
	Super::ActivateAbility(Handle, ActorInfo, ActivationInfo, TriggerEventData);
	ABaseFPSCharacter* actorOwner = Cast<ABaseFPSCharacter>(GetAvatarActorFromActorInfo());
	if (actorOwner)
	{
		actorOwner->DeathCharacter();
	}
}

void UBaseDeathAbility::OnHealthChange(FGameplayAttribute Attribute, float NewValue, float OldValue)
{
	if (NewValue <= 0.f)
	{
		TryDeath();	
	}
	else if (NewValue > 0.f && TaskWaitDelay != nullptr)
	{
		TaskWaitDelay->ExternalCancel();
	}
}

void UBaseDeathAbility::TryDeath()
{
	if (!GetAbilitySystemComponentFromActorInfo()->TryActivateAbility(CurrentSpecHandle))
	{
		CreateDeathTimer();
	}	
}

void UBaseDeathAbility::CreateDeathTimer()
{
	if (TaskWaitDelay == nullptr)
	{
		TaskWaitDelay =	UAbilityTask_WaitDelay::WaitDelay(this,0.016f);
		TaskWaitDelay->OnFinish.AddDynamic(this,& UBaseDeathAbility::OnDelayEnded);
		TaskWaitDelay->Activate();
	}
}


void UBaseDeathAbility::OnDelayEnded()
{
	TaskWaitDelay = nullptr;
	if (GetAbilitySystemComponentFromActorInfo()->GetNumericAttribute(UHealthAttributes::GetHealthAttribute()) <=0.f)
	{
		TryDeath();
	}
}
