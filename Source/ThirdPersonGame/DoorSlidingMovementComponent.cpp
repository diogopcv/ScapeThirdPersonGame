#include "DoorSlidingMovementComponent.h"

UDoorSlidingMovementComponent::UDoorSlidingMovementComponent()
{
}

void UDoorSlidingMovementComponent::BeginPlay()
{
	Super::BeginPlay();
	TargetSceneComponent = GetOwner()->FindComponentByClass<UStaticMeshComponent>();
	OriginalPosition = GetOwner()->GetActorLocation();
	OriginalPosition = TargetSceneComponent->GetRelativeLocation();
	TargetPosition = OriginalPosition + Displacement;
	TempTargetPosition = OriginalPosition;
}

void UDoorSlidingMovementComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	FVector CurrentPosition = TargetSceneComponent->GetRelativeLocation();
	FVector NewPosition = FMath::VInterpConstantTo(CurrentPosition, TempTargetPosition, DeltaTime, SpeedDisplacement);

	TargetSceneComponent->SetRelativeLocation(NewPosition);
}

void UDoorSlidingMovementComponent::MoveDoor(bool bOpen)
{
	TempTargetPosition = bOpen ? TargetPosition: OriginalPosition;
}
