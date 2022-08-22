// Fill out your copyright notice in the Description page of Project Settings.


#include "Ball.h"

// Sets default values
ABall::ABall()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//Mesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("MESH"));
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MESH"));
	Box = CreateDefaultSubobject<UBoxComponent>(TEXT("BOX"));
	//Sphere = CreateDefaultSubobject<USphereComponent>(TEXT("SPHERE"));
	Movement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("MOVEMENT"));

	RootComponent = Box;
	Mesh->SetupAttachment(Box);
	
	//static ConstructorHelpers::FObjectFinder<USkeletalMesh> SWORD(TEXT("SkeletalMesh'/Game/InfinityBladeWeapons/Weapons/Blade/Swords/Blade_BlackKnight/SK_Blade_BlackKnight.SK_Blade_BlackKnight'"));
	/*
	if (SWORD.Succeeded()) {
		Mesh->SetSkeletalMesh(SWORD.Object);
	}*/
	static ConstructorHelpers::FObjectFinder<UStaticMesh> CONE(TEXT("SkeletalMesh'/Engine/BasicShapes/Cone'"));
	if (CONE.Succeeded()) {
		Mesh->SetStaticMesh(CONE.Object);
	}
	
	Mesh->SetRelativeLocation(FVector(0.0f, 0.0f, 0.0f));
	Mesh->SetRelativeScale3D(FVector(0.3f, 0.3f, 0.6f));
	//Sphere->SetSphereRadius(59.0f);
	//Sphere->SetRelativeRotation(FRotator(-90.0f, 0.0f, 0.0f));
	
	Box->SetBoxExtent(FVector(12.0f, 12.0f, 27.4f));
	Box->SetRelativeRotation(FRotator(-90.0f, 0.0f, 0.0f));


	//Movement->InitialSpeed = 10.0f;
	Movement->Velocity = FVector(0.0f, 0.0f, 1000.0f);
	//Movement->SetVelocityInLocalSpace(FVector(10.0f, 0.0f, 0.0f));
	Movement->ProjectileGravityScale = 0.0f;
}

// Called when the game starts or when spawned
void ABall::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ABall::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

