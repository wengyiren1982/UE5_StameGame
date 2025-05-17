// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Skill_DataTable.generated.h"


/**
 * 
 */
UCLASS()
class ACT_FTG_XYZ_API USkill_DataTable : public UObject
{
	GENERATED_BODY()
};

//	================================ enum ================================

UENUM()
enum class ESkillMainType : uint16
{
	//	=============== 基础拳脚 =============== 1~9
	//	轻,中,重 拳
	Lp = 1,
	Mp,
	Hp,

	//	轻,中,重 脚
	Lk,
	Mk,
	Hk,

	//	=============== 基础动作 ===============10~100
	Idle = 10,
	Walk,
	Run,
	JumpX1 = 20,
	JumpX2,

	//	=============== 基础TC =============== 101~150
	Tc1_P = 101,
	Tc2_P,
	Tc3_P,
	Tc1_K = 125,
	Tc2_K,
	Tc3_K,

	//	=============== 基础攻击技能 =============== 200~2000
	Dash      = 200, //	Dash -> F
	DashSlash = 201, //	Dash -> Slash

	OTO = 300, //	技能取消技能

	ShorYuKen    = 500, //	升龙 -> 只要能把对方打浮空的技能都是这个类型
	HitTheGround = 600, //	砸地 -> 从上到下攻击的

	Blocking = 700, //	格挡 -> 不追加攻击
	Parry    = 701, //	弹反 -> 格挡 + 追加攻击

	CA_1     = 1000,
	CA_Parry = 2000, //	类似 SF5 Ruy的 VT

	//	=============== Bullet =============== 2001~3000
	Bullet_Hadouken_Ground   = 2001, //	人在地面上发波
	Bullet_Hadouken_InTheAir = 2002, //	人在空中发波

	//	=============== 使用道具 =============== 65532
	UsingItem = 65532,
	//	=============== 捡垃圾 =============== 65533
	PickUpItem = 65533,
	//	=============== Hurt =============== 65534
	OnHurt = 65534,
	//	=============== 死亡 =============== 65535
	Dead = 65535
};


//	================================ struct ================================
USTRUCT(BlueprintType)
struct FSkillTplVo : public FTableRowBase
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Basic")
	int OwnerUnitId ;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Basic")
	FString SkillDesc ;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Types")
	ESkillMainType SkillMainType;

	
};


