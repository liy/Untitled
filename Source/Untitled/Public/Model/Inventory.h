// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Object.h"
#include "Inventory.generated.h"

/**
* For inventory item information
*/
USTRUCT(BlueprintType)
struct FInventoryItemInfo
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UClass* Class;

	// Thumbnail of the inventory item
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class UTexture2D* Thumbnail;

	// Information about the inventory item
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FText Info;

	// Inventory.Remove(item) requires implementation of the comparison operator.
	FORCEINLINE bool operator==(const FInventoryItemInfo& item) const
	{
		return Class == item.Class && Thumbnail == item.Thumbnail && Info.EqualTo(item.Info);
	}
};

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
