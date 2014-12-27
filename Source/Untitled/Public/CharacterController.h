// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/PlayerController.h"
#include "CharacterController.generated.h"

/**
 * 
 */
UCLASS()
class UNTITLED_API ACharacterController : public APlayerController
{
	GENERATED_BODY()
	
public:
	ACharacterController(const FObjectInitializer& objectInitializer);
	
	UPROPERTY(BlueprintReadOnly, Category = Inventory)
	class UInventory* Inventory;


	virtual void BeginPlay() override;
};
