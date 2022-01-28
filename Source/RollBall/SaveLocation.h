// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "HitBoxbase.h"
#include "SaveLocation.generated.h"

/**
 * 
 */
UCLASS()
class ROLLBALL_API ASaveLocation : public AHitBoxbase
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		class UStaticMeshComponent* SaveMesh;
public:
	ASaveLocation();
	virtual void OnHit(class ABallBase* Ball)override;
};
