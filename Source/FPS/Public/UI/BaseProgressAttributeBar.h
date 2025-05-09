// © 2025 Marco Fernandez garcia <marcoferciatr@gmail.com>

#pragma once

#include "CoreMinimal.h"
#include "Widgets/BaseWidgets/FerciaUserWidget.h"
#include "AttributeSet.h"
#include "BaseProgressAttributeBar.generated.h"

/**
 * 
 */

class UFerciaProgressBar;
class UAsyncTaskAttributeChanged;

UCLASS()
class FPS_API UBaseProgressAttributeBar : public UFerciaUserWidget
{
	GENERATED_BODY()
public:

	UPROPERTY(EditAnywhere,BlueprintReadWrite, meta= (BindWidget))
	UFerciaProgressBar* ProgressBar;

	UPROPERTY(EditAnywhere, Category = "Attributes To Scan")
	FGameplayAttribute actualAttribute;
	UPROPERTY(EditAnywhere,Category = "Attributes To Scan")
	FGameplayAttribute MaxAttribute;
	
protected:

	UPROPERTY()
	float ActualValue;
	UPROPERTY()
	float MaxValue;

	UPROPERTY()
	UAsyncTaskAttributeChanged* ActualListenTask;
	UPROPERTY()
	UAsyncTaskAttributeChanged* MaxListenTask;
	
private:


	
public:

	virtual void UpdateUI();
	UFUNCTION(BlueprintCallable)
	bool InitializeUI(UAbilitySystemComponent* _ASC);

	
protected:

	UFUNCTION()
	void OnActualAttributeChanged(FGameplayAttribute Attribute, float NewValue, float OldValue);
	UFUNCTION()
	void OnMaxAttributeChanged(FGameplayAttribute Attribute, float NewValue, float OldValue);

	virtual void NativeConstruct() override;
	virtual void NativeDestruct() override;
	
private:

	
	
	
};
