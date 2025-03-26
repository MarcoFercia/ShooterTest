// © 2025 Marco Fernandez garcia <marcoferciatr@gmail.com>


#include "Character/MainCharacterController.h"

#include "AbilitySystemBlueprintLibrary.h"
#include "EnhancedInputComponent.h"
#include "DataAssets/InputActionsConfiguration.h"
#include "UI/PlayerHUD.h"


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

void AMainCharacterController::BeginPlay()
{
	Super::BeginPlay();
	APlayerHUD* playerHUD = Cast<APlayerHUD>(GetHUD());
	if (!playerHUD)
	{
		return;
	}
	playerHUD->InitializeHUD(UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(GetPawn()));	
}
