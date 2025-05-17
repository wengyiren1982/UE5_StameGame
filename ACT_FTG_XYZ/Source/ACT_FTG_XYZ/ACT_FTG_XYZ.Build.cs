// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class ACT_FTG_XYZ : ModuleRules
{
	public ACT_FTG_XYZ(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput" });
	}
}
