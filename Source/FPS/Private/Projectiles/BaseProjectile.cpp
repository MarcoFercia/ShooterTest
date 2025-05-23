// © 2025 Marco Fernandez garcia <marcoferciatr@gmail.com>


#include "Projectiles/BaseProjectile.h"

#include "AbilitySystemBlueprintLibrary.h"
#include "AbilitySystemComponent.h"
#include "Components/SphereComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"


ABaseProjectile::ABaseProjectile(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	
	PrimaryActorTick.bCanEverTick = true;
	SphereCollision = CreateDefaultSubobject<USphereComponent>("Sphere Collision");
	SetRootComponent(SphereCollision);
	ProjectileComponent = CreateDefaultSubobject<UProjectileMovementComponent>("Projectile Component");
	
}

void ABaseProjectile::SetEffectSpecHandle(FGameplayEffectSpecHandle _Spec)
{
	EffectSpecHandle =_Spec;
}

void ABaseProjectile::SetAbilitySystemComponent(UAbilitySystemComponent* _ASC)
{
	InstigatorASC = _ASC;
}

void ABaseProjectile::OnProjectileHitted(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	UAbilitySystemComponent* HittedASC =  UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(OtherActor);
	
	if (HittedASC && InstigatorASC)
	{
		InstigatorASC->ApplyGameplayEffectSpecToTarget(*EffectSpecHandle.Data.Get(),HittedASC);
	}
	
	Destroy();
}

// Called when the game starts or when spawned
void ABaseProjectile::BeginPlay()
{
	Super::BeginPlay();
	SphereCollision->OnComponentBeginOverlap.AddDynamic(this,&ABaseProjectile::OnProjectileHitted);
	
}

// Called every frame
void ABaseProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

