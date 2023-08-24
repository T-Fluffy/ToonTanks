// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ProjectileBase.generated.h"

class UProjectileMovementComponent;

UCLASS()
class TOONTANKS_API AProjectileBase : public AActor
{
	GENERATED_BODY()
private:
	//void InitComponents();
	UPROPERTY(VisibleAnywhere,
			  BlueprintReadOnly,
			  Category = "Components",
			  meta = (AllowPrivateAccess = "true"))
	UProjectileMovementComponent* ProjectileMovement=nullptr;
	UPROPERTY(VisibleAnywhere,
			  BlueprintReadOnly,
			  Category = "Components",
			  meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* ProjectileMesh = nullptr;
	UPROPERTY(EditDefaultsOnly, 
			  Category = "Damage")
	TSubclassOf<UDamageType> DamageType;
	UPROPERTY(VisibleAnywhere,
			  BlueprintReadOnly,
			  Category = "Move",
		      meta = (AllowPrivateAccess = "true"))
	float MovementSpeed = 1300;
	UPROPERTY(VisibleAnywhere,
			  BlueprintReadOnly,
		      Category = "Damage",
			  meta = (AllowPrivateAccess = "true"))
	float Damage = 20;


public:	
	// Sets default values for this actor's properties
	AProjectileBase();
	UFUNCTION()
	void OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherCamp, FVector NormalImpulse, const FHitResult& Hit);
protected:
	// Called when the game starts or when spawned
	void BeginPlay() override;
};
