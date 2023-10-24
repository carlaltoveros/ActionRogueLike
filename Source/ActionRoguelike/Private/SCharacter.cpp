// Fill out your copyright notice in the Description page of Project Settings.


#include "SCharacter.h"

#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"

// Sets default values
ASCharacter::ASCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// SETUP create 
	//  these functions are only usable in constructors
	//  templated func, expects a type
	//  arg is the name that will show up in the editor
	//  make sure to add the includes
	SpringArmComp = CreateDefaultSubobject<USpringArmComponent>("SpringArmComp");
	CameraComp = CreateDefaultSubobject<UCameraComponent>("CameraComp");

	// SETUP attachments
	//  attach the components to the right objects 
	//  root component is the capsule of the character we see in the editor
	//  camera component is attached to the spring arm component 
	SpringArmComp->SetupAttachment(RootComponent);
	CameraComp->SetupAttachment(SpringArmComp);
}

// Called when the game starts or when spawned
void ASCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

void ASCharacter::MoveForward(float Value)
{
	AddMovementInput(GetActorForwardVector(), Value);
}

// Called every frame
void ASCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ASCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	// These names need to get assigned later in the editor
	//  project settings --> Input --> AxisBindings 
	PlayerInputComponent->BindAxis("MoveForward", this, &ASCharacter::MoveForward);

	// Roll - air roll rocket league lol, Yaw - horizontal rotation, Pitch - vertical rotation
	PlayerInputComponent->BindAxis("Turn", this, &APawn::AddControllerYawInput);

	
}

