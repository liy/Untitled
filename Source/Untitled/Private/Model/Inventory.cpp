// Fill out your copyright notice in the Description page of Project Settings.

#include "Untitled.h"
#include "Inventory.h"

UInventory::UInventory(int32 maxSize) : Super(), MaxSize(maxSize)
{
	Items = TArray<FInventoryItemInfo>();
}

UInventory::UInventory() : UInventory(20)
{

}

void UInventory::Add(FInventoryItemInfo info)
{
	Items.Add(info);
}

void UInventory::Remove(const FInventoryItemInfo& item)
{
	Items.Remove(item);
}

void UInventory::RemoveAt(int32 index)
{
	Items.RemoveAt(index);
}

void UInventory::Clear()
{
	Items.Reset();
}