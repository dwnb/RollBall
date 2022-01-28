// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "HitBoxbase.h"
#include "RotationHitBox.generated.h"
/**
 * 
 */
UCLASS()
class ROLLBALL_API ARotationHitBox : public AHitBoxbase
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		class UStaticMeshComponent* StaticMesh;

	FVector FV;
	FRotator FR;

public:
	ARotationHitBox();
	virtual void OnHit(class ABallBase* Ball)override;
	void setLocation();
	void GETLocationAndRotation();
};
