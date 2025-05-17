// Fill out your copyright notice in the Description page of Project Settings.


#include "GameInstance/MyGameInstance.h"

#include "Tools/GLogService.h"

UMyGameInstance* UMyGameInstance::Instance     = nullptr;

UMyGameInstance::UMyGameInstance()
{
	HitTest_GameInstanceSubSystem = nullptr ;
}


UMyGameInstance* UMyGameInstance::GetInstance()
{
	if (Instance == nullptr)
		throw std::runtime_error("Instance is nullPrt ...");

	return Instance;
}

UHitTest_Giss* UMyGameInstance::GetHitTestGameInstanceSubSystem()
{
	if (Instance == nullptr)
		throw std::runtime_error("Instance is nullPrt ...");

	if (Instance->HitTest_GameInstanceSubSystem == nullptr)
		Instance->HitTest_GameInstanceSubSystem = Instance->GetSubsystem<UHitTest_Giss>();

	return Instance->HitTest_GameInstanceSubSystem;
}

//	=====================================================



void UMyGameInstance::Init()
{
	Super::Init();
	Instance = this;
	UGLogService::LogOnly({TEXT("Init")});
}

void UMyGameInstance::OnStart()
{
	Super::OnStart();


	UGLogService::LogOnly({TEXT("OnStart")});
}

void UMyGameInstance::Shutdown()
{
	Super::Shutdown();
	UGLogService::LogOnly({TEXT("Shutdown")});
}

void UMyGameInstance::StartGameInstance()
{
	Super::StartGameInstance();
	UGLogService::LogOnly({TEXT("StartGameInstance")});
}


void UMyGameInstance::LoadComplete(const float LoadTime, const FString& MapName)
{
	Super::LoadComplete(LoadTime, MapName);
	UGLogService::LogOnly({TEXT("LoadComplete")});
}


void UMyGameInstance::OnWorldChanged(UWorld* OldWorld, UWorld* NewWorld)
{
	Super::OnWorldChanged(OldWorld, NewWorld);
}

void UMyGameInstance::OnPreLoadMap(const FString& MapName)
{
}

void UMyGameInstance::OnPostLoadMap(UWorld* LoadedWorld)
{
}
