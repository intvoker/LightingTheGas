// Copyright intvoker. All Rights Reserved.


#include "AbilitySystem/LTG_AttributeSet.h"

#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameplayEffectExtension.h"
#include "Net/UnrealNetwork.h"

void ULTG_AttributeSet::PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data)
{
	Super::PostGameplayEffectExecute(Data);

	if (Data.EvaluatedData.Attribute == GetHealthAttribute())
	{
		SetHealth(FMath::Clamp(GetHealth(), 0.0f, GetMaxHealth()));
	}
	else if (Data.EvaluatedData.Attribute == GetMaxMovementSpeedAttribute())
	{
		if (const auto OwningCharacter = Cast<ACharacter>(GetOwningActor()))
		{
			if (const auto CharacterMovement = OwningCharacter->GetCharacterMovement())
			{
				CharacterMovement->MaxWalkSpeed = GetMaxMovementSpeed();
			}
		}
	}
}

void ULTG_AttributeSet::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME_CONDITION_NOTIFY(ULTG_AttributeSet, Health, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(ULTG_AttributeSet, MaxHealth, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(ULTG_AttributeSet, MaxMovementSpeed, COND_None, REPNOTIFY_Always);
}

void ULTG_AttributeSet::OnRep_Health(const FGameplayAttributeData& OldHealth)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(ULTG_AttributeSet, Health, OldHealth);
}

void ULTG_AttributeSet::OnRep_MaxHealth(const FGameplayAttributeData& OldMaxHealth)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(ULTG_AttributeSet, MaxHealth, OldMaxHealth);
}

void ULTG_AttributeSet::OnRep_MaxMovementSpeed(const FGameplayAttributeData& OldMaxMovementSpeed)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(ULTG_AttributeSet, MaxMovementSpeed, OldMaxMovementSpeed);
}
