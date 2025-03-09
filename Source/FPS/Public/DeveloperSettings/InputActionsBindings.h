// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InputAction.h"
#include "Engine/DeveloperSettings.h"
#include "InputActionsBindings.generated.h"

class UInputAction;
/**
 * 
 */
UCLASS(Config = Game, defaultconfig, meta = (DisplayName = "Input Actions Bindings"))
class FPS_API UInputActionsBindings : public UDeveloperSettings
{
	GENERATED_BODY()
public:
	UPROPERTY(config, EditAnywhere, Category="Input", meta=(AllowedClasses="/Script/EnhancedInput.InputAction", DisplayName="Left Input Action"))
	FSoftObjectPath LeftMouseAction;
	
	UPROPERTY(config, EditAnywhere, Category="Input", meta=(AllowedClasses="/Script/EnhancedInput.InputAction", DisplayName="Right Input Action"))
	FSoftObjectPath RightMouseAction;
	
};
