// Fill out your copyright notice in the Description page of Project Settings.


#include "PawnTurret.h"
#include "Kismet/GameplayStatics.h"
#include "PawnTank.h"


// Called when the game starts or when spawned
void APawnTurret::BeginPlay()
{
	Super::BeginPlay();

	GetWorld()->GetTimerManager().SetTimer(FireRateTimerHandle, this,&APawnTurret::CheckFireCondition,FireRate,true);

	PlayerPawn = Cast<APawnTank>(UGameplayStatics::GetPlayerPawn(this, 0));

	TEST("Call from Turret");
}

void APawnTurret::HandleDestruction()
{
	// Call base pawn class HandleDestruction to play effects.
	Super::HandleDestruction();
	Destroy();
}

void APawnTurret::TEST(FString msg)
{
	//Call PawnBase TEST()
	Super::TEST("Base call");
}

//Called every frame
void APawnTurret::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	// If Player == null || is Dead THEN BAIL !! 
	if (!PlayerPawn||ReturnDistanceToPlayer()>FireRange)
	{
		return;
	}
	RotateTurret(PlayerPawn->GetActorLocation());	
}

void APawnTurret::CheckFireCondition()
{
	//If Player == null || is Dead THEN BAIL !!
	if (!PlayerPawn)
	{
		return;
	}
	//If Player IS in range THEN FIRE !!
	if (ReturnDistanceToPlayer()<=FireRange)
	{
		FIRE(); 
	}
}
float APawnTurret::ReturnDistanceToPlayer() {
	if (!PlayerPawn)
	{
		return 0.0f;
	}
	return FVector::Dist(PlayerPawn->GetActorLocation(), GetActorLocation());
}