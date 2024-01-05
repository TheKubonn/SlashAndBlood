// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Item.generated.h"

/* EditDefaultsOnly - Pozwala na edycjê wartoœci w BP ale tylko w g³ównym BP, na scenie nie */
/* EditInstanceOnly - Pozwala na edycjê wartoœci w BP na scenie, ale nie w g³ównym BP */
/* EditAnywhere - Pozwala na edycjê wartoœci i w g³ównym BP, jak i równie¿ na scenie */
/* VisibleDefaultsOnly - Pozwala widzieæ dan¹ wartoœæ w g³ównym BP, ale nie mo¿na jej zmieniæ w BP */
/* VisibleInstanceOnly - Pozwala widzieæ dan¹ wartoœæ w BP na scenie, ale nie mo¿na jej zmieniæ */
/* VisibleAnywhere - Pozwala widzieæ dan¹ wartoœæ w g³ównym BP jak i na scenie, ale nie mo¿na jej zmieniæ */

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
