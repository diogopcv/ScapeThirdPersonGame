#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "PassiveInteractable.generated.h"

UINTERFACE(MinimalAPI)
class UPassiveInteractable : public UInterface
{
	GENERATED_BODY()
};

class THIRDPERSONGAME_API IPassiveInteractable
{
	GENERATED_BODY()

public:
	virtual void ExecutePassiveInteraction(bool bIsStarting) = 0;
};
