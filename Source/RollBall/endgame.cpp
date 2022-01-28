// Fill out your copyright notice in the Description page of Project Settings.


#include "endgame.h"
#include "Engine.h"
#include "RollBallGameModeBase.h"
void Aendgame::OnHit(class ABallBase* Ball){
	if (auto x= Cast<ARollBallGameModeBase>(GetWorld()->GetAuthGameMode())) {
		x->SetEnd();
	}
}