// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/Components/ActiveWeaponComponent.h"
#include "AbilitySystemBlueprintLibrary.h"
#include "AbilitySystemComponent.h"
#include "EnhancedInputSubsystems.h"
#include "Character/MainCharacter.h"
#include "GAS/AttributeSets/AmmoAttrubites.h"
#include "Kismet/KismetSystemLibrary.h"

// Sets default values for this component's properties
UActiveWeaponComponent::UActiveWeaponComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	SkeletalWeaponMesh = CreateDefaultSubobject<USkeletalMeshComponent>("SkeletalMeshComponent");
	StaticWeaponMesh = CreateDefaultSubobject<UStaticMeshComponent>("StaticMeshComponent");	
}


// Called when the game starts
void UActiveWeaponComponent::BeginPlay()
{
	Super::BeginPlay();	
}

bool UActiveWeaponComponent::RemoveWeapon()
{
	if (!ActualWeapon)
	{
		return false;
	}
	
	return ClearOldWeapon();
}

bool UActiveWeaponComponent::ClearOldWeapon()
{
	UAbilitySystemComponent* ASC = UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(GetOwner());
	if (!ASC)
	{
		return false;
	}


	//Remove Abilities
	if (LeftAbilityHandle.IsValid())
	{
		ASC->ClearAbility(LeftAbilityHandle);
	}
	if (RightAbilityHandle.IsValid())
	{
		ASC->ClearAbility(RightAbilityHandle);
	}


	//Clear Weapon Mesh
	SkeletalWeaponMesh->SetSkeletalMesh(nullptr);
	StaticWeaponMesh->SetStaticMesh(nullptr);
	SkeletalWeaponMesh->SetVisibility(false);
	StaticWeaponMesh->SetVisibility(false);
	SkeletalWeaponMesh->SetMaterial(0,nullptr);
	StaticWeaponMesh->SetMaterial(0,nullptr);
	FDetachmentTransformRules detachmentRules = FDetachmentTransformRules(EDetachmentRule::KeepRelative,false);
	SkeletalWeaponMesh->DetachFromComponent(detachmentRules);
	StaticWeaponMesh->DetachFromComponent(detachmentRules);

	//Clear GameplayTags
	ASC->RemoveLooseGameplayTags(ActualWeapon->WeaponTags);

	//Clear Ammo
	ASC->SetNumericAttributeBase(UAmmoAttributes::GetMaxAmmoAttribute(),0);
	ASC->SetNumericAttributeBase(UAmmoAttributes::GetAmmoAttribute(),0);
	ASC->SetNumericAttributeBase(UAmmoAttributes::GetReloadTimeAttribute(),0);

	
	//Remove Mapping Context

	if (ActualWeapon->WeaponMappingContext)
	{
		AMainCharacter* MainCharacter = Cast<AMainCharacter>(GetOwner());
		if (APlayerController* PlayerController = Cast<APlayerController>(MainCharacter->GetController()))
		{
			if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
			{
				Subsystem->RemoveMappingContext(ActualWeapon->WeaponMappingContext);
			}
		}
	}	
	ActualWeapon = nullptr;
	return true;
}

bool UActiveWeaponComponent::AssignNewWeapon(UWeaponDataAsset* _NewWeapon)
{

	//Try Get ASC
	UAbilitySystemComponent* ASC = UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(GetOwner());
	if (!ASC)
	{
		return false;
	}

	//Mesh
	switch (_NewWeapon->WeaponMeshType)
	{
		case EWeaponTypeMesh::SkeletalMesh:
		{
			USceneComponent* root = Cast<AMainCharacter>(GetOwner())->GetMeshToAttach();
			SkeletalWeaponMesh->AttachToComponent(root,FAttachmentTransformRules(EAttachmentRule::SnapToTarget,EAttachmentRule::SnapToTarget,
																					EAttachmentRule::SnapToTarget,true),_NewWeapon->SocketToAttach);
			SkeletalWeaponMesh->SetSkeletalMesh(_NewWeapon->SkeletalWeaponMesh.Get());
				SkeletalWeaponMesh->SetMaterial(0,_NewWeapon->MaterialWeapon);
			SkeletalWeaponMesh->SetVisibility(true,true);

				
		}
		break;
		case EWeaponTypeMesh::StaticMesh:
		{
			USceneComponent* root = Cast<AMainCharacter>(GetOwner())->GetMeshToAttach();
			StaticWeaponMesh->AttachToComponent(root,FAttachmentTransformRules(EAttachmentRule::SnapToTarget,EAttachmentRule::SnapToTarget,
																						EAttachmentRule::SnapToTarget,true),_NewWeapon->SocketToAttach);
				StaticWeaponMesh->SetStaticMesh(_NewWeapon->StaticWeaponMesh.Get());
				StaticWeaponMesh->SetMaterial(0,_NewWeapon->MaterialWeapon);

			StaticWeaponMesh->SetVisibility(true,true);				
		}
		break;			
		default:
			{
				
			}
	}

	//GameplayAbilities
	if (_NewWeapon->LeftMouseAbility != nullptr)
	{
		FGameplayAbilitySpec LeftAbilitySpec = FGameplayAbilitySpec(_NewWeapon->LeftMouseAbility,1,0);
		LeftAbilityHandle = ASC->GiveAbility(LeftAbilitySpec);
	}

	if (_NewWeapon->RightMouseAbility != nullptr)
	{
		FGameplayAbilitySpec RightAbilitySpec = FGameplayAbilitySpec(_NewWeapon->RightMouseAbility,1,1);
		LeftAbilityHandle = ASC->GiveAbility(RightAbilitySpec);
	}


	//GameplayTags
	ASC->AddLooseGameplayTags(_NewWeapon->WeaponTags);

	//Give Weapon attributes
	ASC->SetNumericAttributeBase(UAmmoAttributes::GetMaxAmmoAttribute(), _NewWeapon->MaxAmmo);
	ASC->SetNumericAttributeBase(UAmmoAttributes::GetAmmoAttribute(), _NewWeapon->MaxAmmo);
	ASC->SetNumericAttributeBase(UAmmoAttributes::GetReloadTimeAttribute(), _NewWeapon->ReloadTime);
	ASC->SetNumericAttributeBase(UAmmoAttributes::GetDamageAttribute(), _NewWeapon->Damage);

	

	//Mapping Context
	if (_NewWeapon->WeaponMappingContext)
	{
		AMainCharacter* MainCharacter = Cast<AMainCharacter>(GetOwner());

		if (APlayerController* PlayerController = Cast<APlayerController>(MainCharacter->GetController()))
		{
			
			if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
			{
				Subsystem->AddMappingContext(_NewWeapon->WeaponMappingContext, 5);
			
			}
		}
	}	
	
	ActualWeapon = _NewWeapon;	
	return true;
}


// Called every frame
void UActiveWeaponComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

bool UActiveWeaponComponent::SetNewWeapon(UWeaponDataAsset* _NewWeapon)
{
	if (ActualWeapon && IsValid(ActualWeapon))
	{
		if (!ClearOldWeapon())
		{
			return false;
		}
	}

	if (!_NewWeapon && IsValid(_NewWeapon))
	{
		return false;
	}
	
	return AssignNewWeapon(_NewWeapon);	
}

UMeshComponent* UActiveWeaponComponent::GetWeaponMesh()
{
	if (!ActualWeapon)
	{
		return nullptr;
	}
	
	if (ActualWeapon->WeaponMeshType == SkeletalMesh)
	{
		return SkeletalWeaponMesh;
	}
	else if (ActualWeapon->WeaponMeshType == StaticMesh)
	{
		return StaticWeaponMesh;
	}
	return nullptr;
}

