#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MP_PickupCountWidget.generated.h"

class UTextBlock;
/**
 * 
 */
UCLASS()
class MP_CPP_API UMP_PickupCountWidget : public UUserWidget
{
	GENERATED_BODY()
public:
	void SetPickupCount(int32 Count);
	
private:
	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UTextBlock> Text_PickupCount;
};
