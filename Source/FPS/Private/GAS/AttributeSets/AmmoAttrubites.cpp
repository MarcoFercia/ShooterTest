// Fill out your copyright notice in the Description page of Project Settings.


#include "GAS/AttributeSets/AmmoAttrubites.h"


void UAmmoAttributes::PreAttributeBaseChange(const FGameplayAttribute& Attribute, float& NewValue) const
{
	Super::PreAttributeBaseChange(Attribute, NewValue);

	if (Attribute == GetAmmoAttribute())
	{
		NewValue = FMath::Clamp(NewValue,0.f,GetMaxAmmo());
	}
	
	if (Attribute == GetMaxAmmoAttribute())
	{
		NewValue = FMath::Max(NewValue,0.f);
	}		
}

void UAmmoAttributes::PostAttributeBaseChange(const FGameplayAttribute& Attribute, float OldValue, float NewValue) const
{
	Super::PostAttributeBaseChange(Attribute, OldValue, NewValue);

	

}

void UAmmoAttributes::PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue)
{
	Super::PreAttributeChange(Attribute, NewValue);
}

void UAmmoAttributes::PostAttributeChange(const FGameplayAttribute& Attribute, float OldValue, float NewValue)
{
	Super::PostAttributeChange(Attribute, OldValue, NewValue);
	
	if (Attribute == GetMaxAmmoAttribute() && ((NewValue - OldValue) <= 0.f) && GetAmmo() > NewValue)
	{
		SetAmmo(NewValue);
	}
	
}

bool UAmmoAttributes::PreGameplayEffectExecute(FGameplayEffectModCallbackData& Data)
{
	return Super::PreGameplayEffectExecute(Data);
}

void UAmmoAttributes::PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data)
{
	Super::PostGameplayEffectExecute(Data);
}
