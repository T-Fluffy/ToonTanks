// Fill out your copyright notice in the Description page of Project Settings.


#include "HealthComponent.h"
#include "ToonTanks/GameModes/TankGameModeBase.h"
#include "Kismet/GameplayStatics.h"

// Sets default values for this component's properties
UHealthComponent::UHealthComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

}


// Called when the game starts
void UHealthComponent::BeginPlay()
{
	Super::BeginPlay();

	Health = DefaultHealth;
	AGameModeBase* GameMode = UGameplayStatics::GetGameMode(GetWorld());
	GameModeRef = Cast<ATankGameModeBase>(GameMode);
	GetOwner()->OnTakeAnyDamage.AddDynamic(this, &UHealthComponent::TakeDamage);
	
}

void UHealthComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}


void UHealthComponent::TakeDamage(AActor* DamagedActor,
								  float Damage, 
								  const UDamageType* DamageType, 
								  AController* InstigatedBy, 
								  AActor* DamageCauser)
{
	check(DamagedActor != nullptr);
	check(Damage >= 0.0f);
	check(DamageType != nullptr);
	check(InstigatedBy != nullptr);
	check(DamageCauser != nullptr);

	UE_LOG(LogTemp, Warning, TEXT("DAMAGE TAKKEN BY %s to %s"), *DamageCauser->GetName(), *DamagedActor->GetName())

	if(GameModeRef==nullptr) 
	{
		UE_LOG(LogTemp, Warning, TEXT("Health Component has no reference to the GameMode"))
	}
	if (Health <= 0.0f)
	{
		return; 
	}

	Health = FMath::Clamp(Health - Damage, 0.0f, DefaultHealth); //avoid drop health below 0 or above max
	
	if (Health <= 0.0f && GameModeRef !=nullptr)
	{ 
		GameModeRef->ActorDied(GetOwner());
	}
	
}

