// Fill out your copyright notice in the Description page of Project Settings.

#include "Untitled.h"
#include "TreasurePickup.h"

ATreasurePickup::ATreasurePickup(const FObjectInitializer& objectInitializer) : Super(objectInitializer), MinValue(10), MaxValue(1000)
{

}

void ATreasurePickup::Evaludate(){
	Value = FMath::FRandRange(MinValue, MaxValue);
}