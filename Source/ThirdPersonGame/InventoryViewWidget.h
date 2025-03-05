#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "CoreStructs.h"
#include "InventoryViewWidget.generated.h"

/**
 * 
 */
UCLASS()
class THIRDPERSONGAME_API UInventoryViewWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category = "InventoryView")
	void AddItemsInInventory(const TMap<FCollectableItem, uint8>& ItensMap);

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category = "InventoryView")
	void ClearInventory();
	
};
