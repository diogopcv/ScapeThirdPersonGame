#include "ActiveDoor.h"
#include "DoorBaseMovementComponent.h"
#include "Components/BoxComponent.h"

AActiveDoor::AActiveDoor() : ADoor()
{

}

void AActiveDoor::BeginPlay()
{
	Super::BeginPlay();
}

bool AActiveDoor::ExecuteActiveInteraction(TMap<FName, uint8> const& PlayerItensMap, OUT TMap<FName, uint8>& RequiredItensMap)
{
	if (bAlreadyInteracted)
		return true;

	RequiredItensMap = RequiredItensIDs;
	bool bCheck = ShouldInteract(PlayerItensMap);

	if (!bCheck)
	{
		return false;
	}

	if (DoorMovement)
	{
		bAlreadyInteracted = true;
		DoorMovement->MoveDoor(true);
		return true;
	}

	return false;
}

bool AActiveDoor::ShouldInteract(TMap<FName, uint8> const& PlayerItensMap)
{
	if (RequiredItensIDs.IsEmpty())
		return true;

	for (auto& ItemPair : RequiredItensIDs)
	{
		if (!(PlayerItensMap.Contains(ItemPair.Key) && PlayerItensMap[ItemPair.Key] >= ItemPair.Value))
			return false;
	}

	return true;
}
