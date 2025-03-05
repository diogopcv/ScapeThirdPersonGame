// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "ThirdPersonGameGameMode.generated.h"

UCLASS(minimalapi)
class AThirdPersonGameGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	AThirdPersonGameGameMode();
	const UDataTable* GetItemDataTable();
	void EndGame(APawn* Pawn);

private:
	UDataTable* ItemDataTable;
};



