#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "PlayerBase.generated.h"

UCLASS()
class PRACTICASCPP_API APlayerBase : public APawn
{
	GENERATED_BODY()

protected:
	void BeginPlay() override;

public:
	UPROPERTY(VisibleAnywhere)
	class ACheckpoint* currentCheckpoint;

	UPROPERTY(EditAnywhere)
	FVector initialPosition;

	UPROPERTY(EditAnywhere)
	FRotator initialRotation;

	UPROPERTY(EditAnywhere)
	float initialLife;

	UPROPERTY(EditAnywhere)
	int keys;

	UPROPERTY(EditAnywhere)
	int respawns;

	UPROPERTY(EditAnywhere)
	float life;

	UPROPERTY(EditAnywhere)
	float velocity;

	UPROPERTY(EditAnywhere)
	float rotationVelocity;

	APlayerBase();
	void SetupPlayerInputComponent(class UInputComponent* inputComponent) override;
	void ForwardAxis(float axis);
	void SideAxis(float axis);
	void Tick(float deltaTime) override;
};