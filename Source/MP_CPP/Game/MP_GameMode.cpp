#include "MP_GameMode.h"

#include "MP_GameState.h"

AMP_GameMode::AMP_GameMode()
{
	bDelayedStart = true;
	MatchStartDelay = 5.f;
}

void AMP_GameMode::StartMatch()
{
	Super::StartMatch();
	
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("Match Started!"));
}

void AMP_GameMode::PostLogin(APlayerController* NewPlayer)
{
	Super::PostLogin(NewPlayer);
	AMP_GameState* MP_GameState = GetGameState<AMP_GameState>();
	if (IsValid(MP_GameState))
	{
		MP_GameState->AddTeamMember(NewPlayer);
	}
}

void AMP_GameMode::BeginPlay()
{
	Super::BeginPlay();
	
	GetWorldTimerManager().SetTimer(MatchStartTimer, this, &AMP_GameMode::StartDelayFinished, MatchStartDelay, false);
}

void AMP_GameMode::StartDelayFinished()
{
	StartMatch();
}
