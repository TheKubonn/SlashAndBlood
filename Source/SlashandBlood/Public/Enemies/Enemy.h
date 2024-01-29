// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Characters/BaseCharacter.h"
#include "Characters/CharacterTypes.h"
#include "Enemy.generated.h"

class UHealthBarComponent;
class AAIController;
class UPawnSensingComponent;

UCLASS()
class SLASHANDBLOOD_API AEnemy : public ABaseCharacter
{
	GENERATED_BODY()

public:
	AEnemy();

	virtual void Tick(float DeltaTime) override;
	void CheckPatrolTarget();
	void CheckCombatTarget();
	// virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	virtual void GetHit_Implementation(const FVector& ImpactPoint) override;
	virtual float TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent, class AController* EventInstigator, AActor* DamageCauser) override;
	virtual void Destroyed() override;

private:

	UPROPERTY(VisibleAnywhere)
	TObjectPtr <UHealthBarComponent> HealthBarWidget;

	UPROPERTY(VisibleAnywhere)
	TObjectPtr <UPawnSensingComponent> PawnSensing;

	UPROPERTY(EditAnywhere, Category = "Combat")
	float LifeSpanTimer = 10.f;

	UPROPERTY(EditAnywhere)
	TSubclassOf <class AWeapon> WeaponClass;

	/**
	* Navigation
	**/

	UPROPERTY()
	TObjectPtr <AAIController> EnemyController;

	UPROPERTY()
	TObjectPtr <AActor> CombatTarget;

	UPROPERTY(EditAnywhere)
	double CombatRadius = 1000.f;

	UPROPERTY(EditAnywhere)
	double AttackRadius = 150.f;

	// Current Patrol Target
	UPROPERTY(EditInstanceOnly, Category = "AI Navigation")
	TObjectPtr <AActor> PatrolTarget;

	UPROPERTY(EditInstanceOnly, Category = "AI Navigation")
	TArray <TObjectPtr<AActor>> PatrolTargets;

	UPROPERTY(EditAnywhere)
	double PatrolRadius = 200.f;

	FTimerHandle PatrolTimer;
	void PatrolTimerFinished();

	UPROPERTY(EditAnywhere, Category = "AI Navigation")
	float WaitMin = 5.f;
	UPROPERTY(EditAnywhere, Category = "AI Navigation")
	float WaitMax = 10.f;

	UPROPERTY(EditAnywhere, Category = "Combat")
	float PatrollingSpeed = 125.f;

	UPROPERTY(EditAnywhere, Category = "Combat")
	float ChasingSpeed = 300.f;

	/**
	* AI Behaviour
	**/

	void HideHealthBar();
	void ShowHealthBar();
	void LoseInterest();
	void StartPatrolling();
	void ChaseTarget();
	void ClearPatrolTimer();
	bool IsOutsideCombatRadius();
	bool IsOutsideAttackRadius();
	bool IsInsideAttackRadius();
	bool IsChasing();
	bool IsAttacking();
	bool IsDead();
	bool IsEngaged();

	/**
	* Combat Behaviour
	**/
	void StartAttackTimer();
	void ClearAttackTimer();

	FTimerHandle AttackTimer;

	UPROPERTY(EditAnywhere, Category = "Combat")
	float AttackMin = 0.5f;

	UPROPERTY(EditAnywhere, Category = "Combat")
	float AttackMax = 1.f;

protected:
	virtual void BeginPlay() override;
	virtual void Die() override;
	bool InTargetRange(TObjectPtr<AActor> Target, double Radius);
	void MoveToTarget(TObjectPtr <AActor> Target);
	virtual void Attack() override;
	virtual bool CanAttack() override;
	virtual void HandleDamage(float DamageAmount) override;
	virtual int32 PlayDeathMontage() override;
	virtual void AttackEnd() override;

	TObjectPtr <AActor> ChoosePatrolTarget();

	UFUNCTION()
	void PawnSeen(APawn* SeenPawn);

	UPROPERTY(BlueprintReadOnly)
	TEnumAsByte <EDeathPose> DeathPose;

	UPROPERTY(BlueprintReadOnly)
	EEnemyState EnemyState = EEnemyState::EES_Patrolling;

public:	

};
