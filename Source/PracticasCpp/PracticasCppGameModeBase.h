#pragma once
#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "PracticasCppGameModeBase.generated.h"

UCLASS()
class PRACTICASCPP_API APracticasCppGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

public:
	APracticasCppGameModeBase();

	UPROPERTY(VisibleAnywhere)
	int pickedObjectives;

	UPROPERTY(EditAnywhere)
	int objectivesToPick;

	void Tick(float deltaSeconds) override;
};