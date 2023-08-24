// Fill out your copyright notice in the Description page of Project Settings.


#include "TankGameModeBase.h"


void ATankGameModeBase::BeginPlay()
{
	//Get reference and game win/lose conditions.

	//Call HandleGameStart() to initialise the start countdown, turret activation, pawn check etc.

}

void ATankGameModeBase::ActorDied(AActor* DeadActor)
{
	//Check what type of Actor died.If turret, tally.If Player -> go to lose condition.
	UE_LOG(LogTemp, Warning, TEXT("A Pawn Died."))
}

void ATankGameModeBase::HandleGameStart()
{
	//Initialise the satrt countdown, turret activation, pawn check etc.

	//Call Blueprint version GameStart();
}

void ATankGameModeBase::HandleGameOver(bool PlayerWon)
{
	//See if the player has destroyed all the turret, show win result.
	//else if turret destroyed player,show lose result.
	//Call blueprint version GameOver(bool).
}

//void ATankGameModeBase::GameStart()
//{
//}
//
//void ATankGameModeBase::GameOver(bool PlayerWon)
//{
//}
