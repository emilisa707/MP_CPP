// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MP_Pickup.generated.h"

class USphereComponent;

UCLASS()
class MP_CPP_API AMP_Pickup : public AActor
{
	GENERATED_BODY()
	
public:
	AMP_Pickup();
	
	virtual void NotifyActorBeginOverlap(AActor* OtherActor) override;
	
protected:
	virtual void BeginPlay() override;

private:
	UPROPERTY(VisibleAnywhere, Category = "Components")
	TObjectPtr<UStaticMeshComponent> SphereMesh;
	
	UPROPERTY(VisibleAnywhere, Category = "Components")
	TObjectPtr<USphereComponent> SphereCollision;
};
