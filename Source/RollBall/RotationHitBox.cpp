// Fill out your copyright notice in the Description page of Project Settings.


#include "RotationHitBox.h"
#include "BallBase.h"
#include "HitBoxbase.h"
#include "Components/StaticMeshComponent.h"
#include "Components/BoxComponent.h"
ARotationHitBox::ARotationHitBox() {
	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	this->Comp_HitBox->SetupAttachment(StaticMesh);

	
}
void ARotationHitBox::OnHit(ABallBase* Ball)
{
	StaticMesh->SetSimulatePhysics(true);
}
void ARotationHitBox::GETLocationAndRotation() {
	FV = this->GetActorLocation();
	FR = this->GetActorRotation();
}
void ARotationHitBox::setLocation() {
	this->SetActorLocationAndRotation(FV,FR);
}
