// Fill out your copyright notice in the Description page of Project Settings.

#include "CollectorComponent.h"
#include "ThirdPersonGameGameMode.h"

UCollectorComponent::UCollectorComponent()
{
}

void UCollectorComponent::BeginPlay()
{
	Super::BeginPlay();
	UPrimitiveComponent* RootComponent = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());
	if (RootComponent)
	{
		RootComponent->OnComponentBeginOverlap.AddDynamic(this, &UCollectorComponent::BeginOverlapCollectible);
	}

	DataTable = ((AThirdPersonGameGameMode*)GetWorld()->GetAuthGameMode())->GetItemDataTable();
}

TMap<FName, uint8> UCollectorComponent::GetInventory() const
{
	TMap<FName, uint8> mapOnlyKeys;

	for (auto& ItemPair : Inventory)
	{
		mapOnlyKeys.Add(ItemPair.Key.ItemKey, ItemPair.Value);
	}

	return mapOnlyKeys;
}

void UCollectorComponent::RemoveItensFromInventory(TMap<FName, uint8> RemoveItens)
{
	for (auto& itemPair : RemoveItens)
	{
		if (Inventory.Contains(itemPair.Key))
		{
			if (itemPair.Value >= Inventory[itemPair.Key])
			{
				Inventory.Remove(itemPair.Key);
			}
			else
			{
				Inventory[itemPair.Key] -= itemPair.Value;
			}
		}
	}

	OnItemsChanged.Broadcast(Inventory);
}

void UCollectorComponent::BeginOverlapCollectible(UPrimitiveComponent* OverlappedComponent,
	AActor* OtherActor,
	UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex,
	bool bFromSweep,
	const FHitResult& SweepResult)
{
	if (ACollectibleItem* Item = Cast<ACollectibleItem>(OtherActor))
	{
		const FName ItemType = Item->CollectItem();
		AddItemInInventory(ItemType);
	}
}

void UCollectorComponent::AddItemInInventory(FName ItemType)
{
	FTableRowCollectableItem* ItemRow = DataTable->FindRow<FTableRowCollectableItem>(ItemType, "");
	if (!ItemRow)
		return;

	FCollectableItem Item(ItemType, ItemRow);

	if (Inventory.Contains(Item))
	{
		Inventory[Item]++;
	}
	else
	{
		Inventory.Add(Item, 1);
	}

	OnItemsChanged.Broadcast(Inventory);
}
