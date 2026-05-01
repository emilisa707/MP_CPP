#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "MP_HealthComponent.generated.h"


UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class MP_CPP_API UMP_HealthComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UMP_HealthComponent();
	
	virtual void GetLifetimeReplicatedProps(TArray<class FLifetimeProperty>& OutLifetimeProps) const override;
	
	void SetHealth(float NewHealth) { Health = NewHealth; }
	float GetHealth() const { return Health; }
	
private:
	UPROPERTY(ReplicatedUsing=OnRep_Health)
	float Health;
	
	UFUNCTION(BlueprintCallable, Category="Components|Health")
	void OnRep_Health();
};