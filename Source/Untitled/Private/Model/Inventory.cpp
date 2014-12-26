// Fill out your copyright notice in the Description page of Project Settings.

#include "Untitled.h"
#include "Inventory.h"

UInventory::UInventory(int32 maxSize) : Super(), MaxSize(maxSize)
{
}

UInventory::UInventory() : UInventory(10)
{

}

void UInventory::Add_Implementation(FInventoryItemInfo item)
{
	Items.Add(item);
}

void UInventory::Remove_Implementation(FInventoryItemInfo item)
{
	Items.Remove(item);
}

void UInventory::RemoveAt_Implementation(int32 index)
{
	Items.RemoveAt(index);
}

void UInventory::Clear()
{
	Items.Reset(MaxSize);
}