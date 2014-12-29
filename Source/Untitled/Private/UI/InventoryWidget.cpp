// Fill out your copyright notice in the Description page of Project Settings.

#include "Untitled.h"
#include "CharacterController.h"
#include "InventoryWidget.h"
#include "InventorySlotWidget.h"
#include "Inventory.h"
#include "Pickup.h"

UInventoryWidget::UInventoryWidget(const FObjectInitializer& objectInitializer) : Super(objectInitializer), IsActive(false)
{
	// I cannot use "new", have to use CreateDefaultSubobject?!?!?
	// Inventory = new UInventory();
	// Cannot use ConstructObject?!?!? Is it because I'm in the class constructor?! I have to use CreateDefaultSubobject in constructor for all Unreal Object!?!?!
	// If I'm not in the constructor, I can use ConstructObject?!?!??!?!
	// Inventory = ConstructObject<UInventory>(UInventory::StaticClass(), this);
	Inventory = objectInitializer.CreateDefaultSubobject<UInventory>(this, TEXT("Inventory"));
}

void UInventoryWidget::Construct_Implementation()
{
	Inventory->Clear();

	// Get a specific widget, if you want.
	// UWidget* test = this->GetWidgetFromName(TEXT("Slot0"));

	// Get all widgets
	TArray<UWidget*> widgets;
	WidgetTree->GetAllWidgets(widgets);

	for (UWidget* widget : widgets)
	{
		//if (widget->GetClass()->IsChildOf(UInventorySlotWidget::StaticClass()))
		if (widget->IsA(UInventorySlotWidget::StaticClass()))
		{
			Slots.Add(Cast<UInventorySlotWidget>(widget));
		}
	}

	SetAlignmentInViewport(FVector2D(0.5f, 0.5f));

	Super::Construct_Implementation();
}

void UInventoryWidget::Tick_Implementation(FGeometry MyGeometry, float DeltaSeconds)
{
	Super::Tick_Implementation(MyGeometry, DeltaSeconds);

	if (IsActive)
	{
		FVector2D screenLocation;
		ACharacterController* controller = Cast<ACharacterController>(GetOwningPlayer());
		if (controller && controller->ProjectWorldLocationToScreen(controller->GetCharacter()->GetActorLocation(), screenLocation))
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

void UInventoryWidget::Add(const FPickupData& data)
{
	Inventory->Add(data);
	Refresh();
}

void UInventoryWidget::Remove(const FPickupData& data)
{
	Inventory->Remove(data);
	Refresh();
}

void UInventoryWidget::RemoveAt(int32 index)
{
	Inventory->RemoveAt(index);
	Refresh();
}