// © 2025 Marco Fernandez garcia <marcoferciatr@gmail.com>


#include "GAS/Abilities/HitScanShootAbility.h"
#include "Character/MainCharacter.h"
#include "Character/Components/ActiveWeaponComponent.h"
#include "Kismet/GameplayStatics.h"


UHitScanShootAbility::UHitScanShootAbility(const FObjectInitializer& ObjectInitializer)
{
	
}

bool UHitScanShootAbility::StartHitScan(FHitResult& Hit, FVector& HitDirection,FVector& StartPosition,FVector& EndPosition)
{
	 StartPosition = GetWeaponSocketTransform().GetLocation();
	if (StartPosition == FVector::ZeroVector)
	{
		return false;
	}
	APlayerCameraManager* cameraManager = UGameplayStatics::GetPlayerCameraManager(this,0);
	FVector ForwardCameraVector = cameraManager->GetActorForwardVector();
	FVector CameraPosition = cameraManager->GetCameraLocation();
	 EndPosition =(ForwardCameraVector * WeaponTraceDistance) + CameraPosition;
	HitDirection = (EndPosition - StartPosition).GetSafeNormal(0.05f);
	
	
	bool hitted = GetWorld()->LineTraceSingleByChannel(Hit,StartPosition,EndPosition,ECC_Visibility);
	FColor debuColor = hitted ? FColor::Green : FColor::Red;
	//DrawDebugLine(GetWorld(),StartPosition,EndPosition,debuColor,false,5.f,0,1.4f);
	return hitted;
}



void UHitScanShootAbility::ShootProjectile(TArray<FHitResult>& _hits)
{
	Super::ShootProjectile(_hits);
	FVector StartPosition, EndPosition, HitDirection = FVector::ZeroVector;
	FHitResult Hit = FHitResult();
	StartHitScan(Hit,HitDirection,StartPosition,EndPosition);
	_hits.Add(Hit);
	ExecuteCues(StartPosition,EndPosition);
	
}
