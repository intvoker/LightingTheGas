// Copyright intvoker. All Rights Reserved.


#include "LTG_GameInstance.h"

#include "AbilitySystemGlobals.h"

void ULTG_GameInstance::Init()
{
	Super::Init();

	UAbilitySystemGlobals::Get().InitGlobalData();
}
