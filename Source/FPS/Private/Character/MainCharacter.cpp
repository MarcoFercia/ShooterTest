// © 2025 Marco Fernandez garcia <marcoferciatr@gmail.com>


#include "Character/MainCharacter.h"
#include "Character/Components/ActiveWeaponComponent.h"
#include "DataAssets/WeaponDataAsset.h"
#include "GAS/FPSAbilitySystemComponent.h"


// Sets default values
AMainCharacter::AMainCharacter(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	WeaponComponent = CreateDefaultSubobject<UActiveWeaponComponent>("Active Weapon Component");
	
	
}

UActiveWeaponComponent* AMainCharacter::GetWeaponComponent()
{
	return WeaponComponent.Get();
}

// Called when the game starts or when spawned
void AMainCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}


// Called every frame
void AMainCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void AMainCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	AbilitySystemComponent->BindToInputComponent(PlayerInputComponent);
}

