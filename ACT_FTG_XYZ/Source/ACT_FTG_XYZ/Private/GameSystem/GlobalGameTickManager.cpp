// Fill out your copyright notice in the Description page of Project Settings.


#include "ACT_FTG_XYZ/Public/GameSystem/GlobalGameTickManager.h"
#include "ACT_FTG_XYZ/Public/Tools/GLogService.h"
#include "Defines/MyDefine.h"
#include "GameFramework/PlayerStart.h"
#include "GameInstance/MyGameInstance.h"
#include "GameInstance/InstanceSubSystem/HitTest_Giss.h"
#include "Kismet/GameplayStatics.h"
#include "Tools/GFileService.h"

// Sets default values
AGlobalGameTickManager::AGlobalGameTickManager()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	// 	TArray<int32> IntArray{1, 2, 3};
	// 	uint8         val = static_cast<uint8>(ELogLocationType::AddOnScreen);
	// 	auto          a   = IntArray[val];
	// 	UGLogService::LogOnly(TEXT("GameTick1111111111"), ELogVerbosity::Warning, {FString::FromInt(a)});
	// 	UGFileService::LogOnly(UGFileService::SelfFromStr , ELogVerbosity::Error, {TEXT("5555555555"), TEXT("555555555555")});
}

// Called when the game starts or when spawned
void AGlobalGameTickManager::BeginPlay()
{
	Super::BeginPlay();

	// auto hitTestGiss = UMyGameInstance::GetInstance()->GetSubsystem<UHitTest_Giss>() ;
	auto s  = UMyGameInstance::GetHitTestGameInstanceSubSystem();
	auto s1 = s->MyName;
	UGLogService::LogOnly({s1});

	// UGLogService::LogOnly(TEXT("GameTick"), ELogVerbosity::Log, {TEXT("1111111"), TEXT("111111111111")});
	// UGLogService::MessageOnly(TEXT("GameTick"), FColor::Cyan, {TEXT("222222222222"), TEXT("2222222222222222")});
	// UGLogService::Debug(TEXT("GameTick"), {TEXT("3333333333"), TEXT("33333333333333")});
	// UGLogService::Debug(TEXT(""), ELogVerbosity::Error, FColor::Cyan, {TEXT("44444444"), TEXT("44444444444")});


	TArray<AActor*> FoundActors;
	UGameplayStatics::GetAllActorsWithTag(GetWorld(), UMyDefine::TagName_PlayerStartActor, FoundActors);
	APlayerStart* pStart = nullptr;
	if (FoundActors.Num() > 0)
	{
		pStart = Cast<APlayerStart>(FoundActors[0]);
	}

	// 动态加载角色类
	FString CharacterPath = TEXT("/Game/_Main/BP/BattleUnits/BP_BattleUnit_PlayerMain_1.BP_BattleUnit_PlayerMain_1_C");

	if (UClass* CharacterClass = LoadObject<UClass>(nullptr, *CharacterPath))
	{
		// 获取玩家控制器
		if (APlayerController* PlayerController = GetWorld()->GetFirstPlayerController())
		{
			// 在指定位置生成角色
			if (pStart != nullptr)
			{
				FVector  SpawnLocation = pStart->GetActorLocation();
				FRotator SpawnRotation = pStart->GetActorRotation();

				// 将玩家控制器绑定到生成的角色
				if (APawn* SpawnedPawn = GetWorld()->SpawnActor<APawn>(CharacterClass, SpawnLocation, SpawnRotation))
				{
					PlayerController->Possess(SpawnedPawn);
				}
			}
		}
	}
}

// Called every frame
void AGlobalGameTickManager::Tick(float DeltaTime)
{
	//UGLogService::LogOnly(TEXT("GameTick"), ELogVerbosity::Warning, {TEXT("000000000000000000000000000")});
	Super::Tick(DeltaTime);
	//UGLogService::LogOnly(TEXT("GameTick"), ELogVerbosity::Error, {TEXT("11111111111111111111111111")});
}
