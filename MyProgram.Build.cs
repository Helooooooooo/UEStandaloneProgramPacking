// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class MyProgram : ModuleRules
{
	public MyProgram(ReadOnlyTargetRules Target) : base(Target)
	{
		PublicIncludePaths.Add("Runtime/Launch/Public");

		PrivateIncludePaths.Add("Runtime/Launch/Private");		// For LaunchEngineLoop.cpp include

		PrivateDependencyModuleNames.Add("Core");
		PrivateDependencyModuleNames.Add("Projects");
		
		PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore", "StandaloneRenderer" });
	}
}







