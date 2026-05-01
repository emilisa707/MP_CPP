#include "MP_Actor.h"


AMP_Actor::AMP_Actor()
{
	PrimaryActorTick.bCanEverTick = true;
	
	bNetLoadOnClient = true;
	bReplicates = true;
	SetReplicatingMovement(true);
}

void AMP_Actor::Client_PrintActorName_Implementation()
{
	FString MessageStr = HasAuthority() ? "Server: " : "Client: ";
	MessageStr += GetName();
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Cyan, FString::Printf(TEXT("Message from %s"), *MessageStr));
}

void AMP_Actor::BeginPlay()
{
	Super::BeginPlay();

	if (HasAuthority()
	{
		Client_PrintActorName();
	})
	
}

