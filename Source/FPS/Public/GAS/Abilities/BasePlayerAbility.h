// © 2025 Marco Fernandez garcia <marcoferciatr@gmail.com>

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "InputTriggers.h"
#include "EnhancedInputComponent.h"
#include "BasePlayerAbility.generated.h"

class AMainCharacter;

UENUM(BlueprintType)
enum EAbilityActivationPolicy
{
	Passive  UMETA(DisplayName = "Passive"),
	Active    UMETA(DisplayName = "Active")
};

UENUM(BlueprintType)
enum EActivationMethod
{
	Triggered  UMETA(DisplayName = "Triggered"),
	Started    UMETA(DisplayName = "Started")
};


class UInputAction;

/**
 * 
 */
UCLASS(Abstract)
class FPS_API UBasePlayerAbility : public UGameplayAbility
{
	GENERATED_BODY()

	public:
	UBasePlayerAbility(const FObjectInitializer& ObjectInitializer);

public:

	
	
	
protected:

	UPROPERTY(EditDefaultsOnly, Category = "Ability Configuration")
	TEnumAsByte<EAbilityActivationPolicy> AbilityPolicy = Active;
	
	UPROPERTY(EditDefaultsOnly,Category = "Ability Configuration" ,DisplayName = "Input to Activate Ability",meta=(EditCondition="AbilityPolicy==EAbilityActivationPolicy::Active", EditConditionHides) )
	UInputAction* InputAction = nullptr;	
	
	UPROPERTY(EditDefaultsOnly, Category = "Ability Configuration",meta=(Bitmask, BitmaskEnum= "/Script/EnhancedInput.ETriggerEvent",EditCondition="AbilityPolicy==EAbilityActivationPolicy::Active", EditConditionHides))
	uint8 FunctionsToBind = 1;

	UPROPERTY(EditDefaultsOnly,Category = "Ability Configuration", meta=(EditCondition="AbilityPolicy==EAbilityActivationPolicy::Active", EditConditionHides))
	bool bStartAbilityFromCode = true;

	UPROPERTY(EditDefaultsOnly,Category = "Ability Configuration", meta=(ToolTip="Which type of input will activate the ability",EditCondition="bStartAbilityFromCode==True", EditConditionHides))
	TEnumAsByte<EActivationMethod> ActivationMethod  = EActivationMethod::Triggered;
	

UPROPERTY(BlueprintReadOnly)
	TObjectPtr<AMainCharacter> PlayerCharacter = nullptr;
	
private:
	UPROPERTY(Transient)
	FGameplayAbilitySpec OwnAbilitySpec;


	TArray<FInputBindingHandle*> InputBindings;
	
public:

	
protected:

	virtual void OnGiveAbility(const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilitySpec& Spec) override;
	virtual void OnRemoveAbility(const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilitySpec& Spec) override;
	
	UFUNCTION(BlueprintNativeEvent)
	void OnInputTriggered(const FInputActionValue& InputActionValue);

	UFUNCTION(BlueprintNativeEvent)
	void OnInputStarted(const FInputActionValue& InputActionValue);
	
	UFUNCTION(BlueprintNativeEvent)
	void OnInputOnGoing(const FInputActionValue& InputActionValue);

	UFUNCTION(BlueprintNativeEvent)
	void OnInputCanceled(const FInputActionValue& InputActionValue);

	UFUNCTION(BlueprintNativeEvent)
	void OnInputCompleted(const FInputActionValue& InputActionValue);
	
private:
	
};
