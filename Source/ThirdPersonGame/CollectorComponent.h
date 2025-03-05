#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "CollectibleItem.h"
#include "CoreStructs.h"
#include "CollectorComponent.generated.h"

typedef TMap<FCollectableItem, uint8> FItemMap;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class THIRDPERSONGAME_API UCollectorComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UCollectorComponent();
	TMap<FName, uint8> GetInventory() const;
	void RemoveItensFromInventory(TMap<FName, uint8> RemoveItens);

	DECLARE_MULTICAST_DELEGATE_OneParam(FItemsChangedDelegate, FItemMap)
	FItemsChangedDelegate OnItemsChanged;

protected:
	virtual void BeginPlay() override;

private:
	const class UDataTable* DataTable = nullptr;

	UFUNCTION()
	void BeginOverlapCollectible(UPrimitiveComponent* OverlappedComponent,
		AActor* OtherActor,
		UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex,
		bool bFromSweep,
		const FHitResult& SweepResult);
	void AddItemInInventory(FName ItemType);
	TMap<FCollectableItem, uint8> Inventory;
};
