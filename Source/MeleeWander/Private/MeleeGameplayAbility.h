// Copyright Liu Long

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "MeleeGameplayAbility.generated.h"

/**
 * 
 */
UCLASS()
class UMeleeGameplayAbility : public UGameplayAbility
{
	GENERATED_BODY()
public:
	UMeleeGameplayAbility(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

	UFUNCTION(BlueprintCallable, Category = "Melee|Ability")
	UMeleeAbilitySystemComponent* GetMeleeAbilitySystemComponentFromActorInfo() const;
};
