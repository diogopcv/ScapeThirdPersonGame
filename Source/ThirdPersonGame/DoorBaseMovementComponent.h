#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "DoorBaseMovementComponent.generated.h"


UCLASS( ClassGroup=(Custom), abstract)
class THIRDPERSONGAME_API UDoorBaseMovementComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UDoorBaseMovementComponent();
	virtual void MoveDoor(bool bOpen);
};
