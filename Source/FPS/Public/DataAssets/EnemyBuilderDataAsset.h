// © 2025 Marco Fernandez garcia <marcoferciatr@gmail.com>

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "GameplayEffect.h"
#include "StateTreeReference.h"
#include "Blueprint/UserWidget.h"
#include "EnemyBuilderDataAsset.generated.h"

/**
 * 
 */
class USkeletalMesh;
class UAbilitiesDataAsset;

UCLASS()
class FPS_API UEnemyBuilderDataAsset : public UPrimaryDataAsset
{
	GENERATED_BODY()
public:
	
	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly)
	TObjectPtr<USkeletalMesh> EnemyMesh;
	
	UPROPERTY(EditDefaultsOnly, meta =(DisplayName= "Effect to initialize attributes"))
	TSubclassOf<UGameplayEffect> GameplayEffectClass;
	
	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly)
	TSubclassOf<UUserWidget> HealthBarWidgetClass;

	UPROPERTY(EditDefaultsOnly);
	UAbilitiesDataAsset* AbilitiesDataAsset;
	
	UPROPERTY(EditDefaultsOnly)
	FStateTreeReference StateTreeSchema;

	UPROPERTY(EditDefaultsOnly);
	TArray<TSubclassOf<UAttributeSet>> attributesForEnemy;
	
	
public:

	bool CheckInformationFilled() const;
	
};
