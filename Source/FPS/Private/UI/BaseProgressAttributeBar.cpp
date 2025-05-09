// © 2025 Marco Fernandez garcia <marcoferciatr@gmail.com>


#include "UI/BaseProgressAttributeBar.h"
#include "GAS/AsyncTaskAttributeChanged.h"
#include "AbilitySystemBlueprintLibrary.h"
#include "Widgets/BaseWidgets/FerciaProgressBar.h"

void UBaseProgressAttributeBar::NativeConstruct()
{
	Super::NativeConstruct();	
}


bool UBaseProgressAttributeBar::InitializeUI(UAbilitySystemComponent* _ASC)
{
	if (!_ASC)
	{
		return false;
	}
	
	ActualListenTask = UAsyncTaskAttributeChanged::ListenForAttributeChange(_ASC,actualAttribute);
	if (!ActualListenTask)
	{
		return false;
	}
	ActualListenTask->OnAttributeChanged.AddDynamic(this,&UBaseProgressAttributeBar::OnActualAttributeChanged);

	MaxListenTask = UAsyncTaskAttributeChanged::ListenForAttributeChange(_ASC,MaxAttribute);
	if (!MaxListenTask)
	{
		return false;
	}
	MaxListenTask->OnAttributeChanged.AddDynamic(this,&UBaseProgressAttributeBar::OnMaxAttributeChanged);
	
	ActualValue = _ASC->GetNumericAttribute(actualAttribute);
	MaxValue = _ASC->GetNumericAttribute(MaxAttribute);	
	UpdateUI();

	ActualListenTask->Activate();
	MaxListenTask->Activate();
	return true;
}


void UBaseProgressAttributeBar::OnActualAttributeChanged(FGameplayAttribute Attribute, float NewValue, float OldValue)
{
	ActualValue = NewValue;
	UpdateUI();
}
void UBaseProgressAttributeBar::OnMaxAttributeChanged(FGameplayAttribute Attribute, float NewValue, float OldValue)
{
	MaxValue = NewValue;
	UpdateUI();
}

void UBaseProgressAttributeBar::UpdateUI()
{
	float temp = ActualValue / MaxValue;
	ProgressBar->SetPercent(temp);	
}




void UBaseProgressAttributeBar::NativeDestruct()
{
	Super::NativeDestruct();

	if (MaxListenTask)
	{
		MaxListenTask->EndTask();
		MaxListenTask = nullptr;
	}

	
	if (ActualListenTask)
	{
		ActualListenTask->EndTask();
		ActualListenTask = nullptr;
	}
}
