// Fill out your copyright notice in the Description page of Project Settings.


#include "GAS/FPSAbilitySystemComponent.h"

#include "DataAssets/AbilitiesDataAsset.h"
#include "GAS/AttributeSets/HealthAttributes.h"


void UFPSAbilitySystemComponent::PostInitProperties()
{
	Super::PostInitProperties();
}

void UFPSAbilitySystemComponent::GiveAbilitiesToPlayer()
{
	if (AbilitiesDataAsset)
	{
		for (auto it : AbilitiesDataAsset->Abilities)
		{
			K2_GiveAbility(it);
		}
	}
	
	

}

void UFPSAbilitySystemComponent::InitializeAttributes()
{
	TArray<UAttributeSet*> attributesSets;	
	for (auto it : AttributeSets)
	{
		attributesSets.Add(NewObject<UAttributeSet>(GetAvatarActor(),it));
	}
	SetSpawnedAttributes(attributesSets);


	UGameplayEffect* effect = GameplayEffectClass->GetDefaultObject<UGameplayEffect>();
	FGameplayEffectContextHandle context;
	ApplyGameplayEffectToSelf(effect,0,context);
}
