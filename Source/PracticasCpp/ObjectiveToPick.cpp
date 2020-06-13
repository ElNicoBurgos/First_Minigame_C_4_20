#include "ObjectiveToPick.h"
#include "PlayerBase.h"
#include "PracticasCppGameModeBase.h"
#include "Engine/World.h"

void AObjectiveToPick::BeginPlay()
{
	Super::BeginPlay();
	OnActorBeginOverlap.AddDynamic(this, &AObjectiveToPick::OnOverlap);
}


void AObjectiveToPick::OnOverlap(AActor* me, AActor* other)
{
	APlayerBase* pb = Cast<APlayerBase>(other);
	if (pb != nullptr)
	{
		AGameModeBase* gameModeBase = GetWorld()->GetAuthGameMode();
		APracticasCppGameModeBase* gameMode = Cast<APracticasCppGameModeBase>(gameModeBase);
		if (gameMode != nullptr)
		{
			gameMode->pickedObjectives++;
			Destroy();
		}
	}
}