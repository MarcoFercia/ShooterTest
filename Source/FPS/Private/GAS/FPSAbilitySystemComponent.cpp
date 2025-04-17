// © 2025 Marco Fernandez garcia <marcoferciatr@gmail.com>


#include "GAS/FPSAbilitySystemComponent.h"

#include "DataAssets/AbilitiesDataAsset.h"
#include "GAS/AttributeSets/HealthAttributes.h"


void UFPSAbilitySystemComponent::PostInitProperties()
{
	Super::PostInitProperties();
}

void UFPSAbilitySystemComponent::GiveAbilitiesToOwner()
{
	if (AbilitiesDataAsset)
	{
		for (auto it : AbilitiesDataAsset->Abilities)
		{
			K2_GiveAbility(it);
		}
	}
}

void UFPSAbilitySystemComponent::GiveAbilitiesToOwner(TArray<TSubclassOf<UGameplayAbility>>& _abilities)
{
	for (auto it : _abilities)
		{
			K2_GiveAbility(it);
		}	
}

void UFPSAbilitySystemComponent::InitializeAttributes()
{
	TArray<UAttributeSet*> attributesSets;	
	for (auto it : AttributeSetsClass)
	{
		attributesSets.Add(NewObject<UAttributeSet>(GetAvatarActor(),it));
	}
	SetSpawnedAttributes(attributesSets);

	if (GameplayEffectClass)
	{
		ApplyGameplayEffect(GameplayEffectClass);
	}
}

void UFPSAbilitySystemComponent::InitializeAttributes(TArray<TSubclassOf<UAttributeSet>>& _newAttributes)
{
	TArray<UAttributeSet*> attributesSets;	
	for (auto it : _newAttributes)
	{
		attributesSets.Add(NewObject<UAttributeSet>(GetAvatarActor(),it));
	}
	SetSpawnedAttributes(attributesSets);

	if (GameplayEffectClass)
	{
		ApplyGameplayEffect(GameplayEffectClass);
	}
}

void UFPSAbilitySystemComponent::ApplyGameplayEffect(TSubclassOf<UGameplayEffect> _effectToApply)
{
	UGameplayEffect* effect = _effectToApply->GetDefaultObject<UGameplayEffect>();
	FGameplayEffectContextHandle context;
	ApplyGameplayEffectToSelf(effect,0,context);
}

void UFPSAbilitySystemComponent::BeginPlay()
{
	Super::BeginPlay();

	InitializeAttributes();
	GiveAbilitiesToOwner();
}
