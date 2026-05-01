
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "MP_PlayerState.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FPickupCountChanged,int32,Count);

/**
 * 
 */
UCLASS()
class MP_CPP_API AMP_PlayerState : public APlayerState
{
	GENERATED_BODY()
	
public:
	virtual void GetLifetimeReplicatedProps(TArray<class FLifetimeProperty>& OutLifetimeProps) const override;
	
	int32 GetNumPickups() const { return NumPickups;}
	void SetNumPickups(const int32 NewNumPickups);
	
	FPickupCountChanged OnPickupCountChanged;
	
private:
	UPROPERTY(ReplicatedUsing=OnRep_NumPickups)
	int32 NumPickups;
	
	UFUNCTION()
	void OnRep_NumPickups();
};
