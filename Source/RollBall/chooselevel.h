// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "HitBoxbase.h"
#include "chooselevel.generated.h"

/**
 * 
 */
UCLASS()
class ROLLBALL_API Achooselevel : public AHitBoxbase
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FName  Level_Name;
public:
	virtual void OnHit(class ABallBase* Ball)override;
};
