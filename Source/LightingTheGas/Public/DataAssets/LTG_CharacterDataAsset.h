// Copyright intvoker. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "Player/LTG_CharacterData.h"
#include "LTG_CharacterDataAsset.generated.h"

/**
 * 
 */
UCLASS()
class LIGHTINGTHEGAS_API ULTG_CharacterDataAsset : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly)
	FLTG_CharacterData CharacterData;
};
