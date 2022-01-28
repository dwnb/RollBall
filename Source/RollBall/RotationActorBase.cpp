// Fill out your copyright notice in the Description page of Project Settings.


#include "RotationActorBase.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
ARotationActorBase::ARotationActorBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	StaticBase = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticBase"));
}

// Called when the game starts or when spawned
void ARotationActorBase::BeginPlay()
{
	Super::BeginPlay();
	
}
inline void ARotationActorBase::SetRotate() {

}
// Called every frame
void ARotationActorBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FRotator NewRotation = this->GetActorRotation();
	
	NewRotation.Roll += DeltaTime * roll;
	NewRotation.Yaw += DeltaTime * yaw;
	NewRotation.Pitch += DeltaTime * pitch;
	this->SetActorRotation(NewRotation);
}

