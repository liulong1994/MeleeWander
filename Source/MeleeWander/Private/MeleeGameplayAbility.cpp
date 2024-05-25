// Copyright Liu Long


#include "MeleeGameplayAbility.h"

#include "MeleeAbilitySystemComponent.h"

UMeleeGameplayAbility::UMeleeGameplayAbility(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	//Initializer
}

UMeleeAbilitySystemComponent* UMeleeGameplayAbility::GetMeleeAbilitySystemComponentFromActorInfo() const
{
	return (CurrentActorInfo ? Cast<UMeleeAbilitySystemComponent>(CurrentActorInfo->AbilitySystemComponent.Get()) : nullptr);
}

