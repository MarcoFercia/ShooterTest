// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Widgets/BaseWidgets/FerciaUserWidget.h"
#include "PlayerHUDWidget.generated.h"

/**
 * 
 */
class UProgressBarWithTextWidget;


UCLASS()
class FPS_API UPlayerHUDWidget : public UFerciaUserWidget
{
	GENERATED_BODY()
	
public:

	UPROPERTY(EditAnywhere,BlueprintReadWrite, meta= (BindWidget))
	UProgressBarWithTextWidget* HealthBarWidget;

	UPROPERTY(EditAnywhere,BlueprintReadWrite, meta= (BindWidget))
	UProgressBarWithTextWidget* AmmoBarWidget;
	
protected:

private:

public:
	
protected:

private:
	
	
};
