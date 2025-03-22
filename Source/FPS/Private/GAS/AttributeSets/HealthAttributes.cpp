// Fill out your copyright notice in the Description page of Project Settings.


#include "GAS/AttributeSets/HealthAttributes.h"


void UHealthAttributes::PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue)
{
	Super::PreAttributeChange(Attribute, NewValue);
	
	if (Attribute == GetHealthAttribute())
	{
		NewValue = FMath::Clamp(NewValue,0.f,GetMaxHealth());
	}

	if (Attribute == GetMaxHealthAttribute())
	{
		NewValue = FMath::Max(NewValue,1.f);
	}
	
}

void UHealthAttributes::PostAttributeChange(const FGameplayAttribute& Attribute, float OldValue, float NewValue)
{
	Super::PostAttributeChange(Attribute, OldValue, NewValue);

	if (Attribute == GetMaxHealthAttribute())
	{
		float differenceMaxHealth = NewValue - OldValue;
		float NewHealth = 0.f;
		
		if (differenceMaxHealth > 0.f)
		{
			NewHealth = GetHealth() + differenceMaxHealth;
			SetHealth(NewHealth);
		}
		else
		{
			if (GetHealth() > NewHealth)
			{
				SetHealth(NewValue);
			}
		}

		
	}

	
}
