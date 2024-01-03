// Fill out your copyright notice in the Description page of Project Settings.


#include "Items/Item.h"
#include "DrawDebugHelpers.h"

AItem::AItem()
{
	PrimaryActorTick.bCanEverTick = true;

}

void AItem::BeginPlay()
{
	Super::BeginPlay();

	UE_LOG(LogTemp, Warning, TEXT("Begin Play called!"));

	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(1, 60.f, FColor::Blue, FString("Hello World!"));
	}

	UWorld* DebugWorld = GetWorld();

	if (DebugWorld)
	{
		
	}
	
}

void AItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

