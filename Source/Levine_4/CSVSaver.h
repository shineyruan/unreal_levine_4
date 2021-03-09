// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"

#include "CSVSaver.generated.h"

/**
 * @brief A CSV Saver
 *
 */
UCLASS()
class LEVINE_4_API UCSVSaver : public UBlueprintFunctionLibrary {
    GENERATED_BODY()

    UFUNCTION(BlueprintCallable)
    static void saveToCSV(const FVector &actorLocation);
};
