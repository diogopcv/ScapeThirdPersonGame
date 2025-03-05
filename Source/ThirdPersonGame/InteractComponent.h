#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "InteractComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class THIRDPERSONGAME_API UInteractComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UInteractComponent();
	bool Interact(TMap<FName, uint8> const& Inventory, OUT TMap<FName, uint8>& RequiredItensMap);

	DECLARE_DELEGATE_OneParam(FInteractionResultMessageDelegate, FString)
	FInteractionResultMessageDelegate OnInteractionFailedMessage;

protected:
	virtual void BeginPlay() override;

private:
	UFUNCTION()
	void BeginOverlapInteractable(UPrimitiveComponent* OverlappedComponent,
		AActor* OtherActor,
		UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex,
		bool bFromSweep,
		const FHitResult& SweepResult);

	UFUNCTION()
	void EndOverlapInteractable(UPrimitiveComponent* OverlappedComponent,
		AActor* OtherActor,
		UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex);

	class IActiveInteractable* ActiveInteractableOverlapped = nullptr;
	const class UDataTable* DataTable = nullptr;
};
