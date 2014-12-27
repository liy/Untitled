// Fill out your copyright notice in the Description page of Project Settings.

#include "Untitled.h"
#include "Inventory.h"
#include "CharacterController.h"


ACharacterController::ACharacterController(const FObjectInitializer& objectInitializer) : Super(objectInitializer)
{
	// I cannot use "new", have to use CreateDefaultSubobject?!?!?
	// Inventory = new UInventory();

	// Cannot use ConstructObject?!?!? Is it because I'm in the class constructor?! I have to use CreateDefaultSubobject in constructor for all Unreal Object!?!?!
	// If I'm not in the constructor, I can use ConstructObject?!?!??!?!
	// Inventory = ConstructObject<UInventory>(UInventory::StaticClass(), this);

	Inventory = objectInitializer.CreateDefaultSubobject<UInventory>(this, TEXT("Inventory"));
}

void ACharacterController::BeginPlay()
{
	Super::BeginPlay();

	Inventory->Clear();
}
