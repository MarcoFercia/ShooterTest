// © 2025 Marco Fernandez garcia <marcoferciatr@gmail.com>


#include "Enemies/Components/BaseWidgetComponent.h"

#include "UI/BaseProgressAttributeBar.h"


bool UBaseWidgetComponent::InitializeBarWidget(UAbilitySystemComponent* _ASC)
{
	UBaseProgressAttributeBar* WidgetBar = Cast<UBaseProgressAttributeBar>(GetWidget());

	if (!WidgetBar)
	{
		return false;
	}
	
	return WidgetBar->InitializeUI(_ASC);	
}
