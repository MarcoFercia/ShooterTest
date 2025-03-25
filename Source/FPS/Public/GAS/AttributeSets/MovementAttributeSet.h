// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GAS/AttributeSets/BaseAttributeSet.h"
#include "MovementAttributeSet.generated.h"

/**
 * 
 */
UCLASS()
class FPS_API UMovementAttributeSet : public UBaseAttributeSet
{
	GENERATED_BODY()
	
public:
	UPROPERTY(BlueprintReadOnly, Category = "Movement")
	FGameplayAttributeData Speed;
	
protected:

private:

public:	

	ATTRIBUTE_ACCESSORS(UMovementAttributeSet,Speed);
	
protected:

	virtual void PreAttributeBaseChange(const FGameplayAttribute& Attribute, float& NewValue) const override;
	virtual void PostAttributeChange(const FGameplayAttribute& Attribute, float OldValue, float NewValue) override;
	
private:	
};
