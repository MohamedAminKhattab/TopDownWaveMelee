// Fill out your copyright notice in the Description page of Project Settings.


#include "TD_Character.h"

// Sets default values
ATD_Character::ATD_Character()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 540.0f, 0.0f);
	GetCharacterMovement()->JumpZVelocity = 600.0f;
	GetCharacterMovement()->AirControl = 0.2f;

	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->TargetArmLength = 300.0f;
	CameraBoom->bUsePawnControlRotation = true;

	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);
	FollowCamera->bUsePawnControlRotation = false;
	health=10000;
}

// Called when the game starts or when spawned
void ATD_Character::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void ATD_Character::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (health == 0)
	{
		isDead = true;
	}
}

// Called to bind functionality to input
void ATD_Character::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &ACharacter::StopJumping);

	PlayerInputComponent->BindAction("Attack", IE_Pressed, this, &ATD_Character::Attack);

	PlayerInputComponent->BindAxis("MoveForward", this, &ATD_Character::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &ATD_Character::MoveRight);
}
void ATD_Character::MoveForward(float Axis)
{
	FRotator rotation = Controller->GetControlRotation();
	FRotator YawRotation(0.0f, rotation.Yaw, 0.0f);
	FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
	AddMovementInput(Direction, Axis);
}

void ATD_Character::MoveRight(float Axis)
{
	FRotator rotation = Controller->GetControlRotation();
	FRotator YawRotation(0.0f, rotation.Yaw, 0.0f);
	FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
	AddMovementInput(Direction, Axis);
}

void ATD_Character::Attack()
{
	isAttacking = true;
}