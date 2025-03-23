// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/ProgressBarWithTextWidget.h"

#include "AbilitySystemBlueprintLibrary.h"
#include "GAS/AsyncTaskAttributeChanged.h"
#include "Widgets/BaseWidgets/FerciaProgressBar.h"
#include "Widgets/BaseWidgets/FerciaText.h"





void UProgressBarWithTextWidget::NativeConstruct()
{
	Super::NativeConstruct();
	
	UAbilitySystemComponent* ASC =	UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(GetOwningPlayer()->GetPawn());
	
	if (!ASC)
	{
		return;
	}
	
	ActualListenTask = UAsyncTaskAttributeChanged::ListenForAttributeChange(ASC,actualAttribute);
	if (!ActualListenTask)
	{
		return;
	}
	ActualListenTask->OnAttributeChanged.AddDynamic(this,&UProgressBarWithTextWidget::OnActualAttributeChanged);

	MaxListenTask = UAsyncTaskAttributeChanged::ListenForAttributeChange(ASC,MaxAttribute);
	if (!MaxListenTask)
	{
		return;
	}
	MaxListenTask->OnAttributeChanged.AddDynamic(this,&UProgressBarWithTextWidget::OnMaxAttributeChanged);
	
	ActualValue = ASC->GetNumericAttribute(actualAttribute);
	MaxValue = ASC->GetNumericAttribute(MaxAttribute);	
	UpdateUI();

	ActualListenTask->Activate();
	MaxListenTask->Activate();
}

void UProgressBarWithTextWidget::OnActualAttributeChanged(FGameplayAttribute Attribute, float NewValue, float OldValue)
{
	ActualValue = NewValue;
	UpdateUI();
}
void UProgressBarWithTextWidget::OnMaxAttributeChanged(FGameplayAttribute Attribute, float NewValue, float OldValue)
{
	MaxValue = NewValue;
	UpdateUI();
}

void UProgressBarWithTextWidget::UpdateUI()
{
	ActualValueText->SetText(FText::AsNumber(ActualValue));
	MaxValueText->SetText(FText::AsNumber(MaxValue));	
	float temp = ActualValue / MaxValue;
	ProgressBar->SetPercent(temp);	
}

void UProgressBarWithTextWidget::NativeDestruct()
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
