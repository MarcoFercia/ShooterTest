// © 2025 Marco Fernandez garcia <marcoferciatr@gmail.com>


#include "GAS/Abilities/BaseShootAbility.h"

#include "AbilitySystemBlueprintLibrary.h"
#include "AbilitySystemComponent.h"
#include "Abilities/Tasks/AbilityTask_WaitDelay.h"
#include "Character/MainCharacter.h"
#include "Character/Components/ActiveWeaponComponent.h"
#include "Core/TagsMacros.h"
#include "Kismet/KismetMathLibrary.h"


void UBaseShootAbility::ActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, const FGameplayEventData* TriggerEventData)
{
	Super::ActivateAbility(Handle, ActorInfo, ActivationInfo, TriggerEventData);
	CommitAbility(Handle, ActorInfo, ActivationInfo);
	TArray<FHitResult> Hits;	
	ShootProjectile(Hits);
	ApplyDamageEffect(Hits);
	
	if (UKismetMathLibrary::NearlyEqual_FloatFloat(TimeBetweenShots,0.f))
	{
		OnTimerFinish();
		return;
	}
	
	DelayTask = UAbilityTask_WaitDelay::WaitDelay(this,TimeBetweenShots);
	DelayTask->OnFinish.AddDynamic(this,&UBaseShootAbility::OnTimerFinish);
	DelayTask->Activate();
}

bool UBaseShootAbility::CommitAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, FGameplayTagContainer* OptionalRelevantTags)
{
	if (GetAbilitySystemComponentFromActorInfo()->HasMatchingGameplayTag(GET_TAG(INFINITE_AMMO_TAG)))
	{
		return true;
	}
	return Super::CommitAbility(Handle, ActorInfo, ActivationInfo, OptionalRelevantTags);
}

void UBaseShootAbility::EndAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, bool bReplicateEndAbility, bool bWasCancelled)
{
	Super::EndAbility(Handle, ActorInfo, ActivationInfo, bReplicateEndAbility, bWasCancelled);

	if (!CheckCost(CurrentSpecHandle, CurrentActorInfo))
	{
		UAbilitySystemBlueprintLibrary::SendGameplayEventToActor(GetAvatarActorFromActorInfo(),GET_TAG(INPUT_RELOAD_TAG),FGameplayEventData());
	}
	
}

void UBaseShootAbility::ShootProjectile(TArray<FHitResult>& _hits)
{
}



void UBaseShootAbility::ExecuteCues_Implementation(FVector _StartPos, FVector _EndPos)
{
	TArray<FGameplayTag> CuesToExecute;
	CuesToActivate.GetGameplayTagArray(CuesToExecute);	
	for (FGameplayTag it : CuesToActivate)
	{
		FGameplayCueParameters params;
		params.Location = _StartPos;
		params.Normal = _EndPos;
		params.Instigator = GetAvatarActorFromActorInfo();
		GetAbilitySystemComponentFromActorInfo()->ExecuteGameplayCue(it, params);
	}
}

void UBaseShootAbility::OnTimerFinish_Implementation()
{
	EndAbility(CurrentSpecHandle, CurrentActorInfo, CurrentActivationInfo, true, false);
}

void UBaseShootAbility::ApplyDamageEffect(TArray<FHitResult>& _hits)
{
	for (FHitResult& it : _hits)
	{
		ApplyDamageEffectToTarget(it);
	}
}

void UBaseShootAbility::ApplyDamageEffectToTarget(FHitResult& _hit)
{
	FGameplayAbilityTargetData_SingleTargetHit* TargetData = new FGameplayAbilityTargetData_SingleTargetHit(_hit);
	
	TArray<FActiveGameplayEffectHandle> temp = ApplyGameplayEffectToTarget(CurrentSpecHandle,CurrentActorInfo,CurrentActivationInfo,TargetData,HitEffect,1);
}




FTransform UBaseShootAbility::GetWeaponSocketTransform()
{
	FTransform weaponStartPoint = FTransform::Identity;
	AActor* temp = GetAvatarActorFromActorInfo();	
	if (!temp)
	{
		return weaponStartPoint;
	}
	AMainCharacter* MyCharacter = Cast<AMainCharacter>(temp);
	if (!MyCharacter)
	{
		return weaponStartPoint;
	}
	UActiveWeaponComponent* WeaponComponent = MyCharacter->GetWeaponComponent();

	if (!WeaponComponent)
	{
		return weaponStartPoint;
	}
	UMeshComponent* MeshComponent = WeaponComponent->GetWeaponMesh();
	if (!MeshComponent)
	{
		return weaponStartPoint;
	}
	
	weaponStartPoint = MeshComponent->GetSocketTransform(FName("Muzzle"));
	return weaponStartPoint;
}
