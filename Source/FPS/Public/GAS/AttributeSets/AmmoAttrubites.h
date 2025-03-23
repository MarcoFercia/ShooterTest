// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseAttributeSet.h"
#include "AmmoAttrubites.generated.h"

/**
 * 
 */
UCLASS()
class FPS_API UAmmoAttributes : public UBaseAttributeSet
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
