// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Item.generated.h"

/* EditDefaultsOnly - Pozwala na edycj� warto�ci w BP ale tylko w g��wnym BP, na scenie nie */
/* EditInstanceOnly - Pozwala na edycj� warto�ci w BP na scenie, ale nie w g��wnym BP */
/* EditAnywhere - Pozwala na edycj� warto�ci i w g��wnym BP, jak i r�wnie� na scenie */
/* VisibleDefaultsOnly - Pozwala widzie� dan� warto�� w g��wnym BP, ale nie mo�na jej zmieni� w BP */
/* VisibleInstanceOnly - Pozwala widzie� dan� warto�� w BP na scenie, ale nie mo�na jej zmieni� */
/* VisibleAnywhere - Pozwala widzie� dan� warto�� w g��wnym BP jak i na scenie, ale nie mo�na jej zmieni� */

UCLASS()
class SLASHANDBLOOD_API AItem : public AActor
{
	GENERATED_BODY()
	
public:	
	AItem();
	virtual void Tick(float DeltaTime) override;

protected:
	virtual void BeginPlay() override;
private:
	UPROPERTY(VisibleAnywhere)
	float RunningTime;
	UPROPERTY(EditAnywhere) 
	float Amplitude = 0.25f;
	UPROPERTY(EditAnywhere)
	float TimeConstant = 5.f;
};
