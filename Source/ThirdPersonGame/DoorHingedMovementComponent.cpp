#include "DoorHingedMovementComponent.h"

UDoorHingedMovementComponent::UDoorHingedMovementComponent() : UDoorBaseMovementComponent()
{
	
}

void UDoorHingedMovementComponent::BeginPlay()
{
	Super::BeginPlay();
	TargetSceneComponent = GetOwner()->FindComponentByClass<UStaticMeshComponent>();
	OriginalRotation = TargetSceneComponent->GetRelativeRotation();
	TargetRotation = OriginalRotation + DeltaRotation;
	TempTargetRotation = OriginalRotation;
}

void UDoorHingedMovementComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	FRotator CurrentRotation = TargetSceneComponent->GetRelativeRotation();
	FRotator NewRotation = FMath::RInterpConstantTo(CurrentRotation, TempTargetRotation, DeltaTime, SpeedRotation);

	TargetSceneComponent->SetRelativeRotation(NewRotation);
}

void UDoorHingedMovementComponent::MoveDoor(bool bOpen)
{
	TempTargetRotation = bOpen ? TargetRotation : OriginalRotation;
}
