#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Door.h"
#include "PassiveInteractable.h"
#include "AutomaticDoor.generated.h"

UCLASS()
class THIRDPERSONGAME_API AAutomaticDoor : public ADoor, public IPassiveInteractable
{
	GENERATED_BODY()

public:
	AAutomaticDoor();
	virtual void ExecutePassiveInteraction(bool bIsStarting) override;

protected:
	virtual void BeginPlay() override;
};
