#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Door.h"
#include "ActiveInteractable.h"
#include "ActiveDoor.generated.h"

UCLASS()
class THIRDPERSONGAME_API AActiveDoor : public ADoor, public IActiveInteractable
{
	GENERATED_BODY()

public:
	AActiveDoor();
	virtual bool ExecuteActiveInteraction(TMap<FName, uint8> const& PlayerItensMap, OUT TMap<FName, uint8>& RequiredItensMap) override;

protected:
	virtual void BeginPlay() override;

private:
	bool ShouldInteract(TMap<FName, uint8> const& PlayerItensMap);
	UPROPERTY(EditAnywhere)
	TMap<FName, uint8> RequiredItensIDs;
	bool bAlreadyInteracted{ false };
};
