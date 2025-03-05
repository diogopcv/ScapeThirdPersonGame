#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CollectibleItem.generated.h"

UCLASS()
class THIRDPERSONGAME_API ACollectibleItem : public AActor
{
	GENERATED_BODY()

public:
	ACollectibleItem();
	FName CollectItem();

protected:
	virtual void BeginPlay() override;

private:
	UPROPERTY(EditAnywhere)
	class UStaticMeshComponent* ItemMesh;
	UPROPERTY(EditAnywhere)
	FName ItemType;
};
