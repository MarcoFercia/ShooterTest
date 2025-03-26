// © 2025 Marco Fernandez garcia <marcoferciatr@gmail.com>


#include "UI/PlayerHUDWidget.h"

#include "UI/ProgressBarWithTextWidget.h"

bool UPlayerHUDWidget::InitializeUIAndDelegates(UAbilitySystemComponent* _ASC)
{
	bool success = true;
	
	if (!HealthBarWidget->InitializeUI(_ASC))
	{
		return false;
	}

	if (!AmmoBarWidget->InitializeUI(_ASC))
	{
		return false;
	}

	return true;
	
}
