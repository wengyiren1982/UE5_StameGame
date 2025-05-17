// Fill out your copyright notice in the Description page of Project Settings.


#include "BattleUnits/Comps/PlayerBattleUnitComp/PlayerBattleUnitComp.h"

USkillDataProvider* SkillDataProvider = nullptr;

int     AssetsId;
FString Uid;


// Sets default values for this component's properties
UPlayerBattleUnitComp::UPlayerBattleUnitComp()
{
	DebugLogFromStr = TEXT("[PlayerBattleUnitComp]");
}

void UPlayerBattleUnitComp::Abs_LifeCycleTypeChange()
{
#if WITH_EDITOR
	Dev_LogLifeCycleType();
#endif


	switch (CurrentLifeCycleType)
	{
		case EBattleUnitLifeCycleType::OnBeginPlay:
			{
				Self_OnBeginPlay();
				break;
			}

		case EBattleUnitLifeCycleType::OnBeginTick:
			{
				break;
			}
		case EBattleUnitLifeCycleType::OnTick:
			{
				break;
			}
		default: ;
	}
}


void UPlayerBattleUnitComp::Self_OnBeginPlay()
{
	Uid = FString::FromInt(this->GetUniqueID());
	Log({TEXT("AssetsId / UID ->"), FString::FromInt(AssetsId), Uid});

	
}

#if WITH_EDITOR

void UPlayerBattleUnitComp::Dev_LogLifeCycleType()
{
	if (EBattleUnitLifeCycleType::OnTick != CurrentLifeCycleType)
	{
		const UEnum* EnumPtr = StaticEnum<EBattleUnitLifeCycleType>();
		const auto   EName   = EnumPtr->GetNameByValue(static_cast<int64>(CurrentLifeCycleType));
		Log({EName.ToString()});
	}
}

#endif
