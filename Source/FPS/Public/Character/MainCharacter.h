// © 2025 Marco Fernandez garcia <marcoferciatr@gmail.com>

#pragma once

#include "CoreMinimal.h"
#include "BaseFPSCharacter.h"
#include "MainCharacter.generated.h"

class UGameplayEffect;
class UWeaponDataAsset;
class UActiveWeaponComponent;
class UFPSAbilitySystemComponent;

UCLASS()
class FPS_API AMainCharacter : public ABaseFPSCharacter
{
	GENERATED_BODY()
public:

	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly)
	TObjectPtr<UWeaponDataAsset> InitialWeapon;
	
UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TObjectPtr<UActiveWeaponComponent> WeaponComponent;

	
protected:

	
private:
	
	
public:
	// Sets default values for this character's properties
	AMainCharacter(const FObjectInitializer& ObjectInitializer);

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
