// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "DataAssets/WeaponDataAsset.h"
#include "ActiveWeaponComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class FPS_API UActiveWeaponComponent : public UActorComponent
{
	GENERATED_BODY()

public:

// UPROPERTY(EditDefaultsOnly,BlueprintReadOnly)
// 	TObjectPtr<UWeaponDataAsset> InitialWeapon;
	
protected:
	
private:
	UPROPERTY()
	TObjectPtr<UWeaponDataAsset> ActualWeapon = nullptr;

	UPROPERTY()
	FGameplayAbilitySpecHandle LeftAbilityHandle;
	UPROPERTY()
	FGameplayAbilitySpecHandle RightAbilityHandle;
	
	UPROPERTY()
	TObjectPtr<USkeletalMeshComponent> SkeletalWeaponMesh = nullptr;

	UPROPERTY()
	TObjectPtr<UStaticMeshComponent> StaticWeaponMesh = nullptr;
	
public:	
	// Sets default values for this component's properties
	UActiveWeaponComponent();
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

UFUNCTION(BlueprintCallable)
bool SetNewWeapon(UWeaponDataAsset* _NewWeapon);

	
protected:
	// Called when the game starts
	virtual void BeginPlay() override;

private:	
	
	bool ClearOldWeapon();

	bool AssignNewWeapon(UWeaponDataAsset* _NewWeapon);
};
