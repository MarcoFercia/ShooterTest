// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "AbilitiesDataAsset.generated.h"

class UGameplayAbility;
/**
 * 
 */
UCLASS()
class FPS_API UAbilitiesDataAsset : public UPrimaryDataAsset
{
	GENERATED_BODY()

public:
UPROPERTY(EditDefaultsOnly, Category = "Abilities")
	TArray<TSubclassOf<UGameplayAbility>> Abilities;
};
