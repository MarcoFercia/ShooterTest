// © 2025 Marco Fernandez garcia <marcoferciatr@gmail.com>

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "PlayerHUD.generated.h"

class UAbilitySystemComponent;
/**
 * 
 */
class UPlayerHUDWidget;

UCLASS()
class FPS_API APlayerHUD : public AHUD
{
	GENERATED_BODY()
	
public:
	
protected:
	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<UPlayerHUDWidget> PLayerHUDWidgetClass;

	TObjectPtr<UPlayerHUDWidget> HUDWidgetRef;
	
private:
	
public:
	UFUNCTION(BlueprintCallable) 
	UPlayerHUDWidget* GetPlayerHUDWidget();

	UFUNCTION(BlueprintCallable) 
	bool InitializeHUD(UAbilitySystemComponent* _ASC);

	virtual void BeginPlay() override;
protected:
	
private:
	void CreateWidgetHUD();
	
	
};
