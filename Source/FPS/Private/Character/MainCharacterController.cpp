// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/MainCharacterController.h"

#include "EnhancedInputComponent.h"
#include "DataAssets/InputActionsConfiguration.h"


void AMainCharacterController::SetupInputComponent()
{
	Super::SetupInputComponent();
	UEnhancedInputComponent* EnhancedInput = Cast<UEnhancedInputComponent>(InputComponent);
	if (!InputConfig)
	{
		return;
	}
	
	EnhancedInput->BindAction(InputConfig->MoveAction,ETriggerEvent::Triggered,this, &AMainCharacterController::CharacterMove);
	
}

void AMainCharacterController::CharacterMove(const FInputActionValue& InputActionValue)
{
	
}
