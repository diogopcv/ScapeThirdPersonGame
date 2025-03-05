#pragma once

#include "CoreMinimal.h"
#include "DoorBaseMovementComponent.h"
#include "DoorMagicMovementComponent.generated.h"

/**
 * 
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class THIRDPERSONGAME_API UDoorMagicMovementComponent : public UDoorBaseMovementComponent
{
	GENERATED_BODY()

public:
	UDoorMagicMovementComponent();
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	virtual void MoveDoor(bool bOpen) override;

protected:
	virtual void BeginPlay() override;

private:
	UPROPERTY(EditAnywhere)
	FVector DeltaScale{ 1.0, 0.0, 0.0 };
	UPROPERTY(EditAnywhere)
	float SpeedScale = 50.f;

	FVector OriginalScale;
	FVector TargetScale;
	FVector TempTargetScale;
	USceneComponent* TargetSceneComponent;
	
};
