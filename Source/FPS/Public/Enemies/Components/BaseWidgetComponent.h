// © 2025 Marco Fernandez garcia <marcoferciatr@gmail.com>

#pragma once

#include "CoreMinimal.h"
#include "Components/WidgetComponent.h"
#include "BaseWidgetComponent.generated.h"

class UAbilitySystemComponent;
/**
 * 
 */
UCLASS()
class FPS_API UBaseWidgetComponent : public UWidgetComponent
{
	GENERATED_BODY()
	
public:
	
protected:

private:
	
public:

	bool InitializeBarWidget(UAbilitySystemComponent* _ASC);
protected:

private:
	
};
