// © 2025 Marco Fernandez garcia <marcoferciatr@gmail.com>


#include "UI/PlayerHUD.h"
#include "UI/PlayerHUDWidget.h"
#include "Blueprint/UserWidget.h"


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

void APlayerHUD::AddToHUD(UFerciaUserWidget* _Widget)
{
	_Widget->AddToViewport(0);
	HUDWidgets.AddUnique(_Widget);
}

void APlayerHUD::ShowHUD()
{
	Super::ShowHUD();
	
	for (UFerciaUserWidget* it : HUDWidgets)
	{
		it->SetHideFromHUD(!bShowHUD);		
	}
}


void APlayerHUD::CreateWidgetHUD()
{
	if (PLayerHUDWidgetClass)
	{
		HUDWidgetRef = CreateWidget<UPlayerHUDWidget>(PlayerOwner, PLayerHUDWidgetClass);
		AddToHUD(HUDWidgetRef);
	}
}
