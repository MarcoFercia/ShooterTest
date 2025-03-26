// © 2025 Marco Fernandez garcia <marcoferciatr@gmail.com>


#include "UI/PlayerHUD.h"

#include "UI/PlayerHUDWidget.h"


UPlayerHUDWidget* APlayerHUD::GetPlayerHUDWidget()
{
	return HUDWidgetRef;
}

bool APlayerHUD::InitializeHUD(UAbilitySystemComponent* _ASC)
{
	if (!HUDWidgetRef)
	{
		CreateWidgetHUD();
	}	
	return 	HUDWidgetRef->InitializeUIAndDelegates(_ASC);
}

void APlayerHUD::BeginPlay()
{
	Super::BeginPlay();
	
	if (!HUDWidgetRef)
	{
		CreateWidgetHUD();
	}
}

void APlayerHUD::CreateWidgetHUD()
{
	if (PLayerHUDWidgetClass)
	{
		HUDWidgetRef = CreateWidget<UPlayerHUDWidget>(PlayerOwner, PLayerHUDWidgetClass);
		HUDWidgetRef->AddToViewport();
	}
}
