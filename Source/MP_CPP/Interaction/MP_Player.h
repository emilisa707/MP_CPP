#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "MP_Player.generated.h"

// This class does not need to be modified.
UINTERFACE()
class UMP_Player : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class MP_CPP_API IMP_Player
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "MP_Player")
	USkeletalMeshComponent* GetSkeletalMesh() const;
	
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "MP_Player")
	void GrantArmor(float AmorAmount);
	
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "MP_Player")
	void IncrementPickupCount();
};
