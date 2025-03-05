#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MessageViewWidget.generated.h"

/**
 * 
 */
UCLASS()
class THIRDPERSONGAME_API UMessageViewWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category = "MessageView")
	void SetMessage(const FString& Message);
	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category = "MessageView")
	void ClearMessage();
};
