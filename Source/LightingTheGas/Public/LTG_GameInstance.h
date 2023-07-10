// Copyright intvoker. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "LTG_GameInstance.generated.h"

/**
 * 
 */
UCLASS()
class LIGHTINGTHEGAS_API ULTG_GameInstance : public UGameInstance
{
	GENERATED_BODY()

public:
	virtual void Init() override;

};
