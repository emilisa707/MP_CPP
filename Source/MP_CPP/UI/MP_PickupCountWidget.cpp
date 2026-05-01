#include "MP_PickupCountWidget.h"

#include "Components/TextBlock.h"

void UMP_PickupCountWidget::SetPickupCount(int32 Count)
{
	Text_PickupCount->SetText(FText::AsNumber(Count));
}
