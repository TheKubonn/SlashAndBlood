// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Item.generated.h"

										/* UPROPERTY RODZAJE */
/* EditDefaultsOnly - Pozwala na edycj� warto�ci w BP ale tylko w g��wnym BP, na scenie nie */
/* EditInstanceOnly - Pozwala na edycj� warto�ci w BP na scenie, ale nie w g��wnym BP */
/* EditAnywhere - Pozwala na edycj� warto�ci i w g��wnym BP, jak i r�wnie� na scenie */
/* VisibleDefaultsOnly - Pozwala widzie� dan� warto�� w g��wnym BP, ale nie mo�na jej zmieni� w BP */
/* VisibleInstanceOnly - Pozwala widzie� dan� warto�� w BP na scenie, ale nie mo�na jej zmieni� */
/* VisibleAnywhere - Pozwala widzie� dan� warto�� w g��wnym BP jak i na scenie, ale nie mo�na jej zmieni� */
/* BlueprintReadOnly - Pozwala wywo�a� zmienn� w event graphie, ale nie mo�na jej zmieni� !!!! Mo�na u�y� w prywatnej sekcji tylko je�eli jest meta meta = (AllowPrivateAccess = "true") */
/* BlueprintReadWrite - Pozwala wywo�a� zmienn� w event graphie oraz j� zmienia� !!!! Mo�na u�y� w prywatnej sekcji tylko je�eli jest meta meta = (AllowPrivateAccess = "true") */
/* Category = "" - Dodajesz zmienn� do danej kategorii kt�r� b�dzie wida� w BP */

										/* UFUNCTION RODZAJE */
/* BlueprintCallable - Mo�na wywo�a� funkcje w BP */
/* BlueprintPure - Mo�na wywo�a� funkcje w BP kt�ra tylko daje output value, nie zmienia niczego */

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
