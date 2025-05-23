// © 2025 Marco Fernandez garcia <marcoferciatr@gmail.com>

#pragma once

#include "CoreMinimal.h"
#include "GAS/Abilities/BasePlayerAbility.h"
#include "BasePlayerAbilityWithWidget.generated.h"

/**
 * 
 */
class UFerciaUserWidget;


UCLASS()
class FPS_API UBasePlayerAbilityWithWidget : public UBasePlayerAbility
{
	GENERATED_BODY()

public:

	UBasePlayerAbilityWithWidget(const FObjectInitializer& ObjectInitializer);
	
public:

	UPROPERTY(EditAnywhere, Category = "Ability Configuration| Widget")
	TSubclassOf<UUserWidget> WidgetClass;
	
	UPROPERTY(EditAnywhere, Category = "Ability Configuration| Widget")
	bool bShowOnlyWhileAbilityIsActive = false;


	
protected:

	

	
private:

	UPROPERTY()
	UFerciaUserWidget* WidgetRef = nullptr;
	
public:

	UFUNCTION(BlueprintPure)
	UFerciaUserWidget* GetWidgetRef();

protected:
	virtual void OnGiveAbility(const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilitySpec& Spec) override;
	virtual void ActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, const FGameplayEventData* TriggerEventData) override;
	virtual void EndAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, bool bReplicateEndAbility, bool bWasCancelled) override;
	
private:
	
	
};
