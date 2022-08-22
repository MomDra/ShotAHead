// Fill out your copyright notice in the Description page of Project Settings.

#include "Ground.h"

// Sets default values
AGround::AGround()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;


	Body = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BODY"));
	Movement = CreateDefaultSubobject<URotatingMovementComponent>(TEXT("MOVEMENT"));

	RootComponent = Body;

	static ConstructorHelpers::FObjectFinder<UStaticMesh> GR_BODY(TEXT("StaticMesh'/Game/Ground/Nature_Pack_-_Low_Polly_Trees___Bushes/Models/tree_2.tree_2'"));
	if (GR_BODY.Succeeded()) {
		Body->SetStaticMesh(GR_BODY.Object);
	}

	RotateSpeed = 30.0f;
	Movement->RotationRate = FRotator(0.0f, RotateSpeed, 0.0f);
}

// Called when the game starts or when spawned
void AGround::BeginPlay()
{
	Super::BeginPlay();
	
	//UE_LOG(ShotAHead, Warning, TEXT("Actor Name: %s, Location X: %.3f"), *GetName(), GetActorLocation().X);

	ABLOG_S(Warning);
	ABLOG(Warning, TEXT("Actor Name: %s, Location X: %.3f"), *GetName(), GetActorLocation().X);
}

void AGround::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);
	ABLOG_S(Warning);
}

void AGround::PostInitializeComponents()
{
	Super::PostInitializeComponents();
	ABLOG_S(Warning);
}

// Called every frame
void AGround::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AddActorLocalRotation(FRotator(0.0f, RotateSpeed * DeltaTime, 0.0f));
}

