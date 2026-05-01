#include "MP_HealthComponent.h"

#include "Net/UnrealNetwork.h"


UMP_HealthComponent::UMP_HealthComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
	
	SetIsReplicatedByDefault(true);
}

void UMP_HealthComponent::GetLifetimeReplicatedProps(TArray<class FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	
	DOREPLIFETIME(ThisClass, Health);
}

void UMP_HealthComponent::OnRep_Health()
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("Health updated: %f"), Health));
}

