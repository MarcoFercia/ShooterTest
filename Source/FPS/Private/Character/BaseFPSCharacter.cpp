// © 2025 Marco Fernandez garcia <marcoferciatr@gmail.com>


#include "Character/BaseFPSCharacter.h"
#include "GAS/FPSAbilitySystemComponent.h"


// Sets default values
ABaseFPSCharacter::ABaseFPSCharacter(const FObjectInitializer& ObjectInitializer)
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
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

// Called to bind functionality to input
void ABaseFPSCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

