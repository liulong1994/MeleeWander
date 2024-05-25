// Copyright Liu Long

#pragma once

#include "CoreMinimal.h"
#include "GameplayAbilitySpecHandle.h"
#include "GameplayTagContainer.h"
#include "Components/ActorComponent.h"
#include "MeleeWander/MeleeWanderCharacter.h"
#include "PassiveAbilityComponent.generated.h"

/**
 * FMeleeAbilitySet_GameplayAbility
 *
 *	Data used by the ability set to grant gameplay abilities.
 */
USTRUCT(BlueprintType)
struct FMeleeAbilitySet_GameplayAbility
{
	GENERATED_BODY()

public:

	// Gameplay ability to grant.
	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<UMeleeGameplayAbility> Ability = nullptr;

	// Level of ability to grant.
	UPROPERTY(EditDefaultsOnly)
	int32 AbilityLevel = 1;

	// Tag used to process input for the ability.
	UPROPERTY(EditDefaultsOnly, Meta = (Categories = "InputTag"))
	FGameplayTag InputTag;
};



UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class MELEEWANDER_API UPassiveAbilityComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UPassiveAbilityComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	FGameplayAbilitySpecHandle GetGrantedPassiveGa() const;

protected:
	// Gameplay abilities to grant when this ability set is granted.
	UPROPERTY(EditDefaultsOnly, Category = "Gameplay Abilities", meta=(TitleProperty=Ability))
	TArray<FMeleeAbilitySet_GameplayAbility> GrantedGameplayAbilities;
	void GrantPassiveAbilities();
	AActor* owner;

	FGameplayAbilitySpecHandle GrantedPassiveGa;
};
