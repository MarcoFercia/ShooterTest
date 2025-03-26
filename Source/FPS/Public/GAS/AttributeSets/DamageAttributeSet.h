// © 2025 Marco Fernandez garcia <marcoferciatr@gmail.com>

#pragma once

#include "CoreMinimal.h"
#include "GAS/AttributeSets/BaseAttributeSet.h"
#include "DamageAttributeSet.generated.h"

/**
 * 
 */
UCLASS()
class FPS_API UDamageAttributeSet : public UBaseAttributeSet
{
	GENERATED_BODY()
	

public:
	
	UPROPERTY(BlueprintReadOnly, Category = "Damage")
	FGameplayAttributeData Damage;
	
protected:

private:

public:	

	ATTRIBUTE_ACCESSORS(UDamageAttributeSet,Damage);

	
protected:

private:	
	
	
	
};
