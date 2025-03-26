// © 2025 Marco Fernandez garcia <marcoferciatr@gmail.com>

#pragma once

#include "CoreMinimal.h"

#include "DamageAttributeSet.h"
#include "AmmoAttrubites.generated.h"

/**
 * 
 */
UCLASS()
class FPS_API UAmmoAttributes : public UDamageAttributeSet
{
	GENERATED_BODY()
public:
	
	UPROPERTY(BlueprintReadOnly, Category = "Ammo")
	FGameplayAttributeData Ammo;

	UPROPERTY(BlueprintReadOnly, Category = "Ammo")
	FGameplayAttributeData MaxAmmo;

	UPROPERTY(BlueprintReadOnly, Category = "Ammo")
	FGameplayAttributeData ReloadTime;
	
protected:

private:

public:	

	ATTRIBUTE_ACCESSORS(UAmmoAttributes,Ammo);
	ATTRIBUTE_ACCESSORS(UAmmoAttributes,MaxAmmo);
	ATTRIBUTE_ACCESSORS(UAmmoAttributes,ReloadTime);

	
	virtual void PreAttributeBaseChange(const FGameplayAttribute& Attribute, float& NewValue) const override;
	virtual void PostAttributeBaseChange(const FGameplayAttribute& Attribute, float OldValue, float NewValue) const override;
	
	virtual void PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue) override;
	virtual void PostAttributeChange(const FGameplayAttribute& Attribute, float OldValue, float NewValue) override;

	virtual bool PreGameplayEffectExecute(FGameplayEffectModCallbackData& Data) override;
	virtual void PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data) override;
	
protected:

private:	
	
};
