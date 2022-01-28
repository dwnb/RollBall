// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "BallBase.generated.h"

UCLASS()
class ROLLBALL_API ABallBase : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ABallBase();

	UPROPERTY(EditAnywhere,BlueprintReadWrite)
		class UStaticMeshComponent* Com_SphereMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CameraArm")
		class USpringArmComponent*  Com_CameraArm;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Camera")
		class UCameraComponent*     Com_Camera;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool CanBeMove;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Speed")
		float SphereSpeed;

	FVector XY;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION()
		void MoveForward(float x);
	UFUNCTION()
		void MoveRight(float y);
};
