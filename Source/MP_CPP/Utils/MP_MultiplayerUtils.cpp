#include "MP_MultiplayerUtils.h"

void UMP_MultiplayerUtils::PrintLocalNetRole(const AActor* Actor)
{
	if (Actor->HasAuthority())
	{
		UE_LOG(LogTemp, Warning, TEXT("Actor [%s] Has Authority"), *Actor->GetName());
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Actor [%s] Does NOT Have Authority"), *Actor->GetName());
	}

	switch (Actor->GetLocalRole())
	{
	case ROLE_None:
		UE_LOG(LogTemp, Warning, TEXT("LocalRole: ROLE_None"));
		break;

	case ROLE_SimulatedProxy:
		UE_LOG(LogTemp, Warning, TEXT("LocalRole: ROLE_SimulatedProxy"));
		break;

	case ROLE_AutonomousProxy:
		UE_LOG(LogTemp, Warning, TEXT("LocalRole: ROLE_AutonomousProxy"));
		break;

	case ROLE_Authority:
		UE_LOG(LogTemp, Warning, TEXT("LocalRole: ROLE_Authority"));
		break;

	default:
		UE_LOG(LogTemp, Warning, TEXT("LocalRole: Unknown role"));
		break;
	}
}

void UMP_MultiplayerUtils::PrintRemoteRole(const AActor* Actor)
{
	switch (Actor->GetRemoteRole())
	{
	case ROLE_None:
		UE_LOG(LogTemp, Warning, TEXT("RemoteRole: ROLE_None"));
		break;

	case ROLE_SimulatedProxy:
		UE_LOG(LogTemp, Warning, TEXT("RemoteRole: ROLE_SimulatedProxy - Network client receiving updates from Server"));
		break;

	case ROLE_AutonomousProxy:
		UE_LOG(LogTemp, Warning, TEXT("RemoteRole: ROLE_AutonomousProxy"));
		break;

	case ROLE_Authority:
		UE_LOG(LogTemp, Warning, TEXT("RemoteRole: ROLE_Authority"));
		break;

	default:
		UE_LOG(LogTemp, Warning, TEXT("RemoteRole: Unknown role"));
		break;
	}
}
