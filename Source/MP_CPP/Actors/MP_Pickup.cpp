#include "MP_Pickup.h"

#include "Components/SphereComponent.h"
#include "Interaction/MP_Player.h"


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
	
	if (OtherActor->Implements<UMP_Player>())
	{
		IMP_Player::Execute_IncrementPickupCount(OtherActor);
		Destroy();
	}
}

void AMP_Pickup::BeginPlay()
{
	Super::BeginPlay();
	
}

