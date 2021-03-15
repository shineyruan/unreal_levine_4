// Fill out your copyright notice in the Description page of Project Settings.

#include "ROSMapPublisher.h"
#include "UROSBridge/Public/std_msgs/String.h"

// Sets default values
AROSMapPublisher::AROSMapPublisher() {
    // Set this actor to call Tick() every frame.  You can turn this off to
    // improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = true;
    PrimaryActorTick.TickGroup    = TG_PrePhysics;

    UE_LOG(LogTemp, Warning, TEXT("Construct ROSMapPublisher"));
}

// Called when the game starts or when spawned
void AROSMapPublisher::BeginPlay() {
    Super::BeginPlay();

    // Construct UROSBridge Handler
    Handler = MakeShareable<FROSBridgeHandler>(
        new FROSBridgeHandler(TEXT("127.0.0.1"), 8080));

    Handler->Connect();

    // Construct UROSBridge Publisher
    Publisher = MakeShareable<FROSBridgePublisher>(new FROSBridgePublisher(
        TEXT("/example_topic"), TEXT("std_msgs/String")));
    Handler->AddPublisher(Publisher);
}

// Called every frame
void AROSMapPublisher::Tick(float DeltaTime) {
    Super::Tick(DeltaTime);

    TSharedPtr<std_msgs::String> StringMsgPtr(
        new std_msgs::String(TEXT("Hello from Unreal")));

    Handler->PublishMsg(TEXT("/example_topic"), StringMsgPtr);
    Handler->Process();
}

void AROSMapPublisher::EndPlay(const EEndPlayReason::Type Reason) {
    Handler->Disconnect();

    Super::EndPlay(Reason);
}
