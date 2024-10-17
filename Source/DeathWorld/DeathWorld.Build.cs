// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class DeathWorld : ModuleRules
{
	public DeathWorld(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
	
<<<<<<< HEAD
		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput", "MultiplayerPlugin",  "OnlineSubsystem", "OnlineSubsystemSteam"});
=======
		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput", "MultiplayerPlugin"});
>>>>>>> 0bcdb22c66cd4a7c278cb80e5b52113ddf83a582

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
		
<<<<<<< HEAD
=======
		// Uncomment if you are using online features
		PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
>>>>>>> 0bcdb22c66cd4a7c278cb80e5b52113ddf83a582
	}
}
