#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MP_Actor.generated.h"

UCLASS()
class MP_CPP_API AMP_Actor : public AActor
{
	GENERATED_BODY()

public:
	AMP_Actor();
	
	UFUNCTION(Client, Reliable)
	void Client_PrintActorName();
	
	UFUNCTION(Server, Reliable)
	void Server_PrintActorName();
	
	virtual void OnRep_Owner() override;

protected:
	virtual void BeginPlay() override;
};
