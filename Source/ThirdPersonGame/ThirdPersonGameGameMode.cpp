// Copyright Epic Games, Inc. All Rights Reserved.

#include "ThirdPersonGameGameMode.h"
#include "ThirdPersonGameCharacter.h"
#include "UObject/ConstructorHelpers.h"
#include "ThirdPersonPlayerController.h"

AThirdPersonGameGameMode::AThirdPersonGameGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APlayerController> PlayerControllerBPClass(TEXT("/Game/ThirdPerson/Blueprints/Player/BP_ThirdPersonPlayerController"));
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/Player/BP_ThirdPersonCharacter"));
	static ConstructorHelpers::FObjectFinder<UDataTable> ItemTableObject(TEXT("/Game/ThirdPerson/Data/DT_ItensTable"));

	if (PlayerControllerBPClass.Class != NULL)
	{
		PlayerControllerClass = PlayerControllerBPClass.Class;
	}

	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}

	if (ItemTableObject.Object != NULL)
	{
		ItemDataTable = ItemTableObject.Object;
	}
}

const UDataTable* AThirdPersonGameGameMode::GetItemDataTable()
{
	return ItemDataTable;
}

void AThirdPersonGameGameMode::EndGame(APawn* Pawn)
{
	Pawn->GetController()->GameHasEnded(Pawn, true);
}
