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
	GENERATED_BODY()

public:
	
protected:
	UPROPERTY(EditDefaultsOnly, Category = "Configuration");
	UAbilitiesDataAsset* AbilitiesDataAsset;
	
private:

public:
	void GiveAbilitiesToPlayer();
	
protected:
	
private:
	
	

	
};
