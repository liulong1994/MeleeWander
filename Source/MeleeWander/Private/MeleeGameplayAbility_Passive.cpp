// Copyright Liu Long


#include "MeleeGameplayAbility_Passive.h"

#include "MeleeWander/MeleeWanderCharacter.h"

UMeleeGameplayAbility_Passive::UMeleeGameplayAbility_Passive(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
}


bool UMeleeGameplayAbility_Passive::CanActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayTagContainer* SourceTags, const FGameplayTagContainer* TargetTags, FGameplayTagContainer* OptionalRelevantTags) const
{
	bool bResult = Super::CanActivateAbility(Handle, ActorInfo, SourceTags, TargetTags, OptionalRelevantTags);

	if (bResult)
	{
		UE_LOG(LogTemplateCharacter, Display, TEXT("CanActivateAbility True"));
	}
	UE_LOG(LogTemplateCharacter, Error, TEXT("CanActivateAbility False"));

	return bResult;
}

void UMeleeGameplayAbility_Passive::ActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, const FGameplayEventData* TriggerEventData)
{
	// Bind target data callback
	//UAbilitySystemComponent* MyAbilityComponent = CurrentActorInfo->AbilitySystemComponent.Get();
	//check(MyAbilityComponent);
	UE_LOG(LogTemplateCharacter, Display, TEXT("ActivateAbility"));
	Super::ActivateAbility(Handle, ActorInfo, ActivationInfo, TriggerEventData);
}

void UMeleeGameplayAbility_Passive::EndAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, bool bReplicateEndAbility, bool bWasCancelled)
{
	UE_LOG(LogTemplateCharacter, Display, TEXT("EndAbility"));
	Super::EndAbility(Handle, ActorInfo, ActivationInfo, bReplicateEndAbility, bWasCancelled);

}

