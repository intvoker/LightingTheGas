// Copyright intvoker. All Rights Reserved.

using UnrealBuildTool;
using System.Collections.Generic;

public class LightingTheGasTarget : TargetRules
{
	public LightingTheGasTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;
		DefaultBuildSettings = BuildSettingsVersion.V2;
		IncludeOrderVersion = EngineIncludeOrderVersion.Unreal5_1;
		ExtraModuleNames.Add("LightingTheGas");
	}
}
