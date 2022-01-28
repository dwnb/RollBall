// Fill out your copyright notice in the Description page of Project Settings.


#include "DieBox.h"
#include "BallBase.h"
#include "Engine.h"
#include "RollBallGameModeBase.h"
void ADieBox::OnHit(ABallBase* ball){
	if (auto x = Cast<ARollBallGameModeBase>(GetWorld()->GetAuthGameMode())) {
		x->setBallLocation();
		x->SetLR();
	}
	//ball->XY=FVector(0.f, 0.f, 0.f);
}