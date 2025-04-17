// © 2025 Marco Fernandez garcia <marcoferciatr@gmail.com>


#include "Character/BaseFPSCharacter.h"
#include "GAS/FPSAbilitySystemComponent.h"



ABaseFPSCharacter::ABaseFPSCharacter(const FObjectInitializer& ObjectInitializer)
{
	PrimaryActorTick.bCanEverTick = true;
	AbilitySystemComponent = CreateDefaultSubobject<UFPSAbilitySystemComponent>("Ability System Component");
}

// Called when the game starts or when spawned
void ABaseFPSCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABaseFPSCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


void ABaseFPSCharacter::DeathCharacter_Implementation()
{
	
}
