// Fill out your copyright notice in the Description page of Project Settings.


#include "ACT_FTG_XYZ/Public/Tools/GLogService.h"


DEFINE_LOG_CATEGORY(GameTick) ;

const FString UGLogService::UnKnowFrom = "UnKnowFrom";
const FString UGLogService::Separator1 = ",";
const FString UGLogService::Separator2 = "_";
const FString UGLogService::Separator3 = ":";

FString UGLogService::ResultStr = "";



void UGLogService::Debug(const FLogStruct& LogStruct)
{
	ResultStr.Empty();

	const FString GTickFrameNum = FString::Printf(TEXT("[%u]"), 0U);
	const FString Messages      = FString::Join(LogStruct.LogMessages, *Separator1);

	ResultStr.Append(*GTickFrameNum);
	ResultStr.Append(*Separator2);
	ResultStr.Append(*LogStruct.From);
	ResultStr.Append(*Separator3);
	ResultStr.Append(*Messages);

	if (LogStruct.LocationType == ELogLocationType::Default || LogStruct.LocationType == ELogLocationType::All)
	{
		switch (LogStruct.Verbosity)
		{
			case ELogVerbosity::Log:
				UE_LOG(GameTick, Log, TEXT("%s"), *ResultStr.TrimEnd());
				break;
			case ELogVerbosity::Verbose:
				UE_LOG(GameTick, Verbose, TEXT("%s"), *ResultStr.TrimEnd());
				break ;
			case ELogVerbosity::Error:
				UE_LOG(GameTick, Error, TEXT("%s"), *ResultStr.TrimEnd());
				break;
			case ELogVerbosity::Warning:
				UE_LOG(GameTick, Warning, TEXT("%s"), *ResultStr.TrimEnd());
				break;
			default:
				UE_LOG(GameTick, Warning, TEXT("%s"), *ResultStr.TrimEnd());
		}
	}


	if (LogStruct.LocationType == ELogLocationType::AddOnScreen || LogStruct.LocationType == ELogLocationType::All)
	{
		if (GEngine)
		{
			GEngine->AddOnScreenDebugMessage(-1, 5.f, LogStruct.ConsoleColor, *ResultStr);
		}
	}
}


void UGLogService::LogOnly(const TArray<FString>& Args)
{
	const FLogStruct LogStructVo{
		.LocationType = ELogLocationType::Default, 
		.Verbosity = ELogVerbosity::Warning,         
		.From = UnKnowFrom,        
		.LogMessages = Args                     
	};

	Debug(LogStructVo);
}

void UGLogService::LogOnly(const FString& From, const ELogVerbosity::Type LogVerbosity, const TArray<FString>& Args)
{
	const FLogStruct LogStructVo{
		.LocationType = ELogLocationType::Default,
		.Verbosity = LogVerbosity ,
		.From = From.IsEmpty()? UnKnowFrom : From ,
		.LogMessages = Args
	};

	Debug(LogStructVo);

}

void UGLogService::MessageOnly(const TArray<FString>& Args)
{
	const FLogStruct LogStructVo{
		.LocationType = ELogLocationType::AddOnScreen,
		.ConsoleColor = FColor::Yellow,
		.From = UnKnowFrom, 
		.LogMessages = Args
	};

	Debug(LogStructVo);
}

void UGLogService::MessageOnly(const FString& From, const FColor Color, const TArray<FString>& Args)
{
	const FLogStruct LogStructVo{
		.LocationType = ELogLocationType::AddOnScreen,
		.ConsoleColor = Color,
		.From = From.IsEmpty()? UnKnowFrom : From ,
		.LogMessages = Args
	};

	Debug(LogStructVo);
}

void UGLogService::Debug(const FString& From, const TArray<FString>& Args)
{
	const FLogStruct LogStructVo{
		.LocationType = ELogLocationType::All,
		.From = From.IsEmpty()? UnKnowFrom : From ,
		.LogMessages = Args
	};

	Debug(LogStructVo);
}

void UGLogService::Debug(const FString& From, const ELogVerbosity::Type LogVerbosity, const FColor Color, const TArray<FString>& Args)
{
	const FLogStruct LogStructVo{
		.LocationType = ELogLocationType::All,
		.Verbosity = LogVerbosity ,
		.ConsoleColor = Color,
		.From = From.IsEmpty()? UnKnowFrom : From ,
		.LogMessages = Args
	};
	
	Debug(LogStructVo);
}
