// Fill out your copyright notice in the Description page of Project Settings.

#include "CSVSaver.h"

#include "Runtime/Core/Public/HAL/PlatformFile.h"
#include "Runtime/Core/Public/HAL/PlatformFilemanager.h"
#include "Runtime/Core/Public/Misc/FileHelper.h"
#include "Runtime/Core/Public/Misc/Paths.h"

bool UCSVSaver::saveToCSV(const FString& actorCategory,
                          const FString& actorNameAndFamily,
                          const FVector& actorLocation) {
    // Get current project directory
    FString projDirectory = FPaths::ProjectDir();
    UE_LOG(LogTemp, Display, TEXT("Current Project dir: %s"), *projDirectory);

    // Creates the file manager
    IPlatformFile& fileManager = FPlatformFileManager::Get().GetPlatformFile();
    // Test if CSV directory exists
    FString csvDirectory = FPaths::Combine(projDirectory, TEXT("csv"));

    if (fileManager.DirectoryExists(*csvDirectory)) {
        UE_LOG(LogTemp, Display, TEXT("Found CSV directory: %s"),
               *csvDirectory);
    } else {
        UE_LOG(LogTemp, Warning, TEXT("CSV directory not found."),
               *csvDirectory);
        bool createDir_stat = fileManager.CreateDirectory(*csvDirectory);
        if (createDir_stat) {
            UE_LOG(LogTemp, Display,
                   TEXT("CSV dir created successful. Created at: %s"),
                   *csvDirectory);
        } else {
            UE_LOG(LogTemp, Error, TEXT("CSV dir created failed."));
        }
    }

    // Create a CSV file for logging
    FString csvPath = FPaths::Combine(csvDirectory, TEXT("actorLocation.csv"));
    FString actorLocationStr =
        actorCategory + TEXT(",") + actorNameAndFamily + TEXT(",") +
        FString::SanitizeFloat(actorLocation.X) + TEXT(",") +
        FString::SanitizeFloat(actorLocation.Y) + TEXT(",") +
        FString::SanitizeFloat(actorLocation.Z) + TEXT("\n");

    // Save the location to CSV file
    if (FFileHelper::SaveStringToFile(actorLocationStr, *csvPath,
                                      FFileHelper::EEncodingOptions::AutoDetect,
                                      &IFileManager::Get(), FILEWRITE_Append)) {
        // save successful
        UE_LOG(LogTemp, Warning, TEXT("Actor location save complete!"));
        return true;
    } else {
        // save failed
        UE_LOG(LogTemp, Error, TEXT("Actor location save failed."));
        return false;
    }
}
