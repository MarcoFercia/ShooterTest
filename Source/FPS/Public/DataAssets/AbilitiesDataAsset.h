// © 2025 Marco Fernandez garcia <marcoferciatr@gmail.com>

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
