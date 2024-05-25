// Copyright Liu Long


#include "PassiveAbilityComponent.h"

#include "GameplayAbilitySpec.h"
#include "MeleeAbilitySystemComponent.h"
#include "MeleeGameplayAbility.h"

// Sets default values for this component's properties
UPassiveAbilityComponent::UPassiveAbilityComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UPassiveAbilityComponent::BeginPlay()
{
	Super::BeginPlay();
	GrantPassiveAbilities();
	// ...
	
}


// Called every frame
void UPassiveAbilityComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

FGameplayAbilitySpecHandle UPassiveAbilityComponent::GetGrantedPassiveGa() const
{
	return GrantedPassiveGa;
}

void UPassiveAbilityComponent::GrantPassiveAbilities()
{
	AActor* ownerActor = GetOwner();
	AMeleeWanderCharacter* ownerCharacter = Cast<AMeleeWanderCharacter>(ownerActor);
	UMeleeAbilitySystemComponent* ASC = ownerCharacter->GetMeleeAbilitySystemComponent();
	check(ASC);

	if (!ASC->IsOwnerActorAuthoritative())
	{
		// Must be authoritative to give or take ability sets.
		return;
	}

	// Grant the gameplay abilities.
	for (int32 AbilityIndex = 0; AbilityIndex < GrantedGameplayAbilities.Num(); ++AbilityIndex)
	{
		const FMeleeAbilitySet_GameplayAbility& AbilityToGrant = GrantedGameplayAbilities[AbilityIndex];

		if (!IsValid(AbilityToGrant.Ability))
		{
			//UE_LOG("", Error, TEXT("GrantedGameplayAbilities[%d] on ability set [%s] is not valid."), AbilityIndex, *GetNameSafe(this));
			continue;
		}

		UMeleeGameplayAbility* AbilityCDO = AbilityToGrant.Ability->GetDefaultObject<UMeleeGameplayAbility>();

		FGameplayAbilitySpec AbilitySpec(AbilityCDO, AbilityToGrant.AbilityLevel);
		AbilitySpec.SourceObject = ownerActor;
		AbilitySpec.DynamicAbilityTags.AddTag(AbilityToGrant.InputTag);

		const FGameplayAbilitySpecHandle AbilitySpecHandle = ASC->GiveAbility(AbilitySpec);
		//Cache the object for test dodge
		GrantedPassiveGa = AbilityCDO;
	}

}

