#include "ThirdPersonPlayerController.h"
#include "UserPanelViewWidget.h"
#include "InventoryViewWidget.h"
#include "MessageViewWidget.h"
#include <Kismet/GameplayStatics.h>

AThirdPersonPlayerController::AThirdPersonPlayerController()
{
}

void AThirdPersonPlayerController::BeginPlay()
{
	Super::BeginPlay();
	MainPanel = CreateWidget<UUserPanelViewWidget>(this, PanelViewClass);

	if (MainPanel)
	{
		MainPanel->AddToViewport();
		InventoryView = MainPanel->GetInventoryView();
		MessageView = MainPanel->GetMessageView();
		InventoryView->SetVisibility(ESlateVisibility::Hidden);
		MessageView->SetVisibility(ESlateVisibility::Hidden);
	}
}

void AThirdPersonPlayerController::SetPlayerEnabledState(bool bPlayerEnabled)
{
	if (bPlayerEnabled)
	{
		GetPawn()->EnableInput(this);
	}
	else
	{
		GetPawn()->DisableInput(this);
	}
	bShowMouseCursor = bPlayerEnabled;
}

void AThirdPersonPlayerController::SetInventoryVisibility()
{
	InventoryView->SetVisibility(InventoryView->GetVisibility() == ESlateVisibility::Hidden ? ESlateVisibility::Visible : ESlateVisibility::Hidden);
}

void AThirdPersonPlayerController::UpdateInventory(TMap<FCollectableItem, uint8> Items)
{
	InventoryView->ClearInventory();
	InventoryView->AddItemsInInventory(Items);
}

void AThirdPersonPlayerController::ShowMessage(FString Message)
{
	MessageView->SetVisibility(ESlateVisibility::Visible);
	MessageView->SetMessage(Message);
	GetWorld()->GetTimerManager().SetTimer(MessageViewTimerHandle, this, &AThirdPersonPlayerController::CloseMessage, 3.0f, false);
}

void AThirdPersonPlayerController::CloseMessage()
{
	MessageView->ClearMessage();
	MessageView->SetVisibility(ESlateVisibility::Hidden);
}

void AThirdPersonPlayerController::RestartGame()
{
	SetPlayerEnabledState(true);
	UGameplayStatics::OpenLevel(this, "FirstLevel");
}

void AThirdPersonPlayerController::GameHasEnded(AActor* EndGameFocus, bool bIsWinner)
{
	Super::GameHasEnded(EndGameFocus, bIsWinner);

	MainPanel->RemoveFromViewport();
	UUserWidget* GameOverPanel = CreateWidget(this, GameOverViewClass);

	if (GameOverPanel)
	{
		GameOverPanel->AddToViewport();
	}

	SetPlayerEnabledState(false);
	GetWorldTimerManager().SetTimer(RestartTimer, this, &AThirdPersonPlayerController::RestartGame, RestartDelay);
}
