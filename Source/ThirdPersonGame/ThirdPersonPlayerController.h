#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "CoreStructs.h"
#include "ThirdPersonPlayerController.generated.h"


UCLASS()
class THIRDPERSONGAME_API AThirdPersonPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	AThirdPersonPlayerController();
	virtual void GameHasEnded(class AActor* EndGameFocus = nullptr, bool bIsWinner = false) override;
	void SetInventoryVisibility();
	void UpdateInventory(TMap<FCollectableItem, uint8> Items);
	void ShowMessage(FString Message);
	void CloseMessage();
	void RestartGame();
	
protected:
	virtual void BeginPlay() override;

private:
	void SetPlayerEnabledState(bool bPlayerEnabled);

	UPROPERTY(EditAnywhere)
	TSubclassOf<class UUserPanelViewWidget> PanelViewClass;
	UPROPERTY(EditAnywhere)
	TSubclassOf<class UUserWidget> GameOverViewClass;
	UPROPERTY()
	class UUserPanelViewWidget* MainPanel;
	UPROPERTY()
	class UInventoryViewWidget* InventoryView;
	UPROPERTY()
	class UMessageViewWidget* MessageView;
	FTimerHandle MessageViewTimerHandle;
	FTimerHandle RestartTimer;
	float RestartDelay = 5.f;
};
