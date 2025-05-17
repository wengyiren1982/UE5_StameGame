// Fill out your copyright notice in the Description page of Project Settings.


#include "BattleUnits/BattleUnitComp.h"

#include "BattleUnits/Comps/DataProvider/SkillDataProvider.h"
#include "Tools/GLogService.h"


EBattleUnitLifeCycleType CurrentLifeCycleType = EBattleUnitLifeCycleType::None;
ELevelTick CurrentTickType = ELevelTick::LEVELTICK_All;
float CurrentDeltaTime = 0.f;
FString DebugLogFromStr = "[UBattleUnitComp]";
int CurrTickCount = 0;


// USkillDataProvider* SkillDataProvider = nullptr ;

// Sets default values for this component's properties
UBattleUnitComp::UBattleUnitComp()
{
	PrimaryComponentTick.bCanEverTick = true;
}


// Called when the game starts
void UBattleUnitComp::BeginPlay()
{
	Super::BeginPlay();
	ChangeLifeCycleType(EBattleUnitLifeCycleType::OnBeginPlay);
}


// Called every frame
void UBattleUnitComp::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	CurrentDeltaTime = DeltaTime;
	CurrentTickType = TickType;
	CurrTickCount += 1 ;

	if ( CurrTickCount <= 1)
	{
		ChangeLifeCycleType(EBattleUnitLifeCycleType::OnBeginTick);
		ChangeLifeCycleType(EBattleUnitLifeCycleType::OnTick);
	}
	else
	{
		ChangeLifeCycleType(EBattleUnitLifeCycleType::OnTick);
	}
}

void UBattleUnitComp::ChangeLifeCycleType(const EBattleUnitLifeCycleType BattleUnitLifeCycleType)
{
	if (BattleUnitLifeCycleType != CurrentLifeCycleType)
	{
		CurrentLifeCycleType = BattleUnitLifeCycleType;
		Abs_LifeCycleTypeChange();
	}
}

void UBattleUnitComp::Log(const TArray<FString>& Messages) const
{
	UGLogService::LogOnly(*DebugLogFromStr, ELogVerbosity::Warning, Messages);
}
