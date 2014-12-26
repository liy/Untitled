// Fill out your copyright notice in the Description page of Project Settings.

#include "Untitled.h"
#include "CharacterBase.h"
#include "Pickable.h"


APickable::APickable(const FObjectInitializer& objectInitializer) : Super(objectInitializer)
{
	bIsActive = true;
	
	CollectionSphere = objectInitializer.CreateDefaultSubobject<USphereComponent>(this, TEXT("CollectionSphere"));
	RootComponent = CollectionSphere;
	
	Mesh = objectInitializer.CreateDefaultSubobject<UStaticMeshComponent>(this, TEXT("Mesh"));
	Mesh->SetSimulatePhysics(true);
	Mesh->AttachTo(RootComponent);
}

void APickable::BeginPlay()
{
	// Cannot put the Class assignment in the constructor, since GetClass() only return the 
	// C++ class in the constructor, not the final blueprint class.
	InventoryItemInfo.Class = GetClass();

	Super::BeginPlay();
}

void APickable::OnCollection(ACharacterBase& character)
{
	// Add the Pickable Information to the inventory, I guess InventoryItemInfo should be copied.
	// Since Inventory.Add(InventoryItemInfo item) copy the parameter by default. (It is pass by value, Not pass by reference or pointer)
	// And, I assume, that this actor's InventoryItemInfo will be destroyed once this actor is destroyed.
	character.Inventory->Add(InventoryItemInfo);

	// Call blueprint OnCollection native event.
	ReceiveOnCollection();

	bIsActive = false;
	this->Destroy();
}