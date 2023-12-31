// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PawnBase.h"
#include "PawnTank.generated.h"

/**
 * The Tank cpp class responsible for the Tank mechaniques.
 */
class USpringArmComponent;
class UCameraComponent;

UCLASS()
class TOONTANKS_API APawnTank : public APawnBase
{
	GENERATED_BODY()
private:
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly,Category="Components",meta=(AllowPrivateAccess="true"))
	USpringArmComponent* SpringArm;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	UCameraComponent* Camera;
	
	FVector MoveDirection;
	FQuat RotationDirection;

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Movement",meta=(AllowPrivateAccess="true"))
	float MoveSpeed = 100.0f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement", meta = (AllowPrivateAccess = "true"))
	float RotationSpeed = 50.0f;

	APlayerController* PlayerControllerRef;

	void CalculateMoveInput(float Value);
	void CalculateRotateInput(float Value);
	void Move();
	void Rotate();

public:
	//Constructor :
	APawnTank();

	// Called every frame
	void Tick(float DeltaTime) override;
	// Called to bind functionality to input
	void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	

protected:
	// Called when the game starts or when spawned
	void BeginPlay() override;
	void HandleDestruction() override;
};
