// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "GLogService.generated.h"

DECLARE_LOG_CATEGORY_EXTERN(GameTick, Log, All) ;


UENUM()
enum class ELogLocationType : uint8
{
	Default = 0,
	AddOnScreen,
	All,
};


USTRUCT()
struct FLogStruct
{
	GENERATED_BODY()

	ELogLocationType    LocationType = ELogLocationType::Default;
	ELogVerbosity::Type Verbosity    = ELogVerbosity::Warning;
	FColor              ConsoleColor = FColor::Yellow;
	FString             From;
	TArray<FString>     LogMessages;
};

/**
 * 
 */
UCLASS()
class ACT_FTG_XYZ_API UGLogService : public UObject
{
	GENERATED_BODY()

	//=================================================================================
	//=========================== Vars ===========================
	//=================================================================================

	const static FString Separator1;
	const static FString Separator2;
	const static FString Separator3;
	const static FString UnKnowFrom;

	static FString ResultStr;

	//=================================================================================
	//=========================== Func ===========================
	//=================================================================================

public:
	static void LogOnly(const TArray<FString>& Args) ;
	static void LogOnly(const FString& From, const ELogVerbosity::Type LogVerbosity, const TArray<FString>& Args);

	static void MessageOnly(const TArray<FString>& Args) ;
	static void MessageOnly(const FString& From, const FColor Color, const TArray<FString>& Args);

	static void Debug(const FLogStruct& LogStruct);
	static void Debug(const FString& From, const TArray<FString>& Args);
	static void Debug(const FString& From, const ELogVerbosity::Type LogVerbosity, const FColor Color, const TArray<FString>& Args);
};
