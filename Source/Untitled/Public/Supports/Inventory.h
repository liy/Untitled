// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Object.h"
#include "StructLibrary.h"
#include "Inventory.generated.h"

/**
 * 
 */
UCLASS()
class UNTITLED_API UInventory : public UObject
{
	GENERATED_BODY()

public:
	UInventory();
	UInventory(int32 size);
	
	// If you want to expose the integer to blueprint, it has to be 32 bit signed integer?!?!
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Property)
	int32 MaxSize;

	UPROPERTY(BlueprintReadOnly, Category = Manipulation)
	TArray<FInventoryItemInfo> Items;

	UFUNCTION(BlueprintNativeEvent, Category = Manipulation)
	void Add(FInventoryItemInfo item);

	UFUNCTION(BlueprintNativeEvent, Category = Manipulation)
	void Remove(FInventoryItemInfo item);

	UFUNCTION(BlueprintNativeEvent, Category = Manipulation)
	void RemoveAt(int32 index);

	UFUNCTION(BlueprintCallable, Category=Manipulation)
	void Clear();
};
