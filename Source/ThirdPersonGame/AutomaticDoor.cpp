#include "AutomaticDoor.h"
#include "DoorBaseMovementComponent.h"
#include "Components/BoxComponent.h"

AAutomaticDoor::AAutomaticDoor() : ADoor()
{

}

void AAutomaticDoor::BeginPlay()
{
	Super::BeginPlay();
}

void AAutomaticDoor::ExecutePassiveInteraction(bool bIsStarting)
{
	if (DoorMovement)
	{
		DoorMovement->MoveDoor(bIsStarting);
	}
}
