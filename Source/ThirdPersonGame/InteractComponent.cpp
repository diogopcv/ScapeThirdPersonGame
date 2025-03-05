#include "InteractComponent.h"
#include "ThirdPersonGameGameMode.h"
#include "ActiveInteractable.h"
#include "PassiveInteractable.h"
#include "CoreStructs.h"

UInteractComponent::UInteractComponent()
{

}


void UInteractComponent::BeginPlay()
{
	Super::BeginPlay();
	UPrimitiveComponent* RootComponent = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());
	if (RootComponent)
	{
		RootComponent->OnComponentBeginOverlap.AddDynamic(this, &UInteractComponent::BeginOverlapInteractable);
		RootComponent->OnComponentEndOverlap.AddDynamic(this, &UInteractComponent::EndOverlapInteractable);
	}

	DataTable = ((AThirdPersonGameGameMode*)GetWorld()->GetAuthGameMode())->GetItemDataTable();
}

void UInteractComponent::BeginOverlapInteractable(
	UPrimitiveComponent* OverlappedComponent,
	AActor* OtherActor,
	UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex,
	bool bFromSweep,
	const FHitResult& SweepResult)
{
	if (IPassiveInteractable* PassiveInteractable = Cast<IPassiveInteractable>(OtherActor))
	{	
		PassiveInteractable->ExecutePassiveInteraction(true);
	}
	else if (IActiveInteractable* ActiveInteractable = Cast<IActiveInteractable>(OtherActor))
	{
		ActiveInteractableOverlapped = ActiveInteractable;
	}
}

void UInteractComponent::EndOverlapInteractable(
	UPrimitiveComponent* OverlappedComponent,
	AActor* OtherActor,
	UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex)
{
	if (IPassiveInteractable* PassiveInteractable = Cast<IPassiveInteractable>(OtherActor))
	{
		PassiveInteractable->ExecutePassiveInteraction(false);
	}
	else if (ActiveInteractableOverlapped == Cast<IActiveInteractable>(OtherActor))
	{
		ActiveInteractableOverlapped = nullptr;
	}
}

bool UInteractComponent::Interact(TMap<FName, uint8> const& Inventory, OUT TMap<FName, uint8>& RequiredItensMap)
{
	bool bSuccess = false;
	if (ActiveInteractableOverlapped)
	{
		FString Message;
		bSuccess = ActiveInteractableOverlapped->ExecuteActiveInteraction(Inventory, RequiredItensMap);
		if (!bSuccess)
		{
			Message = FString(TEXT("You need to collect: \n\n"));
			for (auto& pair : RequiredItensMap)
			{
				FTableRowCollectableItem* ItemDetail = DataTable->FindRow<FTableRowCollectableItem>(pair.Key, "");
				Message += FString::Printf(TEXT("%d x %s \n"), pair.Value, *ItemDetail->Name);
			}

			OnInteractionFailedMessage.ExecuteIfBound(Message);
		}
	}
	return bSuccess;
}
