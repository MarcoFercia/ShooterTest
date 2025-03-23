// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "Widgets/BaseWidgets/FerciaUserWidget.h"
#include "ProgressBarWithTextWidget.generated.h"

class UFerciaProgressBar;
class UFerciaText;
class UAsyncTaskAttributeChanged;
/**
 * 
 */
UCLASS()
class FPS_API UProgressBarWithTextWidget : public UFerciaUserWidget
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere,BlueprintReadWrite, meta= (BindWidget))
	UFerciaText* ActualValueText;

	UPROPERTY(EditAnywhere,BlueprintReadWrite, meta= (BindWidget))
	UFerciaText* MaxValueText;

	UPROPERTY(EditAnywhere,BlueprintReadWrite, meta= (BindWidget))
	UFerciaProgressBar* ProgressBar;

	UPROPERTY(EditDefaultsOnly, Category = "Attributes To Scan")
	FGameplayAttribute actualAttribute;
	UPROPERTY(EditDefaultsOnly,Category = "Attributes To Scan")
	FGameplayAttribute MaxAttribute;
	
protected:


	
private:

	UPROPERTY()
	float ActualValue;
	UPROPERTY()
	float MaxValue;

	UPROPERTY()
	UAsyncTaskAttributeChanged* ActualListenTask;
	UPROPERTY()
	UAsyncTaskAttributeChanged* MaxListenTask;
	
public:

	UFUNCTION()
	void UpdateUI();
	
protected:
	UFUNCTION()
	void OnActualAttributeChanged(FGameplayAttribute Attribute, float NewValue, float OldValue);
	UFUNCTION()
	void OnMaxAttributeChanged(FGameplayAttribute Attribute, float NewValue, float OldValue);

	virtual void NativeConstruct() override;
	virtual void NativeDestruct() override;
	
private:
	
	
};
