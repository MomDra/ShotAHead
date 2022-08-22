// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "ShotAHead.h"
#include "GameFramework/Actor.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Ball.generated.h"

UCLASS()
class SHOTAHEAD_API ABall : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABall();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(VisibleAnywhere, Category = Visual)
		//USkeletalMeshComponent* Mesh;
		UStaticMeshComponent* Mesh;

	UPROPERTY(VisibleAnywhere, Category = Collision)
		UBoxComponent* Box;
		//USphereComponent* Sphere;

	UPROPERTY(EditAnywhere, meta = (AllowPrivateAccess = true))
		TSubclassOf<AActor> ActorToSpawn;

	UPROPERTY(VisibleAnywhere, Category = Movement)
		UProjectileMovementComponent* Movement;
};
