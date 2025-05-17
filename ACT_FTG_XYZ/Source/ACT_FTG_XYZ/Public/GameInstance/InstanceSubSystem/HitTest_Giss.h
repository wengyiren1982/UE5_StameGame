// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "HitTest_Giss.generated.h"

/**
 * 
 */
UCLASS()
class ACT_FTG_XYZ_API UHitTest_Giss : public UGameInstanceSubsystem
{
	GENERATED_BODY()

	UHitTest_Giss() ;
	
	public:
		FString MyName ;
};
