// © 2025 Marco Fernandez garcia <marcoferciatr@gmail.com>


#include "UI/ProgressBarWithTextWidget.h"
#include "Widgets/BaseWidgets/FerciaText.h"



void UProgressBarWithTextWidget::UpdateUI()
{
	Super::UpdateUI();
	
	ActualValueText->SetText(FText::AsNumber(ActualValue));
	MaxValueText->SetText(FText::AsNumber(MaxValue));	

}

