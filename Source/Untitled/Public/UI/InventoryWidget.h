// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Blueprint/UserWidget.h"
#include "PickupDataLibrary.h"
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
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Custom)
	bool IsActive;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Custom)
	class UInventory* Inventory;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Custom)
	TArray<class UInventorySlotWidget*> Slots;

	UFUNCTION(BlueprintCallable, Category=Custom)
	void Add(const FPickupData& data);

	UFUNCTION(BlueprintCallable, Category=Custom)
	void Remove(const FPickupData& data);

	UFUNCTION(BlueprintCallable, Category=Custom)
	void RemoveAt(int32 index);

	UFUNCTION(BlueprintImplementableEvent, Category = Custom)
	void Refresh();

	// Final specific widget and do something about it.
	//virtual TSharedRef<SWidget> RebuildWidget() override;

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
