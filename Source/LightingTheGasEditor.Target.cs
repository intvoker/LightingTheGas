// Copyright intvoker. All Rights Reserved.

using UnrealBuildTool;
using System.Collections.Generic;

public class LightingTheGasEditorTarget : TargetRules
{
	public LightingTheGasEditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;
		DefaultBuildSettings = BuildSettingsVersion.V2;
		IncludeOrderVersion = EngineIncludeOrderVersion.Unreal5_1;
		ExtraModuleNames.Add("LightingTheGas");
	}
}