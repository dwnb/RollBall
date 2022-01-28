// Fill out your copyright notice in the Description page of Project Settings.


#include "chooselevel.h"
#include "Engine.h"
#include "BallBase.h"
#include "RollBallGameModeBase.h"

void Achooselevel::OnHit(ABallBase* Ball)
{
	if (auto x = Cast<ARollBallGameModeBase>(GetWorld()->GetAuthGameMode())) {
		x->OpenLevel(Level_Name);
	}
}
