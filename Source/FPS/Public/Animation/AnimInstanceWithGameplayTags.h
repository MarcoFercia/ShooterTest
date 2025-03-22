// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "AnimInstanceWithGameplayTags.generated.h"

/**
 * 
 */
class UFPSAbilitySystemComponent;

UCLASS()
class FPS_API UAnimInstanceWithGameplayTags : public UAnimInstance
{
	GENERATED_BODY()
	
public:

protected:
	UPROPERTY()
	UFPSAbilitySystemComponent* AbilitySystemComponent;
	
private:

	
	
public:
	UFUNCTION(BlueprintPure, meta= (BlueprintThreadSafe))
	bool HasTag(FGameplayTag _TagToCheck,bool DebugPreview);
	
protected:

virtual void NativeBeginPlay() override;
	
private:

	
	
};
