// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BattleUnits/BattleUnitComp.h"
#include "Components/ActorComponent.h"
#include "PlayerBattleUnitComp.generated.h"


UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class ACT_FTG_XYZ_API UPlayerBattleUnitComp : public UBattleUnitComp
{
	GENERATED_BODY()

	public:
		// Sets default values for this component's properties
		UPlayerBattleUnitComp();

		//	资源ID , 什么模型 (Mesh) ->  填写资源ID, 资源ID可能是重复的
		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "==ID")
		int AssetsId;

		//	唯一内存ID
		FString Uid;

	protected:
		
		virtual void Abs_LifeCycleTypeChange() override;

	private:
		void Self_OnBeginPlay();

	private:
		void Dev_LogLifeCycleType();
};
