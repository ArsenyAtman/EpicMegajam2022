#pragma once

#include "GameplayTagContainer.h"
#include "KillableEnemy.generated.h"

UCLASS()
class AKillableEnemy : public APawn
{
	GENERATED_BODY()
public:

	UFUNCTION(BlueprintCallable)
	void SetDeathTag(FGameplayTag NewDeathTag) { DeathTag = NewDeathTag; }
	
private:
	FGameplayTag DeathTag;
	
};
