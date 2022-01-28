// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "HitBoxbase.h"
#include "DieBox.generated.h"

/**
 * 
 */
UCLASS()
class ROLLBALL_API ADieBox : public AHitBoxbase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite,Category = "RestartXYZ")
		FVector Location_XYZ;
public:
	virtual void OnHit(class ABallBase * ball)override;
};
