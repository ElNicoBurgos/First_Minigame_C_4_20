#include "VerticalTrap.h"
#include "TimerManager.h"
#include "PlayerBase.h"

AVerticalTrap::AVerticalTrap()
{
 	PrimaryActorTick.bCanEverTick = true;
}

void AVerticalTrap::BeginPlay()
{
	Super::BeginPlay();
	GetWorldTimerManager().SetTimer(timerHandle, this, &AVerticalTrap::ChangeDirection, changeTime, true);
	OnActorBeginOverlap.AddDynamic(this, &AVerticalTrap::OnOverlap);
}

void AVerticalTrap::Tick(float DeltaTime)
{
	FVector movement(0, 0, 0);
	movement.Z = velocity * DeltaTime;
	AddActorLocalOffset(movement, true);
}

void AVerticalTrap::ChangeDirection()
{
	velocity *= -1;
}

void AVerticalTrap::OnOverlap(AActor* me, AActor* other)
{
	APlayerBase* pb = Cast<APlayerBase>(other);
	if (pb != nullptr)
	{
		pb->life -= damage;
	}
}