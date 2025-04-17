// © 2025 Marco Fernandez garcia <marcoferciatr@gmail.com>


#include "GAS/Abilities/BasePlayerAbility.h"
#include "AbilitySystemBlueprintLibrary.h"
#include "AbilitySystemComponent.h"
#include "EnhancedInputComponent.h"
#include "Character/MainCharacter.h"
#include "Character/MainCharacterController.h"


UBasePlayerAbility::UBasePlayerAbility(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	InstancingPolicy = EGameplayAbilityInstancingPolicy::Type::InstancedPerActor;
}

void UBasePlayerAbility::OnGiveAbility(const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilitySpec& Spec)
{
	Super::OnGiveAbility(ActorInfo, Spec);
	CurrentActorInfo = ActorInfo;
	PlayerCharacter = Cast<AMainCharacter>(ActorInfo->OwnerActor);	
	AMainCharacterController* MyController = Cast<AMainCharacterController>(PlayerCharacter->GetController());	
	UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(MyController->InputComponent);
	if (!InputAction)
	{
		return;
	}
	
	if (EnumHasAnyFlags(static_cast<ETriggerEvent>(FunctionsToBind),ETriggerEvent::Triggered))
	{
		FEnhancedInputActionEventBinding* temp = &EnhancedInputComponent->BindAction(InputAction,ETriggerEvent::Triggered,this, &UBasePlayerAbility::OnInputTriggered);
		InputBindings.Add(temp);
	}
	if (EnumHasAnyFlags(static_cast<ETriggerEvent>(FunctionsToBind),ETriggerEvent::Started))
	{
		FEnhancedInputActionEventBinding* temp = &EnhancedInputComponent->BindAction(InputAction,ETriggerEvent::Started,this, &UBasePlayerAbility::OnInputStarted);
		InputBindings.Add(temp);
	}
	if (EnumHasAnyFlags(static_cast<ETriggerEvent>(FunctionsToBind),ETriggerEvent::Ongoing))
	{
		FEnhancedInputActionEventBinding* temp = &EnhancedInputComponent->BindAction(InputAction,ETriggerEvent::Ongoing,this, &UBasePlayerAbility::OnInputOnGoing);
		InputBindings.Add(temp);
	}
	if (EnumHasAnyFlags(static_cast<ETriggerEvent>(FunctionsToBind),ETriggerEvent::Canceled))
	{
		FEnhancedInputActionEventBinding* temp = &EnhancedInputComponent->BindAction(InputAction,ETriggerEvent::Canceled,this, &UBasePlayerAbility::OnInputCanceled);
		InputBindings.Add(temp);
	}
	if (EnumHasAnyFlags(static_cast<ETriggerEvent>(FunctionsToBind),ETriggerEvent::Completed))
	{
		FEnhancedInputActionEventBinding* temp = &EnhancedInputComponent->BindAction(InputAction,ETriggerEvent::Completed,this, &UBasePlayerAbility::OnInputCompleted);
		InputBindings.Add(temp);
	}
	
	OnGivenAbility(*ActorInfo,Spec);
}

void UBasePlayerAbility::OnRemoveAbility(const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilitySpec& Spec)
{
	Super::OnRemoveAbility(ActorInfo, Spec);

	if (AbilityPolicy == Active)
	{
		AMainCharacterController* MyController = Cast<AMainCharacterController>(PlayerCharacter->GetController());
		if (!MyController)
		{
			return;
		}
		UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(MyController->InputComponent);
		if (!EnhancedInputComponent)
		{
			return;
		}		
		for (auto it : InputBindings)
		{
			EnhancedInputComponent->RemoveActionBinding(it->GetHandle());
		}			
	}
}

void UBasePlayerAbility::OnInputTriggered_Implementation(const FInputActionValue& InputActionValue)
{
	if (bStartAbilityFromCode && ActivationMethod == EActivationMethod::Triggered)
	{
		CurrentActorInfo->AbilitySystemComponent->TryActivateAbilityByClass(this->GetClass());
	}
}

void UBasePlayerAbility::OnInputStarted_Implementation(const FInputActionValue& InputActionValue)
{
	if (bStartAbilityFromCode && ActivationMethod == EActivationMethod::Started)
	{
		CurrentActorInfo->AbilitySystemComponent->TryActivateAbilityByClass(this->GetClass());
	}
}

void UBasePlayerAbility::OnInputOnGoing_Implementation(const FInputActionValue& InputActionValue)
{
	
}

void UBasePlayerAbility::OnInputCanceled_Implementation(const FInputActionValue& InputActionValue)
{
	
}

void UBasePlayerAbility::OnInputCompleted_Implementation(const FInputActionValue& InputActionValue)
{
	
}

