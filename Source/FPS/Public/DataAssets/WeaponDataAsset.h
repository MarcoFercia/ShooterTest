// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InputMappingContext.h"
#include "Abilities/GameplayAbility.h"
#include "Engine/DataAsset.h"
#include "Enums/WeaponTypeMesh.h"
#include "WeaponDataAsset.generated.h"

/**
 * 
 */
UCLASS()
class FPS_API UWeaponDataAsset : public UDataAsset
{
	GENERATED_BODY()
	
public:

	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly)
	TEnumAsByte<EWeaponTypeMesh> WeaponMeshType;

	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly, meta=(EditCondition="WeaponMeshType==EWeaponTypeMesh::SkeletalMesh", EditConditionHides))
	TObjectPtr<USkeletalMesh> SkeletalWeaponMesh;
	//TSoftObjectPtr<USkeletalMesh> SkeletalWeaponMesh;
	
	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly,meta=(EditCondition="WeaponMeshType==EWeaponTypeMesh::StaticMesh", EditConditionHides))
	TObjectPtr<UStaticMesh> StaticWeaponMesh;

	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly)
	TObjectPtr<UMaterialInterface> MaterialWeapon;
	
	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly)
	FName SocketToAttach;
	
	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly)
	TSubclassOf<UGameplayAbility> LeftMouseAbility;

	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly)
	FGameplayTagContainer WeaponTags;
	
	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly)
	float MaxAmmo;
	
	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly)
	TSubclassOf<UGameplayAbility> RightMouseAbility;
	
	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly)
	UInputMappingContext* WeaponMappingContext;
};
