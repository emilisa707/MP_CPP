#include "MP_Actor.h"


AMP_Actor::AMP_Actor()
{
	PrimaryActorTick.bCanEverTick = true;
	
	bNetLoadOnClient = true;
	bReplicates = true;
	SetReplicatingMovement(true);
}

// Called when the game starts or when spawned
void AMP_Actor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMP_Actor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

