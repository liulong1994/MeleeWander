// Copyright Liu Long

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "MeleeAbilitySystemComponent.generated.h"

class AActor;
class UGameplayAbility;
class UObject;

/**
 * 
 */
UCLASS()
class UMeleeAbilitySystemComponent : public UAbilitySystemComponent
{
	GENERATED_BODY()
	UMeleeAbilitySystemComponent(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());
};
