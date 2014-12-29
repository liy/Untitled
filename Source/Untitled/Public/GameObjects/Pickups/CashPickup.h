// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameObjects/Pickups/Pickup.h"
#include "CashPickup.generated.h"

/**
 * Directly add to player's wealth value.
 */
UCLASS()
class UNTITLED_API ACashPickup : public APickup
{
	GENERATED_BODY()
	
	
public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 Value;
};
