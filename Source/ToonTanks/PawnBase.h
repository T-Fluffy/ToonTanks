// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Components/CapsuleComponent.h"
#include "PawnBase.generated.h"


class UCapsuleComponent;
class UStaticMeshComponent;
class AProjectileBase;


UCLASS()
class TOONTANKS_API APawnBase : public APawn
{
	GENERATED_BODY()
private:
	// COMPONENTS
	UPROPERTY(VisibleAnywhere,
			  BlueprintReadOnly,
			  Category="Components",
			  meta=(AllowPrivateAccess="true"))
	UCapsuleComponent* CapsuleComp;

	UPROPERTY(VisibleAnywhere,
			  BlueprintReadOnly,
		      Category = "Components",
			  meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* BaseMesh;

	UPROPERTY(VisibleAnywhere,
			  BlueprintReadOnly,
			  Category = "Components",
		      meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* TurretMesh;

	UPROPERTY(VisibleAnywhere, 
			  BlueprintReadOnly,
			  Category = "Components", 
			  meta = (AllowPrivateAccess = "true"))
	USceneComponent* ProjectileSpawnPoint;

	// VARIABLES 
	UPROPERTY(EditAnywhere,
			  BlueprintReadOnly,
			  Category="Projectile Type",
			  meta=(AllowPrivateAccess="True"))
	TSubclassOf<AProjectileBase> ProjectileClass;

public:

	// Sets default values for this pawn's properties
	APawnBase();

protected:

	UFUNCTION()
	void RotateTurret(FVector LookAtTarget);

	UFUNCTION()
	void FIRE();

	UFUNCTION()
	virtual void HandleDestruction();

	//virtual void TEST(FString msg);
};
