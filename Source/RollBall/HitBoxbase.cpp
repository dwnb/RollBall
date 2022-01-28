// Fill out your copyright notice in the Description page of Project Settings.


#include "HitBoxbase.h"
#include "Components/BoxComponent.h"
#include "BallBase.h"
#include "Components/SceneComponent.h"
// Sets default values
AHitBoxbase::AHitBoxbase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	

	Comp_HitBox = CreateDefaultSubobject<UBoxComponent>(TEXT("HitBox"));
	Comp_HitBox->OnComponentBeginOverlap.AddDynamic(this,&AHitBoxbase::BeginHit);

}

// Called when the game starts or when spawned
void AHitBoxbase::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AHitBoxbase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AHitBoxbase::OnHit(ABallBase* Ball)
{
}

void AHitBoxbase::BeginHit(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (ABallBase *ball = Cast<ABallBase>(OtherActor)) {
		OnHit(ball);
	}
}

