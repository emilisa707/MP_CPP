#include "MP_Pickup.h"

#include "Components/SphereComponent.h"
#include "GameFramework/Character.h"
#include "Interaction/MP_Player.h"
#include "Player/MP_PlayerState.h"


// Sets default values
AMP_Pickup::AMP_Pickup()
{
	PrimaryActorTick.bCanEverTick = false;
	
	bNetLoadOnClient = true;
	bReplicates = true;
	
	SetRootComponent(CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent")));
	
	SphereMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("SphereMesh"));
	SphereMesh->SetupAttachment(RootComponent);
	SphereMesh->SetIsReplicated(true);
	
	SphereCollision = CreateDefaultSubobject<USphereComponent>(TEXT("SphereCollision"));
	SphereCollision->SetupAttachment(RootComponent);
}

void AMP_Pickup::NotifyActorBeginOverlap(AActor* OtherActor)
{
	Super::NotifyActorBeginOverlap(OtherActor);
	
	if (!OtherActor->HasAuthority()) return;
	
	if (!OtherActor->Implements<UMP_Player>()) return;
	IMP_Player::Execute_IncreaseHealth(OtherActor, HealthAmount);
	
	ACharacter* Character = Cast<ACharacter>(OtherActor);
	if (!IsValid(Character)) return;
	
	AMP_PlayerState* MP_PlayerState = Cast<AMP_PlayerState>(Character->GetPlayerState());
	if (!IsValid(MP_PlayerState)) return;
	
	MP_PlayerState->SetNumPickups(MP_PlayerState->GetNumPickups() + 1);
	Destroy();
}

