// © 2025 Marco Fernandez garcia <marcoferciatr@gmail.com>


#include "Enemies/BaseFPSEnemyController.h"
#include "Enemies/BaseStateTreeComponent.h"


ABaseFPSEnemyController::ABaseFPSEnemyController(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	StateTreeAIComponent = CreateDefaultSubobject<UBaseStateTreeComponent>("SateTree");
}
