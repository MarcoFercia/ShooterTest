// © 2025 Marco Fernandez garcia <marcoferciatr@gmail.com>


#include "GAS/Abilities/BasePlayerAbilityWithWidget.h"
#include "Blueprint/UserWidget.h"
#include "Character/MainCharacter.h"
#include "Character/MainCharacterController.h"
#include "UI/PlayerHUD.h"
#include "Widgets/BaseWidgets/FerciaUserWidget.h"


UBasePlayerAbilityWithWidget::UBasePlayerAbilityWithWidget(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	
}

UFerciaUserWidget* UBasePlayerAbilityWithWidget::GetWidgetRef()
{
	return WidgetRef;
}

void UBasePlayerAbilityWithWidget::OnGiveAbility(const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilitySpec& Spec)
{
	AMainCharacter* PlayerActor = Cast<AMainCharacter>(ActorInfo->OwnerActor);
	AMainCharacterController* PlayerController =PlayerActor->GetController<AMainCharacterController>();
	APlayerHUD* PlayerHUD = PlayerController->GetHUD<APlayerHUD>();
	WidgetRef = Cast<UFerciaUserWidget>(UUserWidget::CreateWidgetInstance(*PlayerController,WidgetClass,MakeUniqueObjectName(this,WidgetClass)));
	PlayerHUD->AddToHUD(WidgetRef);
	if (bShowOnlyWhileAbilityIsActive)
	{
		WidgetRef->SetVisibility(ESlateVisibility::Hidden);
	}

	Super::OnGiveAbility(ActorInfo, Spec);
}

void UBasePlayerAbilityWithWidget::ActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, const FGameplayEventData* TriggerEventData)
{
	Super::ActivateAbility(Handle, ActorInfo, ActivationInfo, TriggerEventData);
	if (bShowOnlyWhileAbilityIsActive)
	{
		WidgetRef->SetVisibility(ESlateVisibility::Visible);
	}
	
}

void UBasePlayerAbilityWithWidget::EndAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, bool bReplicateEndAbility, bool bWasCancelled)
{
	Super::EndAbility(Handle, ActorInfo, ActivationInfo, bReplicateEndAbility, bWasCancelled);
	if (bShowOnlyWhileAbilityIsActive)
	{
		WidgetRef->SetVisibility(ESlateVisibility::Hidden);
	}
}
