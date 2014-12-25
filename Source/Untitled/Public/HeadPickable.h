// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Pickable.h"
#include "HeadPickable.generated.h"

/**
 * 
 */
UCLASS()
class UNTITLED_API AHeadPickable : public APickable
{
	GENERATED_BODY()
	
public:
	AHeadPickable(const FObjectInitializer& objectInitializer);

	void OnCollection(ACharacterBase& character) override;
};
