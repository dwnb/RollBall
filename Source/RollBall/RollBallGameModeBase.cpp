// Copyright Epic Games, Inc. All Rights Reserved.


#include "RollBallGameModeBase.h"
#include "Engine.h"
#include "BallBase.h"
#include "Kismet/GameplayStatics.h"
#include "RotationHitBox.h"



ARollBallGameModeBase::ARollBallGameModeBase()
{
	PrimaryActorTick.bCanEverTick = true;

}
void ARollBallGameModeBase::BeginPlay()
{
	Super::BeginPlay();
	isEnd = false;
	UGameplayStatics::GetAllActorsWithTag(GetWorld(), TEXT("rotphy"), Actors);

	for (AActor* Actor : Actors)
	{
		Cast<ARotationHitBox>(Actor)->GETLocationAndRotation();
	}
	if (ABallBase* x = Cast<ABallBase>(GetWorld()->GetFirstPlayerController()->GetPawn())) {//此处不能放在构造函数中，会造成引擎崩毁，
																							//我的理解是因为获取世界里的东西只能从游戏开始获取
																							//世界里的东西在制作时是随时变化的
		Play_Pawn = x;
		CurrentStart = Play_Pawn->GetActorLocation();
	}
}

void ARollBallGameModeBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ARollBallGameModeBase::setBallLocation()
{
	Play_Pawn->SetActorLocation(CurrentStart);
	Play_Pawn->Com_SphereMesh->SetPhysicsLinearVelocity(FVector(0.f,0.f,0.f));
	Play_Pawn->XY = FVector(0.f, 0.f, 0.f);
}

void ARollBallGameModeBase::setBallLocation(FVector& start) {
	Play_Pawn->SetActorLocation(start);
	Play_Pawn->Com_SphereMesh->SetPhysicsLinearVelocity(FVector(0.f, 0.f, 0.f));
	Play_Pawn->XY = FVector(0.f, 0.f, 0.f);
}

void ARollBallGameModeBase::setCurrentStart(FVector FV)
{
	CurrentStart = FV;
}

void ARollBallGameModeBase::SetLR() {
	for (AActor* Actor : Actors)
	{
		Cast<ARotationHitBox>(Actor)->setLocation();
		Cast<ARotationHitBox>(Actor)->StaticMesh->SetSimulatePhysics(false);
	}
}

void ARollBallGameModeBase::SetEnd() {
	Play_Pawn->CanBeMove = false;
	isEnd = true;
	Play_Pawn->XY = FVector(0.f,0.f,0.f);
}

void ARollBallGameModeBase::OpenLevel(FName str)
{
	UGameplayStatics::OpenLevel(GetWorld(),str);
}
