// © 2025 Marco Fernandez garcia <marcoferciatr@gmail.com>

#pragma once

#include "CoreMinimal.h"
#include "Widgets/BaseWidgets/FerciaUserWidget.h"
#include "PlayerHUDWidget.generated.h"

class UAbilitySystemComponent;
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

bool InitializeUIAndDelegates(UAbilitySystemComponent* _ASC);
	
protected:

private:
	
	
};
