// Fill out your copyright notice in the Description page of Project Settings.


#include "Animation/AnimInstanceWithGameplayTags.h"

#include "GameplayTagContainer.h"
#include "Character/MainCharacter.h"
#include "GAS/FPSAbilitySystemComponent.h"


bool UAnimInstanceWithGameplayTags::HasTag(FGameplayTag _TagToCheck,bool DebugPreview)
{
#if WITH_EDITOR

	if (!AbilitySystemComponent)
	{
		return DebugPreview;
	}
#endif

	ensure(AbilitySystemComponent);
	return AbilitySystemComponent->HasAnyMatchingGameplayTags(FGameplayTagContainer(_TagToCheck));

	
}

void UAnimInstanceWithGameplayTags::NativeBeginPlay()
{
	Super::NativeBeginPlay();
	AbilitySystemComponent = Cast<AMainCharacter>(TryGetPawnOwner())->AbilitySystemComponent;
	ensure(AbilitySystemComponent);
}
