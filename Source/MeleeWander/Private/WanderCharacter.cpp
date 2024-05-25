// Fill out your copyright notice in the Description page of Project Settings.


#include "WanderCharacter.h"

// Sets default values
AWanderCharacter::AWanderCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AWanderCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AWanderCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AWanderCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

