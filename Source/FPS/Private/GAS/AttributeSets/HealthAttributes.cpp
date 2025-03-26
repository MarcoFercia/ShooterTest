// © 2025 Marco Fernandez garcia <marcoferciatr@gmail.com>


#include "GAS/AttributeSets/HealthAttributes.h"

#include "GameplayEffectExtension.h"


void UHealthAttributes::PreAttributeBaseChange(const FGameplayAttribute& Attribute, float& NewValue) const
{
	Super::PreAttributeBaseChange(Attribute, NewValue);
	
	 if (Attribute == GetHealthAttribute())
	 {
	 	NewValue = FMath::Clamp(NewValue,0.f,GetMaxHealth());
	 }
	
	 if (Attribute == GetMaxHealthAttribute())
	 {
	 	NewValue = FMath::Max(NewValue,1.f);
	 }	
}

void UHealthAttributes::PostAttributeBaseChange(const FGameplayAttribute& Attribute, float OldValue, float NewValue) const
{
	Super::PostAttributeBaseChange(Attribute, OldValue, NewValue);
}

void UHealthAttributes::PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue)
{
	Super::PreAttributeChange(Attribute, NewValue);	
}

void UHealthAttributes::PostAttributeChange(const FGameplayAttribute& Attribute, float OldValue, float NewValue)
{
	Super::PostAttributeChange(Attribute, OldValue, NewValue);

	// float baseHealth = Health.GetBaseValue();
	// float currentHealth = Health.GetCurrentValue();
	// float baseMaxHealth = MaxHealth.GetBaseValue();
	// float currentMaxHealth = MaxHealth.GetCurrentValue();
	
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
			if (GetHealth() > NewValue)
			{
				SetHealth(NewValue);
			}
		}		
	}	
}

bool UHealthAttributes::PreGameplayEffectExecute(FGameplayEffectModCallbackData& Data)
{
	return Super::PreGameplayEffectExecute(Data);
}

void UHealthAttributes::PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data)
{
	Super::PostGameplayEffectExecute(Data);
}
