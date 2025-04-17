// © 2025 Marco Fernandez garcia <marcoferciatr@gmail.com>


#include "Enemies/EnemyCharacter.h"
#include "DataAssets/EnemyBuilderDataAsset.h"
#include "Enemies/Components/BaseWidgetComponent.h"
#include "GAS/FPSAbilitySystemComponent.h"
#include "Components/StateTreeAIComponent.h"
#include "DataAssets/AbilitiesDataAsset.h"
#include "Enemies/BaseFPSEnemyController.h"
#include "Enemies/BaseStateTreeComponent.h"


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
	
	ABaseFPSEnemyController* controller = Cast<ABaseFPSEnemyController>(GetController());
	controller->StateTreeAIComponent->SetStateTreeAsset(EnemyAsset->StateTreeSchema);
	
	AbilitySystemComponent->GiveAbilitiesToOwner(EnemyAsset->AbilitiesDataAsset->Abilities);
	AbilitySystemComponent->InitializeAttributes(EnemyAsset->attributesForEnemy);	
	AbilitySystemComponent->ApplyGameplayEffect(EnemyAsset->GameplayEffectClass);

	return true;
	
}

bool AEnemyCharacter::clearEnemy()
{
	AbilitySystemComponent->RemoveAllSpawnedAttributes();
	AbilitySystemComponent->ClearAllAbilities();
	FGameplayEffectQuery test1;
	const FActiveGameplayEffectsContainer& test = AbilitySystemComponent->GetActiveGameplayEffects() ;
	TArray<FActiveGameplayEffectHandle> activeEffectsHandles = test.GetAllActiveEffectHandles();

	for (auto it : activeEffectsHandles)
	{
		AbilitySystemComponent->RemoveActiveGameplayEffect(it);
	}
	
	return true;
}

void AEnemyCharacter::BeginPlay()
{
	Super::BeginPlay();

	if (BuildDataAsset)
	{
		InitializeEnemy(BuildDataAsset);
		StartLogic();
	}	
}


void AEnemyCharacter::StartLogic()
{
	ABaseFPSEnemyController* controller = Cast<ABaseFPSEnemyController>(GetController());
	controller->StateTreeAIComponent->StartLogic();
}


void AEnemyCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}
