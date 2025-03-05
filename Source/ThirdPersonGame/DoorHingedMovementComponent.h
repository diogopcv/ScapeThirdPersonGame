#pragma once

#include "CoreMinimal.h"
#include "DoorBaseMovementComponent.h"
#include "DoorHingedMovementComponent.generated.h"

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class THIRDPERSONGAME_API UDoorHingedMovementComponent : public UDoorBaseMovementComponent
{
	GENERATED_BODY()

public:
	UDoorHingedMovementComponent();
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	virtual void MoveDoor(bool bOpen) override;

protected:
	virtual void BeginPlay() override;

private:
	UPROPERTY(EditAnywhere)
	FRotator DeltaRotation{ 0.0, 90.0, 0.0 };
	UPROPERTY(EditAnywhere)
	float SpeedRotation = 50.f;
	FRotator OriginalRotation;
	FRotator TargetRotation;
	FRotator TempTargetRotation;
	USceneComponent* TargetSceneComponent;
};
