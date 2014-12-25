// Fill out your copyright notice in the Description page of Project Settings.

#include "Untitled.h"
#include "HeadPickable.h"
#include "Engine.h"

AHeadPickable::AHeadPickable(const FObjectInitializer& objectInitializer) : Super(objectInitializer)
{

}

void AHeadPickable::OnCollection(ACharacterBase& character)
{
	Super::OnCollection(character);

	// TODO: chanage head etc. Update the inventory
	GEngine->AddOnScreenDebugMessage(-1, 2, FColor::Red, TEXT("HEAD onpickup"));
	GEngine->AddOnScreenDebugMessage(-1, 2, FColor::Red, FString::Printf(TEXT("%d"), bIsActive));

	bIsActive = false;
	this->Destroy();
}