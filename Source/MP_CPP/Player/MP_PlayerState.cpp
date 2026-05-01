#include "MP_PlayerState.h"

#include "Net/UnrealNetwork.h"

void AMP_PlayerState::GetLifetimeReplicatedProps(TArray<class FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	
	DOREPLIFETIME(ThisClass, NumPickups);

}

void AMP_PlayerState::SetNumPickups(const int32 NewNumPickups)
{
	NumPickups = NewNumPickups;
	OnPickupCountChanged.Broadcast(NumPickups);
}

void AMP_PlayerState::OnRep_NumPickups()
{
	OnPickupCountChanged.Broadcast(NumPickups);
}
