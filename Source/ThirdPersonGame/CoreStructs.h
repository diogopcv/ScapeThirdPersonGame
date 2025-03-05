#pragma once

#include "CoreMinimal.h"
#include "CoreStructs.generated.h"

USTRUCT(BlueprintType)
struct FTableRowCollectableItem : public FTableRowBase
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Name;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Description;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UTexture2D* Thumbnail;

	bool operator==(const  FTableRowCollectableItem& Other) const
	{
		return Equals(Other);
	}

	bool operator!=(const  FTableRowCollectableItem& Other) const
	{
		return !Equals(Other);
	}

	bool Equals(const  FTableRowCollectableItem& Other) const
	{
		return Name == Other.Name && Description == Other.Description && Thumbnail == Other.Thumbnail;
	}
};

USTRUCT(BlueprintType)
struct FCollectableItem
{
	GENERATED_BODY()

	FName ItemKey;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Name;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Description;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UTexture2D* Thumbnail;
	
	FCollectableItem(){}

	FCollectableItem(FName Key) { ItemKey = Key; }

	FCollectableItem(FName Key, const FTableRowCollectableItem* TableRowCollectableItem)
	{
		ItemKey = Key;
		Name = TableRowCollectableItem->Name;
		Description = TableRowCollectableItem->Description;
		Thumbnail = TableRowCollectableItem->Thumbnail;
	}

	bool operator==(const  FCollectableItem& Other) const
	{
		return Equals(Other);
	}

	bool operator!=(const  FCollectableItem& Other) const
	{
		return !Equals(Other);
	}

	bool Equals(const  FCollectableItem& Other) const
	{
		return ItemKey == Other.ItemKey;
	}
};

FORCEINLINE uint32 GetTypeHash(const  FTableRowCollectableItem& This)
{
	return HashCombine(GetTypeHash(This.Name), GetTypeHash(This.Description));
}

FORCEINLINE uint32 GetTypeHash(const  FCollectableItem& This)
{
	return GetTypeHash(This.ItemKey);
}