// © 2025 Marco Fernandez garcia <marcoferciatr@gmail.com>


#include "Enemies/EnemyCharacter.h"
#include "DataAssets/EnemyBuilderDataAsset.h"
#include "Enemies/Components/BaseWidgetComponent.h"
#include "GAS/FPSAbilitySystemComponent.h"


AEnemyCharacter::AEnemyCharacter(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	HealthBarComponent = CreateDefaultSubobject<UBaseWidgetComponent>("Health Bar UI");
	HealthBarComponent->SetupAttachment(GetRootComponent());
}

bool AEnemyCharacter::InitializeEnemy(UEnemyBuilderDataAsset* EnemyAsset)
{
	if (!EnemyAsset || !EnemyAsset->CheckInformationFilled())
	{
		return false;
	}

	
	GetMesh()->SetSkeletalMesh(EnemyAsset->EnemyMesh);
	HealthBarComponent->SetWidgetClass(EnemyAsset->HealthBarWidgetClass);
	HealthBarComponent->InitializeBarWidget(AbilitySystemComponent);	
	AbilitySystemComponent->ApplyGameplayEffect(EnemyAsset->GameplayEffectClass);	
	
	return true;
	
}

void AEnemyCharacter::BeginPlay()
{
	Super::BeginPlay();

	if (BuildDataAsset)
	{
		InitializeEnemy(BuildDataAsset);
	}	
}

void AEnemyCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}
