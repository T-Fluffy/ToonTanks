// Fill out your copyright notice in the Description page of Project Settings.


#include "ProjectileBase.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AProjectileBase::AProjectileBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	ProjectileMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Projectile Mesh"));
	ProjectileMesh->OnComponentHit.AddDynamic(this, &AProjectileBase::OnHit);

	RootComponent = ProjectileMesh;

	ProjectileMovement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("Projectile Movement"));
	ProjectileMovement->InitialSpeed = MovementSpeed;
	ProjectileMovement->MaxSpeed = MovementSpeed;
	InitialLifeSpan = 3.0f;
}

// Called when the game starts or when spawned
void AProjectileBase::BeginPlay()
{
	Super::BeginPlay();
	ProjectileMesh->OnComponentHit.AddDynamic(this, &AProjectileBase::OnHit);
}

void AProjectileBase::OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherCamp, FVector NormalImpulse, const FHitResult& Hit)
{
	//Try to get a reference to the owning class.
	AActor* MyOwner = GetOwner();
	//if we can't a valid reference, return to check against the owner.
	if (!MyOwner)
	{
		return;
	}
	check(OtherActor != nullptr);
	//if the other actor isnt self or owner and exists, then apply damage.
	if (OtherActor && OtherActor!=this && OtherActor!= MyOwner)
	{
		UGameplayStatics::ApplyDamage(OtherActor,
									  Damage,
									  MyOwner->GetInstigatorController(),
									  this,DamageType);
	}
	//play some effects here during the polish phase.
	Destroy();
}

