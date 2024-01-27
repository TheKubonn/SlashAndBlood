// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Interfaces/HitInterface.h"
#include "Characters/CharacterTypes.h"
#include "Enemy.generated.h"

class UAnimMontage;
class USoundBase;
class UParticleSystem;
class UAttributeComponent;
class UHealthBarComponent;
class AAIController;

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

	virtual float TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent, class AController* EventInstigator, AActor* DamageCauser) override;

private:

	UPROPERTY(VisibleAnywhere)
	TObjectPtr <UAttributeComponent> Attributes;
	UPROPERTY(VisibleAnywhere)
	TObjectPtr <UHealthBarComponent> HealthBarWidget;

	UPROPERTY(EditAnywhere)
	float LifeSpanTimer = 30.f;

	UPROPERTY()
	TObjectPtr <AActor> CombatTarget;

	UPROPERTY(EditAnywhere)
	double CombatRadius = 700.f;

	/**
	* Navigation
	**/

	UPROPERTY()
	TObjectPtr <AAIController> EnemyController;

	// Current Patrol Target
	UPROPERTY(EditInstanceOnly, Category = "AI Navigation")
	TObjectPtr <AActor> PatrolTarget;

	UPROPERTY(EditInstanceOnly, Category = "AI Navigation")
	TArray <TObjectPtr<AActor>> PatrolTargets;

	/**
	* Animation Montages
	**/

	UPROPERTY(EditDefaultsOnly, Category = "Montages")
	UAnimMontage* HitReactMontage;

	UPROPERTY(EditDefaultsOnly, Category = "Montages")
	TObjectPtr <UAnimMontage> DeathMontage;

	UPROPERTY(EditAnywhere, Category = "Sounds")
	USoundBase* HitSound;

	UPROPERTY(EditAnywhere, Category = "VisualEffects")
	UParticleSystem* HitParticle;


protected:
	virtual void BeginPlay() override;

	void Die();

	/**
	*	Play Montage Functions
	*/

	void PlayHitReactMontage(const FName& SectionName);

	UPROPERTY(BlueprintReadOnly)
	EDeathPose DeathPose = EDeathPose::EDP_Alive;

public:	

};
