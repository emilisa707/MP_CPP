#include "MP_GameMode.h"

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

void AMP_GameMode::BeginPlay()
{
	Super::BeginPlay();
	
	GetWorldTimerManager().SetTimer(MatchStartTimer, this, &AMP_GameMode::StartDelayFinished, MatchStartDelay, false);
}

void AMP_GameMode::StartDelayFinished()
{
	StartMatch();
}
