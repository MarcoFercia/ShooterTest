// Fill out your copyright notice in the Description page of Project Settings.


#include "GAS/FPSAbilitySystemComponent.h"

#include "DataAssets/AbilitiesDataAsset.h"


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
