#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Door.generated.h"

UCLASS()
class THIRDPERSONGAME_API ADoor : public AActor
{
	GENERATED_BODY()
	
public:	
	ADoor();

protected:
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere)
	class UStaticMeshComponent* DoorMesh;
	UPROPERTY(VisibleAnywhere)
	class UBoxComponent* DoorTrigger;
	UPROPERTY(EditAnywhere)
	FVector TriggerSizeOffset;
	class UDoorBaseMovementComponent* DoorMovement;
};
