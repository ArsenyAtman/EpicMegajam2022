#include "RougelikeGameMode.h"
#include "GameplayTags.h"

ARougelikeGameMode::ARougelikeGameMode()
{
	EnemiesAlive = TArray<FGameplayTag>();
	EnemiesKilled = TArray<FGameplayTag>();
}

void ARougelikeGameMode::InitializeMap()
{
	DifficultyLevel++;
	if (DifficultyLevel > LevelCyclesCount)
	{
		return;
	}
	CreateEnemies();
}

void ARougelikeGameMode::CreateEnemies()
{
	EnemiesAlive.Reset();
	EnemiesKilled.Reset();
	EnemiesCount = FMath::RandRange(MinEnemiesCount * DifficultyLevel, MaxEnemiesCount * DifficultyLevel);
	if (EnemiesCount > MaxPossibleEnemiesCount)
	{
		EnemiesCount = MaxPossibleEnemiesCount;
	}
	for (int32 i=0; i<EnemiesCount; i++)
	{
		FString TagName = "Enemy_" + FString::FromInt(i);
		FGameplayTag EnemyTag = FGameplayTag::RequestGameplayTag(FName(*TagName));
		EnemiesAlive.Add(EnemyTag);
		OnSpawnEnemy.Broadcast(EnemyTag);
		UE_LOG(LogTemp, Error, TEXT("Spawn enemy c++"));
	}
}

void ARougelikeGameMode::UpdateEnemiesStat(FGameplayTag KilledEnemy)
{
	if (EnemiesAlive.Contains(KilledEnemy))
	{
		EnemiesAlive.Remove(KilledEnemy);
		EnemiesKilled.Add(KilledEnemy);
		EnemiesCount--;
		OnUpdateEnemiesCount.Broadcast(EnemiesCount);
		UE_LOG(LogTemp, Error, TEXT("Enemies Alive: %s"), *FString::FromInt(EnemiesAlive.Num()));
		UE_LOG(LogTemp, Error, TEXT("Enemies Killed: %s"), *FString::FromInt(EnemiesKilled.Num()));
		if (EnemiesAlive.IsEmpty())
		{
			//TODO end the game or spawn Boss
			FinishLevel();
		}
		//TODO event on UI
	}
}

void ARougelikeGameMode::FinishLevel()
{
	UE_LOG(LogTemp, Error, TEXT("FINISHED LEVEL"));
}
