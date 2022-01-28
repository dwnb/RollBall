// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RotationActorBase.generated.h"

UCLASS()
class ROLLBALL_API ARotationActorBase : public AActor
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		class UStaticMeshComponent* StaticBase;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FRotator Angle;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float roll;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float yaw;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float pitch;
public:	
	// Sets default values for this actor's properties
	ARotationActorBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	inline void SetRotate();
};
