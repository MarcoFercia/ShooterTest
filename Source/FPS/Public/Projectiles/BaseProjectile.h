// © 2025 Marco Fernandez garcia <marcoferciatr@gmail.com>

#pragma once

#include "CoreMinimal.h"
#include "GameplayEffectTypes.h"
#include "GameFramework/Actor.h"
#include "BaseProjectile.generated.h"

class USphereComponent;
class UProjectileMovementComponent;
class UAbilitySystemComponent;

UCLASS()
class FPS_API ABaseProjectile : public AActor
{
	GENERATED_BODY()
public:
	
	ABaseProjectile(const FObjectInitializer& ObjectInitializer);

public:

	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	TObjectPtr<USphereComponent> SphereCollision;	
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	TObjectPtr<UProjectileMovementComponent> ProjectileComponent;
	
protected:
	
	UPROPERTY(BlueprintReadOnly)
	FGameplayEffectSpecHandle EffectSpecHandle;
	
	UPROPERTY(BlueprintReadOnly)
	UAbilitySystemComponent* InstigatorASC;

private:
	

	
public:	
	void SetEffectSpecHandle(FGameplayEffectSpecHandle _Spec);
	void SetAbilitySystemComponent(UAbilitySystemComponent* _ASC);

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	
	
protected:
	UFUNCTION()
	void OnProjectileHitted(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	
	virtual void BeginPlay() override;

private:	
	
	
};
