// Fill out your copyright notice in the Description page of Project Settings.


#include "BattleUnits/Actor/BattleUnitActor.h"

#include "BattleUnits/Comps/DataProvider/SkillDataProvider.h"
#include "Tools/GLogService.h"

// Sets default values
ABattleUnitActor::ABattleUnitActor()
{
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ABattleUnitActor::BeginPlay()
{
	Super::BeginPlay();

	if (USkillDataProvider* Comp = FindComponentByClass<USkillDataProvider>())
	{
		UGLogService::LogOnly(TEXT("GameTick"), ELogVerbosity::Warning, {TEXT("111111111111111111"), TEXT("USkillDataProvider")});
	}

	if (USkillDataProvider* Comp = Cast<USkillDataProvider>(GetComponentByClass(USkillDataProvider::StaticClass())))
	{
		UGLogService::LogOnly(TEXT("GameTick"), ELogVerbosity::Warning, {TEXT("222222222222222222222"), TEXT("USkillDataProvider")});
	}
}

// Called every frame
void ABattleUnitActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void ABattleUnitActor::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}
