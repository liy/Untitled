// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "CharacterBase.h"
#include "Pickable.generated.h"

/**
 * 
 */
UCLASS()
class UNTITLED_API APickable : public AActor
{
	GENERATED_BODY()
	
public:
	APickable(const FObjectInitializer& objectInitializer);

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bIsActive;
	
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly)
	class UStaticMeshComponent* Mesh;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly)
	class USphereComponent* CollectionSphere;

	// The inventory related information, thumbnail, etc.
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FInventoryItemInfo InventoryItemInfo;

	// In order to make OnCollection polymorphism in both C++ and BP, we need separate implementations.
	// Therefore, I cannot use BlueprintNativeEvent, since it does not allow virtual declaration.
	// You might want to check UE source code's BeginPlay function.
	// Note that, this instance is still active by this time.
	UFUNCTION(BlueprintImplementableEvent, meta=(FriendlyName="OnCollection"))
	virtual void ReceiveOnCollection();
	virtual void OnCollection(ACharacterBase& character);

	// Setup blueprint related stuff here, e.g., the FInventoryItemInfo's Class property.
	virtual void BeginPlay() override;
};
