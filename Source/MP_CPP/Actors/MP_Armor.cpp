#include "MP_Armor.h"

#include "Components/SphereComponent.h"
#include "GameFramework/Character.h"


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
	
	ACharacter* OverlappedCharacter = Cast<ACharacter>(OtherActor);
	if (HasAuthority() && IsValid(OverlappedCharacter))
	{
		//AttachToActor(OtherActor, FAttachmentTransformRules::SnapToTargetNotIncludingScale);
		SphereMesh->AttachToComponent(OverlappedCharacter->GetMesh(), FAttachmentTransformRules::SnapToTargetNotIncludingScale, FName("head"));
		SphereFootL->AttachToComponent(OverlappedCharacter->GetMesh(), FAttachmentTransformRules::SnapToTargetNotIncludingScale, FName("foot_L"));
		SphereFootR->AttachToComponent(OverlappedCharacter->GetMesh(), FAttachmentTransformRules::SnapToTargetNotIncludingScale, FName("foot_R"));
	}
}

