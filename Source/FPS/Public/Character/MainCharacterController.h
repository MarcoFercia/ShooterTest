// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InputActionValue.h"
#include "GameFramework/PlayerController.h"
#include "MainCharacterController.generated.h"

/**
 * 
 */
class UInputActionsConfiguration;
UCLASS()
class FPS_API AMainCharacterController : public APlayerController
{
	GENERATED_BODY()

protected:


public:
	UPROPERTY(EditDefaultsOnly)
	TObjectPtr<UInputActionsConfiguration> InputConfig;

protected:
	
	
private:
	
public:

protected:
	void SetupInputComponent() override;
	void CharacterMove(const FInputActionValue& InputActionValue);
	
private:
	
};
