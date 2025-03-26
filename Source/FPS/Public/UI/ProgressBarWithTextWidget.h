// © 2025 Marco Fernandez garcia <marcoferciatr@gmail.com>

#pragma once

#include "CoreMinimal.h"
#include "BaseProgressAttributeBar.h"
#include "ProgressBarWithTextWidget.generated.h"


class UFerciaText;

/**
 * 
 */
UCLASS()
class FPS_API UProgressBarWithTextWidget : public UBaseProgressAttributeBar
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere,BlueprintReadWrite, meta= (BindWidget))
	UFerciaText* ActualValueText;

	UPROPERTY(EditAnywhere,BlueprintReadWrite, meta= (BindWidget))
	UFerciaText* MaxValueText;
	
protected:
	
private:	
public:

	UFUNCTION()
	virtual void UpdateUI() override;
	
protected:
	
private:	
	
};
