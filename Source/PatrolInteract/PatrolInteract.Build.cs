// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class PatrolInteract : ModuleRules
{
	public PatrolInteract(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
		bLegacyPublicIncludePaths = true;
		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay", "AIModule", "GameplayTasks", "GameplayTags" });
	}
}
