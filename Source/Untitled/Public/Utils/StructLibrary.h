// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Object.h"
#include "StructLibrary.generated.h"

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

	FORCEINLINE bool operator==(const FInventoryItemInfo& item) const
	{
		return Class == item.Class && Thumbnail == item.Thumbnail && Info.EqualTo(item.Info);
	}
};


/**
 * 
 */
UCLASS()
class UNTITLED_API UStructLibrary : public UObject
{
	GENERATED_BODY()
};
