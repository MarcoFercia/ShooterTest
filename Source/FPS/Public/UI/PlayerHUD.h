// © 2025 Marco Fernandez garcia <marcoferciatr@gmail.com>

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "PlayerHUD.generated.h"

class UFerciaUserWidget;
class UAbilitySystemComponent;
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


TArray<UFerciaUserWidget*> HUDWidgets;
	
private:
	
public:
	UFUNCTION(BlueprintCallable) 
	UPlayerHUDWidget* GetPlayerHUDWidget();

	UFUNCTION(BlueprintCallable) 
	bool InitializeHUD(UAbilitySystemComponent* _ASC);

	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable)
	void AddToHUD(UFerciaUserWidget* _Widget);

	
	


	
protected:

	virtual void ShowHUD() override;
	
private:
	void CreateWidgetHUD();
	
	
};
