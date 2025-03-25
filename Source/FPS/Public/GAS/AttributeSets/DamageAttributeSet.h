// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GAS/AttributeSets/BaseAttributeSet.h"
#include "DamageAttributeSet.generated.h"

/**
 * 
 */
UCLASS()
class FPS_API UDamageAttributeSet : public UBaseAttributeSet
{
	GENERATED_BODY()
	

public:
	
	UPROPERTY(BlueprintReadOnly, Category = "Damage")
	FGameplayAttributeData Damage;
	
protected:

private:

public:	

	ATTRIBUTE_ACCESSORS(UDamageAttributeSet,Damage);

	
protected:

private:	
	
	
	
};
