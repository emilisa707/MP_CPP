// Copyright Epic Games, Inc. All Rights Reserved.


#include "MP_CPPPlayerController.h"
#include "EnhancedInputSubsystems.h"
#include "Engine/LocalPlayer.h"
#include "InputMappingContext.h"
#include "Blueprint/UserWidget.h"
#include "MP_CPP.h"
#include "Player/MP_PlayerState.h"
#include "Widgets/Input/SVirtualJoystick.h"
#include "UI/MP_PickupCountWidget.h"

void AMP_CPPPlayerController::BeginPlay()
{
	Super::BeginPlay();
	
	if (!IsLocalController()) return;

	// only spawn touch controls on local player controllers
	if (SVirtualJoystick::ShouldDisplayTouchInterface() && IsLocalPlayerController())
	{
		// spawn the mobile controls widget
		MobileControlsWidget = CreateWidget<UUserWidget>(this, MobileControlsWidgetClass);

		if (MobileControlsWidget)
		{
			// add the controls to the player screen
			MobileControlsWidget->AddToPlayerScreen(0);

		} else {

			UE_LOG(LogMP_CPP, Error, TEXT("Could not spawn mobile controls widget."));

		}

	}
	
	PickupCountWidget = CreateWidget<UMP_PickupCountWidget>(this, PickupCountWidgetClass);
	if (PickupCountWidget) PickupCountWidget->AddToViewport();
	
	if (HasAuthority())
	{
		AMP_PlayerState* MP_PlayerState = GetPlayerState<AMP_PlayerState>();
		if (IsValid(MP_PlayerState))
		{
			MP_PlayerState->OnPickupCountChanged.AddDynamic(this, &ThisClass::OnPickupCountChanged);
		}
	}
}

void AMP_CPPPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	// only add IMCs for local player controllers
	if (IsLocalPlayerController())
	{
		// Add Input Mapping Contexts
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
		{
			for (UInputMappingContext* CurrentContext : DefaultMappingContexts)
			{
				Subsystem->AddMappingContext(CurrentContext, 0);
			}

			// only add these IMCs if we're not using mobile touch input
			if (!SVirtualJoystick::ShouldDisplayTouchInterface())
			{
				for (UInputMappingContext* CurrentContext : MobileExcludedMappingContexts)
				{
					Subsystem->AddMappingContext(CurrentContext, 0);
				}
			}
		}
	}
}

void AMP_CPPPlayerController::OnRep_PlayerState()
{
	Super::OnRep_PlayerState();
	if (!IsLocalController()) return;
	
	AMP_PlayerState* MP_PlayerState = GetPlayerState<AMP_PlayerState>();
	if (!IsValid(MP_PlayerState)) return;
	
	MP_PlayerState->OnPickupCountChanged.AddDynamic(this, &ThisClass::OnPickupCountChanged);
}

void AMP_CPPPlayerController::OnPickupCountChanged(int32 Count)
{
	if (!IsValid(PickupCountWidget)) return;
	
	PickupCountWidget->SetPickupCount(Count);
}
