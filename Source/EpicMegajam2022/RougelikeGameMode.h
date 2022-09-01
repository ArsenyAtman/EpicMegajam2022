#pragma once
#include "EpicMegajam2022GameModeBase.h"
#include "GameplayTagContainer.h"
#include "RougelikeGameMode.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnUpdateEnemiesCount, int32, EnemiesCount);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnSpawnEnemy);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnSpawnUnderwaterEnemy);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnSpawnWeatherEnemy);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnRespawnPlayer, APawn*, Player);

UCLASS()
class EPICMEGAJAM2022_API ARougelikeGameMode : public AEpicMegajam2022GameModeBase
{
	GENERATED_BODY()
 
public:
 
	UPROPERTY(EditAnywhere)
	int32 MinEnemiesCount = 5;

	UPROPERTY(EditAnywhere)
	int32 MaxEnemiesCount = 10;

	UPROPERTY(EditAnywhere)
	int32 MinUnderwaterEnemiesCount = 5;

	UPROPERTY(EditAnywhere)
	int32 MaxUnderwaterEnemiesCount = 10;

	UPROPERTY(EditAnywhere)
	int32 MinWeatherEnemiesCount = 5;

	UPROPERTY(EditAnywhere)
	int32 MaxWeatherEnemiesCount = 10;
	
	UPROPERTY(EditAnywhere)
	TArray<APawn*> EnemiesTypes;
	
	UPROPERTY(EditAnywhere)
	TArray<APawn*> UnderwaterEnemiesTypes;

	UPROPERTY(EditAnywhere)
	TArray<APawn*> WeatherEnemiesTypes;

	UFUNCTION(BlueprintCallable)
	void InitializeMap();

	UFUNCTION(BlueprintCallable)
	void UpdateEnemiesStat();

	UFUNCTION(BlueprintCallable)
	int32 GetEnemiesCount() const { return TotalEnemiesCount; }

protected:
    UPROPERTY(BlueprintAssignable)
    FOnUpdateEnemiesCount OnUpdateEnemiesCount;
	
	UPROPERTY(BlueprintAssignable)
	FOnSpawnEnemy OnSpawnEnemy;

	UPROPERTY(BlueprintAssignable)
	FOnSpawnUnderwaterEnemy FOnSpawnUnderwaterEnemy;
	
	UPROPERTY(BlueprintAssignable)
	FOnSpawnWeatherEnemy FOnSpawnWeatherEnemy;

	UPROPERTY(BlueprintAssignable)
	FOnRespawnPlayer FOnRespawnPlayer;

private:
	int32 DifficultyLevel = 0;
	int32 TotalEnemiesCount;
	int32 SurfaceEnemiesCount;
	int32 UnderwaterEnemiesCount;

	void CreateEnemies();
	void FinishLevel();
};
