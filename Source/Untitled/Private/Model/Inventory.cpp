// Fill out your copyright notice in the Description page of Project Settings.

#include "Untitled.h"
#include "Inventory.h"

UInventory::UInventory(int32 maxSize) : Super(), MaxSize(maxSize)
{
}

UInventory::UInventory() : UInventory(10)
{

}

void UInventory::Add(const FPickupData data)
{
	DataEntries.Add(data);
}

void UInventory::Remove(const FPickupData& data)
{
	DataEntries.Remove(data);
}

void UInventory::RemoveAt(int32 index)
{
	DataEntries.RemoveAt(index);
}

void UInventory::Clear()
{
	DataEntries.Reset();
}