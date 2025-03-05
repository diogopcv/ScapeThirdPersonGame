#pragma once

#include "CoreMinimal.h"
#include "DoorBaseMovementComponent.h"
#include "DoorSlidingMovementComponent.generated.h"

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class THIRDPERSONGAME_API UDoorSlidingMovementComponent : public UDoorBaseMovementComponent
{
	GENERATED_BODY()

public:
	UDoorSlidingMovementComponent();
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	virtual void MoveDoor(bool bOpen) override;

protected:
	virtual void BeginPlay() override;

private:
	UPROPERTY(EditAnywhere)
	FVector Displacement { 0.0, 0.0, 0.0 };
	UPROPERTY(EditAnywhere)
	float SpeedDisplacement = 50.f;
	FVector OriginalPosition;
	FVector TargetPosition;
	FVector TempTargetPosition;
	USceneComponent* TargetSceneComponent;
};
