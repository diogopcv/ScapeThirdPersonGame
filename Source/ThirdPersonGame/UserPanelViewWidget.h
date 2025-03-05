#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "InventoryViewWidget.h"
#include "MessageViewWidget.h"
#include "UserPanelViewWidget.generated.h"

/**
 * 
 */
UCLASS()
class THIRDPERSONGAME_API UUserPanelViewWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category = "UserPanelView")
	UInventoryViewWidget* GetInventoryView();
	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category = "UserPanelView")
	UMessageViewWidget* GetMessageView();
};
