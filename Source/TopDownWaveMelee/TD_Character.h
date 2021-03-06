// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Components/InputComponent.h"
#include "GameFramework/Controller.h"
#include "GameFramework/CharacterMovementComponent.h"
#include"Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "TD_Character.generated.h"

UCLASS()
class TOPDOWNWAVEMELEE_API ATD_Character : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ATD_Character();
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		int health;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		bool isAttacking = false;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		bool isDead = false;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Camera)
		USpringArmComponent* CameraBoom;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Camera)
		UCameraComponent* FollowCamera;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	void MoveForward(float Axis);
	void MoveRight(float Axis);
	void Attack();
};
