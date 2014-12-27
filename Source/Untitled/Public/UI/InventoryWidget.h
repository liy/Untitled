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
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	class UInventory* Inventory;
};
