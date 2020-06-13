#include "PracticasCppGameModeBase.h"
#include "Engine/World.h"

APracticasCppGameModeBase::APracticasCppGameModeBase()
{
	PrimaryActorTick.bCanEverTick = true;
}

void APracticasCppGameModeBase::Tick(float deltaSeconds)
{
	if (pickedObjectives >= objectivesToPick)
	{
		GetWorld()->ServerTravel("win");
	}
}