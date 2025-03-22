// Fill out your copyright notice in the Description page of Project Settings.


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

	// AActor* test = ActorInfo->OwnerActor.Get();
	// AMainCharacterController* MyController = Cast<AMainCharacterController>(test->GetInstigatorController());	
	// UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(MyController->InputComponent);
	// if (!MyController->InputConfig ||!MyController->InputConfig->MoveAction )
	// {
	// 	return;
	// }
	// EnhancedInputComponent->BindAction(MyController->InputConfig->MoveAction,ETriggerEvent::Triggered,this, &UPlayerMovementAbility::CharacterMove);
	
}

void UPlayerMovementAbility::OnInputTriggered_Implementation(const FInputActionValue& InputActionValue)
{
	MovementInput = InputActionValue.Get<FVector2D>();
	Super::OnInputTriggered_Implementation(InputActionValue);
}

// void UPlayerMovementAbility::CharacterMove(const FInputActionValue& InputActionValue)
// {
// 	MovementInput = InputActionValue.Get<FVector2D>();
// 	UAbilitySystemBlueprintLibrary::SendGameplayEventToActor(GetAvatarActorFromActorInfo(),GET_TAG(INPUT_MOVE_TAG),FGameplayEventData());
// }
