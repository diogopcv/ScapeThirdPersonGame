#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Door.h"
#include "ActiveInteractable.h"
#include "Teleporter.generated.h"

UENUM(BlueprintType)
enum class ETeleporterAction : uint8 {
	LEVEL1 = 0 UMETA(DisplayName = "LEVEL 1"),
	LEVEL2 = 1  UMETA(DisplayName = "LEVEL 2"),
	ENDGAME = 2     UMETA(DisplayName = "END GAME"),
};

UCLASS()
class THIRDPERSONGAME_API ATeleporter : public AActor, public IActiveInteractable
{
	GENERATED_BODY()
	
public:	
	ATeleporter();
	virtual bool ExecuteActiveInteraction(TMap<FName, uint8> const& PlayerItensMap, OUT TMap<FName, uint8>& RequiredItensMap) override;

protected:
	virtual void BeginPlay() override;

private:
	UPROPERTY(EditAnywhere)
	class UStaticMeshComponent* TeleporterMesh;
	UPROPERTY(VisibleAnywhere)
	class UBoxComponent* TeleporterTrigger;
	UPROPERTY(EditAnywhere)
	FVector TriggerSizeOffset;
	UPROPERTY(EditAnywhere)
	ETeleporterAction TeleporterAction;
};
