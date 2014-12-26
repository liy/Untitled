// Fill out your copyright notice in the Description page of Project Settings.

#include "Untitled.h"
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
	// I guess this is a copy assignment??
	// I guess InventoryInfo will be destroyed if this actor is destroyed??
	FInventoryItemInfo* Info = new FInventoryItemInfo();
	Info = &InventoryItemInfo;
	// Add the Pickable Information to the inventory
	character.Inventory->Add(*Info);

	// Call blueprint OnCollection native event.
	ReceiveOnCollection();

	bIsActive = false;
	this->Destroy();
}