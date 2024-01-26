// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Interfaces/HitInterface.h"
#include "Enemy.generated.h"

class UAnimMontage;
class USoundBase;
class UParticleSystem;
class UAttributeComponent;
class UWidgetComponent;

UCLASS()
class SLASHANDBLOOD_API AEnemy : public ACharacter, public IHitInterface
{
	GENERATED_BODY()

public:
	AEnemy();

	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	virtual void GetHit_Implementation(const FVector& ImpactPoint) override;

	void DirectionalHitReact(const FVector& ImpactPoint);

private:

	UPROPERTY(VisibleAnywhere)
	TObjectPtr <UAttributeComponent> Attributes;
	UPROPERTY(VisibleAnywhere)
	TObjectPtr <UWidgetComponent> HealthBarWidget;

	/**
	* Animation Montages
	**/

	UPROPERTY(EditDefaultsOnly, Category = "Montages")
	UAnimMontage* HitReactMontage;

	UPROPERTY(EditAnywhere, Category = "Sounds")
	USoundBase* HitSound;

	UPROPERTY(EditAnywhere, Category = "VisualEffects")
	UParticleSystem* HitParticle;

protected:
	virtual void BeginPlay() override;

	/**
	*	Play Montage Functions
	*/

	void PlayHitReactMontage(const FName& SectionName);

public:	

};
