// Fill out your copyright notice in the Description page of Project Settings.


#include "GAS/BaseShooterAbility.h"


UBaseShooterAbility::UBaseShooterAbility(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	InstancingPolicy = EGameplayAbilityInstancingPolicy::Type::InstancedPerActor;
}
