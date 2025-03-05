#include "DoorMagicMovementComponent.h"

UDoorMagicMovementComponent::UDoorMagicMovementComponent()
{
}

void UDoorMagicMovementComponent::BeginPlay()
{
	Super::BeginPlay();
	TargetSceneComponent = GetOwner()->FindComponentByClass<UStaticMeshComponent>();
	OriginalScale = TargetSceneComponent->GetRelativeScale3D();
	TargetScale = TargetScale + DeltaScale;
	TempTargetScale = OriginalScale;
}

void UDoorMagicMovementComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	FVector CurrentScale= TargetSceneComponent->GetRelativeScale3D();
	FVector NewScale = FMath::VInterpConstantTo(CurrentScale, TempTargetScale, DeltaTime, SpeedScale);

	TargetSceneComponent->SetRelativeScale3D(NewScale);
}

void UDoorMagicMovementComponent::MoveDoor(bool bOpen)
{
	TempTargetScale = bOpen ? TargetScale : OriginalScale;
}
