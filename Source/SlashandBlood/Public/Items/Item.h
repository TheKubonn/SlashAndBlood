// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Item.generated.h"

										/* UPROPERTY RODZAJE */
/* EditDefaultsOnly - Pozwala na edycjê wartoœci w BP ale tylko w g³ównym BP, na scenie nie */
/* EditInstanceOnly - Pozwala na edycjê wartoœci w BP na scenie, ale nie w g³ównym BP */
/* EditAnywhere - Pozwala na edycjê wartoœci i w g³ównym BP, jak i równie¿ na scenie */
/* VisibleDefaultsOnly - Pozwala widzieæ dan¹ wartoœæ w g³ównym BP, ale nie mo¿na jej zmieniæ w BP */
/* VisibleInstanceOnly - Pozwala widzieæ dan¹ wartoœæ w BP na scenie, ale nie mo¿na jej zmieniæ */
/* VisibleAnywhere - Pozwala widzieæ dan¹ wartoœæ w g³ównym BP jak i na scenie, ale nie mo¿na jej zmieniæ */
/* BlueprintReadOnly - Pozwala wywo³aæ zmienn¹ w event graphie, ale nie mo¿na jej zmieniæ !!!! Mo¿na u¿yæ w prywatnej sekcji tylko je¿eli jest meta meta = (AllowPrivateAccess = "true") */
/* BlueprintReadWrite - Pozwala wywo³aæ zmienn¹ w event graphie oraz j¹ zmieniaæ !!!! Mo¿na u¿yæ w prywatnej sekcji tylko je¿eli jest meta meta = (AllowPrivateAccess = "true") */
/* Category = "" - Dodajesz zmienn¹ do danej kategorii któr¹ bêdzie widaæ w BP */

										/* UFUNCTION RODZAJE */
/* BlueprintCallable - Mo¿na wywo³aæ funkcje w BP */
/* BlueprintPure - Mo¿na wywo³aæ funkcje w BP która tylko daje output value, nie zmienia niczego */

class USphereComponent;

UCLASS()
class SLASHANDBLOOD_API AItem : public AActor
{
	GENERATED_BODY()
	
public:	
	AItem();
	virtual void Tick(float DeltaTime) override;

protected:
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sine Parameters")
	float Amplitude = 0.25f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sine Parameters")
	float TimeConstant = 5.f;

	UFUNCTION(BlueprintCallable)
	float TransformedSin(float Value);
	
	UFUNCTION(BlueprintPure)
	float TransformedCosin();

	template<typename T>
	T Avg(T First, T Second);
	
	UFUNCTION()
	virtual void OnSphereOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
	virtual void OnSphereEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	float RunningTime;

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* ItemMesh;

	UPROPERTY(VisibleAnywhere)
	USphereComponent* Sphere;

};

template<typename T>
inline T AItem::Avg(T First, T Second)
{
	return (First + Second) / 2;
}
