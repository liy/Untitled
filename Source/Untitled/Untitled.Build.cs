// Copyright 1998-2014 Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class Untitled : ModuleRules
{
	public Untitled(TargetInfo Target)
	{
		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore",
                                                            // UMG
                                                            "UMG", "Slate", "SlateCore" });
	}
}
