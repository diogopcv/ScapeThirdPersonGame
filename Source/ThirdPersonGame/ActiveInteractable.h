#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "ActiveInteractable.generated.h"

UINTERFACE(MinimalAPI)
class UActiveInteractable : public UInterface
{
	GENERATED_BODY()
};

class THIRDPERSONGAME_API IActiveInteractable
{
	GENERATED_BODY()

public:
	virtual bool ExecuteActiveInteraction(TMap<FName, uint8> const& PlayerItensMap, OUT TMap<FName, uint8>& RequiredItensMap) = 0;
};
