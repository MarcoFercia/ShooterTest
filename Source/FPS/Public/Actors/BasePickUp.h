// © 2025 Marco Fernandez garcia <marcoferciatr@gmail.com>

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BasePickUp.generated.h"

class UBoxComponent;

UCLASS()
class FPS_API ABasePickUp : public AActor
{
	GENERATED_BODY()
public:	
	ABasePickUp(const FObjectInitializer& ObjectInitializer);

	
public:	

	UPROPERTY(EditAnywhere)
	TObjectPtr<UBoxComponent> BoxCollision;
	
protected:


private:


public:
	virtual void Tick(float DeltaTime) override;
UFUNCTION(BlueprintNativeEvent)
void OnPickUp();
	
protected:

	virtual void BeginPlay() override;
	
private:
	
	UFUNCTION()
	void OnPickupOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	
};
