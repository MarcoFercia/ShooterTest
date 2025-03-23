// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "FPSAbilitySystemComponent.generated.h"

/**
 * 
 */
class UAbilitiesDataAsset;

UCLASS()
class FPS_API UFPSAbilitySystemComponent : public UAbilitySystemComponent
{
public:
	virtual void PostInitProperties() override;

private:
	GENERATED_BODY()

public:
	
protected:
	UPROPERTY(EditDefaultsOnly, Category = "Configuration");
	UAbilitiesDataAsset* AbilitiesDataAsset;
	
	UPROPERTY(EditDefaultsOnly, Category = "Configuration");
	TArray<TSubclassOf<UAttributeSet>> AttributeSets;


	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<UGameplayEffect> GameplayEffectClass;
	
private:

	

	
public:
	void GiveAbilitiesToPlayer();
	void InitializeAttributes();
	
protected:
	
private:
	
	

	
};
