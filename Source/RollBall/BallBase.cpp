// Fill out your copyright notice in the Description page of Project Settings.


#include "BallBase.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/InputComponent.h"

// Sets default values
ABallBase::ABallBase()
{
	CanBeMove = true;
	SphereSpeed = 600.f;
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Com_SphereMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("RootComponent"));
	Com_SphereMesh->SetSimulatePhysics(true);

	Com_CameraArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraArmBase"));
	Com_CameraArm->SetRelativeRotation(FRotator(-40.f, 0.f, 0.f));
	Com_CameraArm->TargetArmLength = 1000.f;
	Com_CameraArm->SetupAttachment(Com_SphereMesh);
	
	
	Com_Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Com_Camera->SetupAttachment(Com_CameraArm);
}

// Called when the game starts or when spawned
void ABallBase::BeginPlay()
{
	Super::BeginPlay();
	
	
}

// Called every frame
void ABallBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	Com_SphereMesh->SetPhysicsAngularVelocity(XY);
}

// Called to bind functionality to input
void ABallBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("MoveForward", this, &ABallBase::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &ABallBase::MoveRight);

}

void ABallBase::MoveForward(float x)
{
	/*FVector move = GetActorLocation();

	move.X += x * 10.f;

	FRotator Rot = GetActorRotation();

	Rot.Pitch = x * 10.f;*/
	//SetActorLocationAndRotation(move, Rot);
	if (CanBeMove) {
		if (x) {
			XY.Y = x * SphereSpeed;
		}else {
			if (XY.Y != 0) {
				XY.Y > 0 ? XY.Y-=20 : XY.Y+=20;
			}
		}
	}
	//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, FString::SanitizeFloat(100.0 * x));
}

void ABallBase::MoveRight(float y)
{
	/*FVector move = GetActorLocation();

	move.Y += y * 10.f;

	FRotator Rot = GetActorRotation();

	Rot.Roll = y * 10.f;
	//SetActorLocationAndRotation(move, Rot);*/

	if (CanBeMove) {
		if (y) {
			XY.X = y * SphereSpeed;
		}
		else {
			if (XY.X != 0) {
				XY.X > 0 ? XY.X-=20 : XY.X+=20;
			}
		}
	}
	//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::SanitizeFloat(y));
}

