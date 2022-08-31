#pragma once
#include "EpicMegajam2022GameModeBase.h"
#include "GameplayTagContainer.h"
#include "KillableEnemy.h"
#include "RougelikeGameMode.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnUpdateEnemiesCount, int32, EnemiesCount);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnSpawnEnemy, FGameplayTag, EnemyDeathTag);

UCLASS()
class EPICMEGAJAM2022_API ARougelikeGameMode : public AEpicMegajam2022GameModeBase
{
	GENERATED_BODY()
 
public:
	ARougelikeGameMode();
 
	UPROPERTY(EditAnywhere)
	int32 LevelCyclesCount = 3;
 
	UPROPERTY(EditAnywhere)
	int32 MinEnemiesCount = 5;

	UPROPERTY(EditAnywhere)
	int32 MaxEnemiesCount = 10;
 
	UPROPERTY(EditAnywhere)
	int32 MaxPossibleEnemiesCount = 50;

	//TODO change on BaseEnemy type
	UPROPERTY()
	TArray<AKillableEnemy*> EnemiesTypes;

	//TODO change on BaseLoot type
	UPROPERTY()
	TArray<AActor*> LootTypes;

	UFUNCTION(BlueprintCallable)
	void InitializeMap();

	UFUNCTION(BlueprintCallable)
	void UpdateEnemiesStat(FGameplayTag KilledEnemy);

	UFUNCTION(BlueprintCallable)
	int32 GetEnemiesCount() const { return EnemiesCount; }

	UFUNCTION(BlueprintCallable)
	TArray<FGameplayTag> GetEnemiesAlive() { return EnemiesAlive; }

protected:
    UPROPERTY(BlueprintAssignable)
    FOnUpdateEnemiesCount OnUpdateEnemiesCount;
	
	UPROPERTY(BlueprintAssignable)
	FOnSpawnEnemy OnSpawnEnemy;

private:
	int32 DifficultyLevel = 0;
	int32 EnemiesCount;
	UPROPERTY()
	TArray<FGameplayTag> EnemiesAlive;
	UPROPERTY()
	TArray<FGameplayTag> EnemiesKilled;

	void CreateEnemies();
	void FinishLevel();
};
