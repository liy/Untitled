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

void APickable::OnCollection(ACharacterBase& character){
	// Call blueprint OnCollection native event.
	ReceiveOnCollection();
}