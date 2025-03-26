// © 2025 Marco Fernandez garcia <marcoferciatr@gmail.com>

#pragma once

#include "CoreMinimal.h"
#include "InputActionValue.h"
#include "GAS/Abilities/BasePlayerAbility.h"
#include "PlayerMovementAbility.generated.h"

/**
 * 
 */
UCLASS(Abstract)
class FPS_API UPlayerMovementAbility : public UBasePlayerAbility
{
	GENERATED_BODY()

public:
UPROPERTY(BlueprintReadOnly)
	FVector2D MovementInput;
protected:

private:
	
public:

protected:
	virtual void OnGiveAbility(const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilitySpec& Spec) override;

	virtual void OnInputTriggered_Implementation(const FInputActionValue& InputActionValue) override;
private:
	//void CharacterMove(const FInputActionValue& InputActionValue);

	
	
	
};
