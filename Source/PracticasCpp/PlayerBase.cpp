#include "PlayerBase.h"
#include "Engine/World.h"
#include "Components/InputComponent.h"

APlayerBase::APlayerBase()
{
	PrimaryActorTick.bCanEverTick = true;
}

void APlayerBase::BeginPlay()
{
	Super::BeginPlay();
	initialPosition = GetActorLocation();
	initialRotation = GetActorRotation();
	initialLife = life;
}

void APlayerBase::SetupPlayerInputComponent(UInputComponent* inputComponent)
{
	InputComponent->BindAxis("Forward", this, &APlayerBase::ForwardAxis);
	InputComponent->BindAxis("Side", this, &APlayerBase::SideAxis);
}

void APlayerBase::ForwardAxis(float axis)
{
	FVector movement(0, 0, 0);
	movement.X = axis * velocity * GetWorld()->GetDeltaSeconds();
	AddActorLocalOffset(movement, true);
}

void APlayerBase::SideAxis(float axis)
{
	FRotator rotation(0, 0, 0);
	rotation.Yaw = axis * rotationVelocity * GetWorld()->GetDeltaSeconds();
	AddActorLocalRotation(rotation, true);
}

void APlayerBase::Tick(float deltaTime)
{
	if (life <= 0)
	{
		if (respawns > 0)
		{
			SetActorLocation(initialPosition);
			SetActorRotation(initialRotation);
			life = initialLife;
			respawns--;
		}
		else
		{
			Destroy();
		}
	}
}