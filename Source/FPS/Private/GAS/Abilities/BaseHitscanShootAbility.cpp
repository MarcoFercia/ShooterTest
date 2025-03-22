// Fill out your copyright notice in the Description page of Project Settings.


#include "GAS/Abilities/BaseHitscanShootAbility.h"

#include "Character/MainCharacter.h"
#include "Character/Components/ActiveWeaponComponent.h"
#include "Kismet/GameplayStatics.h"


UBaseHitscanShootAbility::UBaseHitscanShootAbility(const FObjectInitializer& ObjectInitializer)
{
	
}

FVector UBaseHitscanShootAbility::GetWeaponSocketLocation()
{
	FVector weaponStartPoint = FVector::ZeroVector;
	AActor* temp = GetAvatarActorFromActorInfo();	
	if (!temp)
	{
		return weaponStartPoint;
	}
	AMainCharacter* MyCharacter = Cast<AMainCharacter>(temp);
	if (!MyCharacter)
	{
		return weaponStartPoint;
	}
	UActiveWeaponComponent* WeaponComponent = MyCharacter->GetWeaponComponent();

	if (!WeaponComponent)
	{
		return weaponStartPoint;
	}
	UMeshComponent* MeshComponent = WeaponComponent->GetWeaponMesh();
	if (!MeshComponent)
	{
		return weaponStartPoint;
	}
	
	weaponStartPoint = MeshComponent->GetSocketLocation(FName("Muzzle"));
	return weaponStartPoint;
}

bool UBaseHitscanShootAbility::StartHitScan(FHitResult& Hit)
{
	FVector StartTracePos = GetWeaponSocketLocation();
	if (StartTracePos == FVector::ZeroVector)
	{
		return false;
	}
	APlayerCameraManager* cameraManager = UGameplayStatics::GetPlayerCameraManager(this,0);
	FVector ForwardCameraVector = cameraManager->GetActorForwardVector();
	FVector CameraPosition = cameraManager->GetCameraLocation();
	FVector EndTracePos =(ForwardCameraVector * WeaponTraceDistance) + CameraPosition;
	
	bool hitted = GetWorld()->LineTraceSingleByChannel(Hit,StartTracePos,EndTracePos,ECC_Visibility);
	FColor debuColor = hitted ? FColor::Green : FColor::Red;
	DrawDebugLine(GetWorld(),StartTracePos,EndTracePos,debuColor,false,5.f,0,1.4f);
	return hitted;
}
