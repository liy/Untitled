// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Object.h"
#include "StructLibrary.generated.h"

/**
 * For inventory item information
 */
USTRUCT(BlueprintType)
struct FInventoryStruct
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class AActor* Item;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class UTexture2D* ItemImage;
};


/**
 * 
 */
UCLASS()
class UNTITLED_API UStructLibrary : public UObject
{
	GENERATED_BODY()
};
