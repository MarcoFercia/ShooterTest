// © 2025 Marco Fernandez garcia <marcoferciatr@gmail.com>

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "BaseFPSEnemyController.generated.h"

class UBaseStateTreeComponent;


UCLASS()
class FPS_API ABaseFPSEnemyController : public AAIController
{
	GENERATED_BODY()

public:
	ABaseFPSEnemyController(const FObjectInitializer& ObjectInitializer);
	
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TObjectPtr<UBaseStateTreeComponent> StateTreeAIComponent;
protected:

private:

public:

protected:

private:
	
};
