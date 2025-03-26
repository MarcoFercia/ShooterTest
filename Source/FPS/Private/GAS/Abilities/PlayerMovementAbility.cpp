// © 2025 Marco Fernandez garcia <marcoferciatr@gmail.com>


#include "GAS/Abilities/PlayerMovementAbility.h"

#include "AbilitySystemBlueprintLibrary.h"
#include "AbilitySystemComponent.h"
#include "EnhancedInputComponent.h"
#include "Character/MainCharacterController.h"
#include "Core/TagsMacros.h"
#include "DataAssets/InputActionsConfiguration.h"


void UPlayerMovementAbility::OnGiveAbility(const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilitySpec& Spec)
{
	Super::OnGiveAbility(ActorInfo, Spec);
}

void UPlayerMovementAbility::OnInputTriggered_Implementation(const FInputActionValue& InputActionValue)
{
	MovementInput = InputActionValue.Get<FVector2D>();
	Super::OnInputTriggered_Implementation(InputActionValue);
}

