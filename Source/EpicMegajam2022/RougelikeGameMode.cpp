#include "RougelikeGameMode.h"

void ARougelikeGameMode::InitializeMap()
{
	DifficultyLevel++;
	// if (DifficultyLevel > LevelCyclesCount)
	// {
	// 	return;
	// }
	CreateEnemies();
}

void ARougelikeGameMode::CreateEnemies()
{
	int32 WeatherEnemiesCount = FMath::RandRange(MinWeatherEnemiesCount * DifficultyLevel, MaxWeatherEnemiesCount * DifficultyLevel);
	// SurfaceEnemiesCount = FMath::RandRange(MinEnemiesCount * DifficultyLevel, MaxEnemiesCount * DifficultyLevel);
	// UnderwaterEnemiesCount = FMath::RandRange(MinUnderwaterEnemiesCount * DifficultyLevel, MaxUnderwaterEnemiesCount * DifficultyLevel);
	// TotalEnemiesCount = SurfaceEnemiesCount + UnderwaterEnemiesCount;
	// for (int32 i=0; i<SurfaceEnemiesCount; i++)
	// {
	// 	OnSpawnEnemy.Broadcast();
	// }
	// for (int32 i=0; i<UnderwaterEnemiesCount; i++)
	// {
	// 	FOnSpawnUnderwaterEnemy.Broadcast();
	// }
	for (int32 i=0; i<WeatherEnemiesCount; i++)
	{
		FOnSpawnWeatherEnemy.Broadcast();
	}
}

void ARougelikeGameMode::UpdateEnemiesStat()
{
	TotalEnemiesCount--;
	OnUpdateEnemiesCount.Broadcast(TotalEnemiesCount);
	if (TotalEnemiesCount == 0)
	{
		//TODO end the game or spawn Boss
		FinishLevel();
	}
	//TODO event on UI
}

void ARougelikeGameMode::FinishLevel()
{
	UE_LOG(LogTemp, Error, TEXT("FINISHED LEVEL"));
}
