#include "MP_Armor.h"

#include "Components/SphereComponent.h"
#include "Interaction/MP_Player.h"


// Sets default values
AMP_Armor::AMP_Armor()
{
	PrimaryActorTick.bCanEverTick = false;
	SetRootComponent(CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent")));
	
	SphereMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("SphereMesh"));
	SphereMesh->SetupAttachment(RootComponent);
	SphereMesh->SetIsReplicated(true);
	
	SphereFootL = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("SphereFootL"));
	SphereFootL->SetupAttachment(RootComponent);
	SphereFootL->SetIsReplicated(true);
	
	SphereFootR = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("SphereFootR"));
	SphereFootR->SetupAttachment(RootComponent);
	SphereFootR->SetIsReplicated(true);
	
	SphereCollision = CreateDefaultSubobject<USphereComponent>(TEXT("SphereCollision"));
	SphereCollision->SetupAttachment(RootComponent);
}

void AMP_Armor::BeginPlay()
{
	Super::BeginPlay();
	
}

void AMP_Armor::NotifyActorBeginOverlap(AActor* OtherActor)
{
	Super::NotifyActorBeginOverlap(OtherActor);
	
	if (!OtherActor->HasAuthority()) return;
	
	if (OtherActor->Implements<UMP_Player>())
	{
		USkeletalMeshComponent* Mesh = IMP_Player::Execute_GetSkeletalMesh(OtherActor);
		
		//AttachToActor(OtherActor, FAttachmentTransformRules::SnapToTargetNotIncludingScale);
		SphereMesh->AttachToComponent(Mesh, FAttachmentTransformRules::SnapToTargetNotIncludingScale, FName("head"));
		SphereFootL->AttachToComponent(Mesh, FAttachmentTransformRules::SnapToTargetNotIncludingScale, FName("foot_l"));
		SphereFootR->AttachToComponent(Mesh, FAttachmentTransformRules::SnapToTargetNotIncludingScale, FName("foot_r"));
		
		IMP_Player::Execute_GrantArmor(OtherActor, 25.f);
	}
}

