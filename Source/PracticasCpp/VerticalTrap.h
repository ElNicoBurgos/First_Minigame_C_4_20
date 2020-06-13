#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "VerticalTrap.generated.h"

UCLASS()
class PRACTICASCPP_API AVerticalTrap : public AActor
{
	GENERATED_BODY()

protected:
	FTimerHandle timerHandle;
	void BeginPlay() override;
	void ChangeDirection();

public:
	UPROPERTY(EditAnywhere)
	float damage;

	UPROPERTY(EditAnywhere)
	float velocity;

	UPROPERTY(EditAnywhere)
	float changeTime;

	AVerticalTrap();

	void Tick(float DeltaTime) override;

	UFUNCTION()
	void OnOverlap(AActor* me, AActor* other);
};
