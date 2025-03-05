#include "Door.h"
#include "DoorBaseMovementComponent.h"
#include "Components/BoxComponent.h"

ADoor::ADoor()
{
	USceneComponent* Root = CreateDefaultSubobject<USceneComponent>("Root");
	SetRootComponent(Root);
	DoorMesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	DoorMesh->SetupAttachment(Root);
	DoorTrigger = CreateDefaultSubobject<UBoxComponent>("Trigger");
	DoorTrigger->SetupAttachment(Root);
}

void ADoor::BeginPlay()
{
	Super::BeginPlay();
	DoorMovement = GetComponentByClass<UDoorBaseMovementComponent>();

	UStaticMesh* StaticMesh = DoorMesh->GetStaticMesh();
	FBox LocalBound = StaticMesh->GetBoundingBox();
	
	FVector BoxExtent = LocalBound.GetExtent() + TriggerSizeOffset;
	DoorTrigger->SetBoxExtent(BoxExtent);
	DoorTrigger->SetRelativeLocation(LocalBound.GetCenter());
}