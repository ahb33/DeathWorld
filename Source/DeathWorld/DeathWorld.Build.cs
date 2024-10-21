// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class DeathWorld : ModuleRules
{
	public DeathWorld(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
	
		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput", "MultiplayerPlugin",  "OnlineSubsystem", "OnlineSubsystemSteam"});

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
		PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });
		
	}
}
