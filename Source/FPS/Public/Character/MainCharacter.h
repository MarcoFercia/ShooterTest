// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "MainCharacter.generated.h"

class UWeaponDataAsset;
class UActiveWeaponComponent;
class UAbilitySystemComponent;

UCLASS()
class FPS_API AMainCharacter : public ACharacter
{
	GENERATED_BODY()
public:

	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly)
	TObjectPtr<UWeaponDataAsset> InitialWeapon;
	
UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TObjectPtr<UActiveWeaponComponent> WeaponComponent;
	
protected:

private:
	UPROPERTY()
	TObjectPtr<UAbilitySystemComponent> AbilitySystemComponent;
	
public:
	// Sets default values for this character's properties
	AMainCharacter();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION(BlueprintImplementableEvent)
	USceneComponent* GetMeshToAttach();

	UFUNCTION(BlueprintPure)
	UActiveWeaponComponent* GetWeaponComponent();
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	

private:	
	
	
};
