// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Interfaces/HitInterface.h"
#include "BaseCharacter.generated.h"

class AWeapon;
class UAttributeComponent;
class UAnimMontage;
class USoundBase;
class UParticleSystem;

UCLASS()
class SLASHANDBLOOD_API ABaseCharacter : public ACharacter, public IHitInterface
{
	GENERATED_BODY()

public:
	ABaseCharacter();
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable)
	void SetWeaponCollisionEnabled(ECollisionEnabled::Type CollisionEnabled);

protected:
	virtual void BeginPlay() override;
	virtual void Attack();
	virtual void Die();

	/**
	*	Play Montage Functions
	*/

	virtual void PlayAttackMontage();
	void PlayHitReactMontage(const FName& SectionName);
	void DirectionalHitReact(const FVector& ImpactPoint);

	virtual bool CanAttack();

	UFUNCTION(BlueprintCallable)
	virtual void AttackEnd();

	/**
	* Animation Montages
	**/

	UPROPERTY(EditDefaultsOnly, Category = "Montages")
	UAnimMontage* AttackMontage;

	UPROPERTY(EditDefaultsOnly, Category = "Montages")
	UAnimMontage* HitReactMontage;

	UPROPERTY(EditDefaultsOnly, Category = "Montages")
	TObjectPtr <UAnimMontage> DeathMontage;

	UPROPERTY(VisibleAnywhere, Category = "Weapon")
	TObjectPtr <AWeapon> EquippedWeapon;

	/**
	* Components
	**/

	UPROPERTY(VisibleAnywhere)
	TObjectPtr <UAttributeComponent> Attributes;

	UPROPERTY(EditAnywhere, Category = "Sounds")
	USoundBase* HitSound;

	UPROPERTY(EditAnywhere, Category = "VisualEffects")
	UParticleSystem* HitParticle;

};
