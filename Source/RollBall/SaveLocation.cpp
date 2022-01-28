// Fill out your copyright notice in the Description page of Project Settings.


#include "SaveLocation.h"
#include "HitBoxbase.h"
#include "Components/BoxComponent.h"
#include "RollBallGameModeBase.h"
#include "Components/StaticMeshComponent.h"
ASaveLocation::ASaveLocation() {
	SaveMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("SaveMesh"));
	this->Comp_HitBox->SetupAttachment(SaveMesh);
}
void ASaveLocation::OnHit(class ABallBase* Ball) {
	if (auto x = Cast<ARollBallGameModeBase>(GetWorld()->GetAuthGameMode())) {
		x->setCurrentStart(this->Comp_HitBox->GetComponentLocation());
	}
}