// Fill out your copyright notice in the Description page of Project Settings.


#include "CollectibleItem.h"
#include "Components/BoxComponent.h"


ACollectibleItem::ACollectibleItem()
{
	ItemMesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	SetRootComponent(ItemMesh);

	if (ItemMesh)
	{
		ItemMesh->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Overlap);
	}
}

void ACollectibleItem::BeginPlay()
{
	Super::BeginPlay();
}

FName ACollectibleItem::CollectItem()
{
	Destroy();
	return ItemType;
}
