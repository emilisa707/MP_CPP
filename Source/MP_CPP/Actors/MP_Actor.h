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

protected:
	virtual void BeginPlay() override;
};
