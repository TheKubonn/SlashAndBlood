// Fill out your copyright notice in the Description page of Project Settings.


#include "Items/Item.h"

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
		GEngine->AddOnScreenDebugMessage(1, 60.f, FColor::Cyan, FString("Hello World!"));
	}

	UE_LOG(LogTemp, Error, TEXT("Second UE_LOG output"));
	
	
}

void AItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

