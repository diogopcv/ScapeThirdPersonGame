#include "Teleporter.h"
#include <Kismet/GameplayStatics.h>
#include "Components/BoxComponent.h"
#include "ThirdPersonGameGameMode.h"

ATeleporter::ATeleporter()
{
	USceneComponent* Root = CreateDefaultSubobject<USceneComponent>("Root");
	SetRootComponent(Root);
	TeleporterMesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	TeleporterMesh->SetupAttachment(Root);
	TeleporterTrigger = CreateDefaultSubobject<UBoxComponent>("Trigger");
	TeleporterTrigger->SetupAttachment(Root);
}

void ATeleporter::BeginPlay()
{
	Super::BeginPlay();

	UStaticMesh* StaticMesh = TeleporterMesh->GetStaticMesh();
	FBox LocalBound = StaticMesh->GetBoundingBox();

	FVector BoxExtent = LocalBound.GetExtent() + TriggerSizeOffset;
	TeleporterTrigger->SetBoxExtent(BoxExtent);
	TeleporterTrigger->SetRelativeLocation(LocalBound.GetCenter());
}

bool ATeleporter::ExecuteActiveInteraction(TMap<FName, uint8> const& PlayerItensMap, OUT TMap<FName, uint8>& RequiredItensMap)
{
	switch (TeleporterAction)
	{
	case ETeleporterAction::LEVEL1:
		UGameplayStatics::OpenLevel(this, "FirstLevel");
		break;
	case ETeleporterAction::LEVEL2:
		UGameplayStatics::OpenLevel(this, "SecondLevel");
		break;
	case ETeleporterAction::ENDGAME:
		AThirdPersonGameGameMode* GameMode = Cast<AThirdPersonGameGameMode>(GetWorld()->GetAuthGameMode());
		if (GameMode)
		{
			GameMode->EndGame(UGameplayStatics::GetPlayerController(GetWorld(), 0)->GetPawn());
		}
		break;
	}

	return true;
}