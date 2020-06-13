// Fill out your copyright notice in the Description page of Project Settings.

#include "Checkpoint.h"
#include "PlayerBase.h"

void ACheckpoint::BeginPlay()
{
	Super::BeginPlay();
	OnActorBeginOverlap.AddDynamic(this, &ACheckpoint::OnOverlap);
}


void ACheckpoint::OnOverlap(AActor* me, AActor* other)
{
	APlayerBase* player = Cast<APlayerBase>(other);
	if (player != nullptr && player->currentCheckpoint != this)
	{
		player->initialPosition = GetActorLocation();
		player->initialRotation = GetActorRotation();

		if (player->currentCheckpoint != nullptr)
			player->currentCheckpoint->AddActorLocalOffset(FVector(0, 0, 20));

		player->currentCheckpoint = this;
		AddActorLocalOffset(FVector(0, 0, -20));
	}
}