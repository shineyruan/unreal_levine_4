// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "UROSBridge/Public/ROSBridgeHandler.h"

#include "ROSMapPublisher.generated.h"

UCLASS()
class LEVINE_4_API AROSMapPublisher : public AActor {
    GENERATED_BODY()

public:
    TSharedPtr<FROSBridgeHandler> Handler;

    // Sets default values for this actor's properties
    AROSMapPublisher();

    // Called every frame
    virtual void Tick(float DeltaTime) override;

protected:
    TSharedPtr<FROSBridgePublisher> Publisher;

    // Called when the game starts or when spawned
    virtual void BeginPlay() override;

    // Called when the game ends
    virtual void EndPlay(const EEndPlayReason::Type Reason) override;
};
