// © 2025 Marco Fernandez garcia <marcoferciatr@gmail.com>


#include "GAS/AttributeSets/MovementAttributeSet.h"

#include "Character/BaseFPSCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"


void UMovementAttributeSet::PreAttributeBaseChange(const FGameplayAttribute& Attribute, float& NewValue) const
{
	Super::PreAttributeBaseChange(Attribute, NewValue);
	
	if (Attribute == GetSpeedAttribute())
	{
		NewValue = FMath::Max(NewValue,1.f);
	}
}

void UMovementAttributeSet::PostAttributeChange(const FGameplayAttribute& Attribute, float OldValue, float NewValue)
{
	Super::PostAttributeChange(Attribute, OldValue, NewValue);

	if (Attribute == GetSpeedAttribute())
	{
		ABaseFPSCharacter* character = Cast<ABaseFPSCharacter>( GetOwningActor());
		character->GetCharacterMovement()->MaxWalkSpeed = NewValue;
	}
}
