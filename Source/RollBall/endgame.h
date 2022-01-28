// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "HitBoxbase.h"
#include "endgame.generated.h"

/**
 * 
 */
UCLASS()
class ROLLBALL_API Aendgame : public AHitBoxbase
{
	GENERATED_BODY()
public:
	virtual void OnHit(class ABallBase* Ball)override;
};
