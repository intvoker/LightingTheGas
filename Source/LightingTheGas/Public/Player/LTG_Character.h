// Copyright intvoker. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemInterface.h"
#include "GameFramework/Character.h"
#include "InputActionValue.h"
#include "LTG_CharacterData.h"
#include "LTG_Character.generated.h"

class UCameraComponent;
class UInputAction;
class UInputMappingContext;
class ULTG_AbilitySystemComponent;
class ULTG_AttributeSet;
class ULTG_CharacterDataAsset;
class USpringArmComponent;

UCLASS(config=Game)
class ALTG_Character : public ACharacter, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	ALTG_Character(const FObjectInitializer& ObjectInitializer);

	/** Returns CameraBoom subobject **/
	FORCEINLINE USpringArmComponent* GetCameraBoom() const { return CameraBoom; }
	/** Returns FollowCamera subobject **/
	FORCEINLINE UCameraComponent* GetFollowCamera() const { return FollowCamera; }

	virtual void PostInitializeComponents() override;

	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;

protected:
	UPROPERTY(EditDefaultsOnly)
	ULTG_AbilitySystemComponent* AbilitySystemComponent;

	UPROPERTY(Transient)
	ULTG_AttributeSet* AttributeSet;

	UPROPERTY()
	FLTG_CharacterData DefaultCharacterData;

	UPROPERTY(EditDefaultsOnly)
	ULTG_CharacterDataAsset* CharacterDataAsset;

	UPROPERTY(EditDefaultsOnly, Category = "GAS")
	float DefaultLevel = 1.0f;

	// To add mapping context
	virtual void BeginPlay() override;

	// APawn interface
	virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;

	/** Called for movement input */
	void Move(const FInputActionValue& Value);

	/** Called for looking input */
	void Look(const FInputActionValue& Value);

	virtual void PossessedBy(AController* NewController) override;

	virtual void OnRep_PlayerState() override;

	void GiveDefaultAbilities();

	void ApplyDefaultEffects();

private:
	/** Camera boom positioning the camera behind the character */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	USpringArmComponent* CameraBoom;

	/** Follow camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	UCameraComponent* FollowCamera;

	/** MappingContext */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputMappingContext* DefaultMappingContext;

	/** Jump Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* JumpAction;

	/** Move Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* MoveAction;

	/** Look Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* LookAction;
};
