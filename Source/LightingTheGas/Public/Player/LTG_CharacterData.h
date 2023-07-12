// Copyright intvoker. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "LTG_CharacterData.generated.h"

class UGameplayAbility;
class UGameplayEffect;

USTRUCT()
struct FLTG_CharacterData
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditDefaultsOnly, Category = "GAS")
	TArray<TSubclassOf<UGameplayAbility>> GameplayAbilityClasses;

	UPROPERTY(EditDefaultsOnly, Category = "GAS")
	TArray<TSubclassOf<UGameplayEffect>> GameplayEffectClasses;
};
