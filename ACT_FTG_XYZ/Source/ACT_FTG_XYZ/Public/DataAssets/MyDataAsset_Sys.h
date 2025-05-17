// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "MyDataAsset_Sys.generated.h"

USTRUCT(BlueprintType)
struct FTagVo
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FName TagName_PlayerStartActor;
};


/**
 * 
 */
UCLASS()
class ACT_FTG_XYZ_API UMyDataAsset_Sys : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Tags")
	FTagVo tagVo;

	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Others")
	float Health = 100.0f;

	virtual void PostLoad() override;
};
