// Fill out your copyright notice in the Description page of Project Settings.

#include "ROSMapPublisher.h"

#include <iostream>
#include <sstream>

// Sets default values
AROSMapPublisher::AROSMapPublisher() : ros_topic_(nullptr) {
    // Set this actor to call Tick() every frame.  You can turn this off to
    // improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = true;
    PrimaryActorTick.TickGroup    = TG_PrePhysics;

    UE_LOG(LogTemp, Warning, TEXT("Construct ROSMapPublisher"));
}

// Called when the game starts or when spawned
void AROSMapPublisher::BeginPlay() {
    Super::BeginPlay();

    // Get current game instance
    UROSIntegrationGameInstance* rosInstance =
        Cast<UROSIntegrationGameInstance>(GetGameInstance());

    // Initialize a topic
    ros_topic_ = NewObject<UTopic>(UTopic::StaticClass());
    ros_topic_->Init(rosInstance->ROSIntegrationCore, TEXT("/example_topic"),
                     TEXT("std_msgs/String"));
    ros_topic_->Advertise();

    UE_LOG(LogTemp, Display, TEXT("Advertised ROS topic"));
}

// Called every frame
void AROSMapPublisher::Tick(float DeltaTime) {
    Super::Tick(DeltaTime);

    TSharedPtr<ROSMessages::std_msgs::String> msg(
        new ROSMessages::std_msgs::String("Hello from Unreal!"));
    if (ros_topic_->Publish(msg)) {
        UE_LOG(LogTemp, Display, TEXT("Published ROS message"));
    } else {
        UE_LOG(LogTemp, Error, TEXT("ROS message publishing failed"));
    }
}
