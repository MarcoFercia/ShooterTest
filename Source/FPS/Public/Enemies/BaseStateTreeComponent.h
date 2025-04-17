// © 2025 Marco Fernandez garcia <marcoferciatr@gmail.com>

#pragma once

#include "CoreMinimal.h"
#include "Components/StateTreeAIComponent.h"
#include "BaseStateTreeComponent.generated.h"


UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class FPS_API UBaseStateTreeComponent : public UStateTreeAIComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UBaseStateTreeComponent(const FObjectInitializer& ObjectInitializer);

protected:


private:

public:
	// Called when the game starts
	virtual void BeginPlay() override;
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

void SetStateTreeAsset(FStateTreeReference _StateTreeAsset);

	
protected:

private:




};
