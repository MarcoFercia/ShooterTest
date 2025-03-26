// © 2025 Marco Fernandez garcia <marcoferciatr@gmail.com>

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

virtual void BeginPlay() override;
	
private:
	
};
