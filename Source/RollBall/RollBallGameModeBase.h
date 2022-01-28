// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "RollBallGameModeBase.generated.h"


/**
 * 
 */
UCLASS()
class ROLLBALL_API ARollBallGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayPawn")
		class ABallBase* Play_Pawn;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayPawn")
		FVector CurrentStart;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool isEnd;


	TArray<AActor*> Actors;
public:
	ARollBallGameModeBase();
	virtual void BeginPlay();
	virtual void Tick(float DeltaTime) override;
	void setBallLocation();
	void setBallLocation(FVector &start);

	void setCurrentStart(FVector FV);
	void SetLR();
	void SetEnd();
	void OpenLevel(FName str);
};
