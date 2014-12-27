// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Blueprint/UserWidget.h"
#include "InventoryWidget.generated.h"

/**
 * 
 */
UCLASS()
class UNTITLED_API UInventoryWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:

	UInventoryWidget(const FObjectInitializer& objectInitializer);
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Property)
	bool IsActive;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	class UInventory* Inventory;

	class ACharacterController* Owner;

	/**
	 * Construct BlueprintNativeEvent implementation. Setup the Alignment.
	 *
	 * Called after the underlying slate widget is constructed.  Depending on how the slate object is used
	 * this event may be called multiple times due to adding and removing from the hierarchy.
	 */
	void Construct_Implementation() override;

	// UUserWidget use different Tick from normal AActor.
	// Its Tick is a BlueprintNativeEvent, therefore, I have to override Tick_Implementation
	void Tick_Implementation(FGeometry MyGeometry, float DeltaSeconds) override;
};
