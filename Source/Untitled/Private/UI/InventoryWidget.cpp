// Fill out your copyright notice in the Description page of Project Settings.

#include "Untitled.h"
#include "CharacterController.h"
#include "InventoryWidget.h"

UInventoryWidget::UInventoryWidget(const FObjectInitializer& objectInitializer) : Super(objectInitializer), IsActive(false)
{
	
}

void UInventoryWidget::Construct_Implementation()
{
	SetAlignmentInViewport(FVector2D(0.5f, 0.5f));
}

void UInventoryWidget::Tick_Implementation(FGeometry MyGeometry, float DeltaSeconds)
{
	Super::Tick_Implementation(MyGeometry, DeltaSeconds);

	if (IsActive)
	{
		FVector2D screenLocation;
		ACharacterController* controller = Cast<ACharacterController>(GetOwningPlayer());
		if (controller->ProjectWorldLocationToScreen(controller->GetCharacter()->GetActorLocation(), screenLocation))
		{
			SetVisibility(ESlateVisibility::Visible);
			SetPositionInViewport(screenLocation);
		}
		else
		{
			SetVisibility(ESlateVisibility::Hidden);
		}
	}
	else{
		SetVisibility(ESlateVisibility::Hidden);
	}
}
