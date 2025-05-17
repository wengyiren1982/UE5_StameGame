// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "InstanceSubSystem/HitTest_Giss.h"
#include "MyGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class ACT_FTG_XYZ_API UMyGameInstance : public UGameInstance
{
	GENERATED_BODY()

	private:
		static UMyGameInstance* Instance;

	private :
		UPROPERTY()
		UHitTest_Giss* HitTest_GameInstanceSubSystem;

	public :
		static UMyGameInstance* GetInstance();
		static UHitTest_Giss*   GetHitTestGameInstanceSubSystem();

		
	public :
		UMyGameInstance();

		// 在游戏实例初始化时调用
		virtual void Init() override;

		// 在游戏实例关闭时调用
		virtual void Shutdown() override;

		// 在游戏实例启动时调用
		virtual void StartGameInstance() override;

		// 在游戏实例开始运行时调用
		virtual void OnStart() override;

		// 在地图加载完成时调用
		virtual void LoadComplete(const float LoadTime, const FString& MapName) override;

		// 在世界切换时调用
		virtual void OnWorldChanged(UWorld* OldWorld, UWorld* NewWorld) override;

		// // 在网络错误发生时调用
		// virtual void HandleNetworkError(ENetworkFailure::Type FailureType, bool bIsServer) override;

		// // 在旅行错误发生时调用
		// virtual void HandleTravelError(ETravelFailure::Type FailureType);

		// 在地图加载之前调用
		virtual void OnPreLoadMap(const FString& MapName);

		// 在地图加载之后调用
		virtual void OnPostLoadMap(UWorld* LoadedWorld);
};
