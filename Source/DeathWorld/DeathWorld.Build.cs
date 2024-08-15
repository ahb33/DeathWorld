// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class DeathWorld : ModuleRules
{
	public DeathWorld(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
	
		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput" });

		PrivateDependencyModuleNames.AddRange(new string[] {  });

		// Define the API macro for this module
        if (Target.Type == TargetRules.TargetType.Editor)
        {
            PublicDefinitions.Add("DeathWorld_API=DLLEXPORT");
        }
        else
        {
            PublicDefinitions.Add("DeathWorld_API=DLLIMPORT");
        }
		
		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });
		
		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
