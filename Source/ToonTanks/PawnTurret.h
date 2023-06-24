// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PawnBase.h"
#include "PawnTurret.generated.h"

class APawnTank;

/**
 * 
 */
UCLASS()
class TOONTANKS_API APawnTurret : public APawnBase
{
	GENERATED_BODY()

private:
	
	APawnTank* PlayerPawn;
	FTimerHandle FireRateTimerHandle;
	void  CheckFireCondition();
	float ReturnDistanceToPlayer();
	
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat", meta = (AllwoPrivateAccess = "true"))
	float FireRate = 2.0f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat", meta = (AllwoPrivateAccess = "true"))
	float FireRange = 500.0f;
	// Called every frame
	virtual void Tick(float DeltaTime) override;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	virtual void HandleDestruction() override;

	void TEST(FString msg) override;
	
};
