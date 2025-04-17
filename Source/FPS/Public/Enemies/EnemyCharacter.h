// © 2025 Marco Fernandez garcia <marcoferciatr@gmail.com>

#pragma once

#include "CoreMinimal.h"
#include "Character/BaseFPSCharacter.h"
#include "EnemyCharacter.generated.h"

class UFPSAbilitySystemComponent;
class UBaseWidgetComponent;
class UEnemyBuilderDataAsset;
class UStateTreeAIComponent;
/**
 * 
 */
UCLASS()
class FPS_API AEnemyCharacter : public ABaseFPSCharacter
{
	GENERATED_BODY()
	AEnemyCharacter(const FObjectInitializer& ObjectInitializer);
public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TObjectPtr<UBaseWidgetComponent> HealthBarComponent;
	
protected:
	UPROPERTY(EditInstanceOnly, BlueprintReadOnly)
	TObjectPtr<UEnemyBuilderDataAsset>  BuildDataAsset;
	
private:
	
public:

	bool InitializeEnemy(UEnemyBuilderDataAsset* EnemyAsset);
	bool clearEnemy();


	UFUNCTION(BlueprintCallable)
	void StartLogic();
	
protected:

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	
private:
	
};

