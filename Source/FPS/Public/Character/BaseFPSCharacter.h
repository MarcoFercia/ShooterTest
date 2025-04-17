// © 2025 Marco Fernandez garcia <marcoferciatr@gmail.com>

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "BaseFPSCharacter.generated.h"


class UFPSAbilitySystemComponent;

UCLASS()
class FPS_API ABaseFPSCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	ABaseFPSCharacter(const FObjectInitializer& ObjectInitializer);

public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TObjectPtr<UFPSAbilitySystemComponent> AbilitySystemComponent;
protected:
	
private:
	

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
	UFUNCTION(BlueprintNativeEvent)
	void DeathCharacter();
	
protected:
	virtual void BeginPlay() override;
	
private:
	
};


