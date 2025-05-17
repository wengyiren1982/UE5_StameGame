// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Comps/DataProvider/SkillDataProvider.h"
#include "BattleUnitComp.generated.h"

UENUM()
enum class EBattleUnitLifeCycleType : uint8
{
	// OnConstructor,
	None ,
	OnBeginPlay,
	OnBeginTick,
	OnTick ,
};


UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent , pro))
class ACT_FTG_XYZ_API UBattleUnitComp : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UBattleUnitComp();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

protected:

	// Log -> From ...
	FString DebugLogFromStr ;
	
	// 生命循环类型
	EBattleUnitLifeCycleType CurrentLifeCycleType;

	// LEVELTICK_All	正常情况下运行的 Tick（大多数 Tick 都是这个）
	// LEVELTICK_PauseTick	游戏暂停时仍会 Tick（如果组件支持）
	// LEVELTICK_ViewportsOnly	编辑器视口中 Tick，比如拖动 Actor 时更新组件状态
	ELevelTick CurrentTickType;

	// 当前的 DeltaTime
	float CurrentDeltaTime ;

	// 当前 Tick 的次数
	int CurrTickCount ;



public:
	void ChangeLifeCycleType(const EBattleUnitLifeCycleType BattleUnitLifeCycleType);

protected:
	virtual void Abs_LifeCycleTypeChange() PURE_VIRTUAL(UBattleUnitComp::Abs_LifeCycleTypeChange, /* ^_^ */);

	//	Debug Log 
	void Log( const TArray<FString>& Messages ) const;
};
