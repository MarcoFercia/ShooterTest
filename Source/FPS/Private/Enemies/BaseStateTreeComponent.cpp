// © 2025 Marco Fernandez garcia <marcoferciatr@gmail.com>


#include "Enemies/BaseStateTreeComponent.h"



UBaseStateTreeComponent::UBaseStateTreeComponent(const FObjectInitializer& ObjectInitializer)
{
	PrimaryComponentTick.bCanEverTick = true;
}

// Called when the game starts
void UBaseStateTreeComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UBaseStateTreeComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UBaseStateTreeComponent::SetStateTreeAsset(FStateTreeReference _StateTreeAsset)
{
	StateTreeRef = _StateTreeAsset;
}

