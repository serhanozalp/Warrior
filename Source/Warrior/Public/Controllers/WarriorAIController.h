// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Perception/AIPerceptionTypes.h"
#include "Runtime/AIModule/Classes/AIController.h"
#include "WarriorAIController.generated.h"

class UAISenseConfig_Sight;

UCLASS()
class WARRIOR_API AWarriorAIController : public AAIController
{
	GENERATED_BODY()

public:
	
	AWarriorAIController(const FObjectInitializer& ObjectInitializer);

protected:

	//PROPERTY
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UAIPerceptionComponent* EnemyPerceptionComponent;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UAISenseConfig_Sight* AISenseConfig_Sight;

	//METHOD

	virtual void BeginPlay() override;
	
	UFUNCTION()
	virtual void OnEnemyPerceptionUpdated(AActor* Actor, FAIStimulus Stimulus);

public:
	
	virtual ETeamAttitude::Type GetTeamAttitudeTowards(const AActor& Other) const override;

private:

	UPROPERTY(EditDefaultsOnly, Category = "Detour Crowd Avoidance Config")
	bool bEnableDetourCrowdAvoidance = true;
	
	UPROPERTY(EditDefaultsOnly, Category = "Detour Crowd Avoidance Config", meta= (EditCondition = "bEnableDetourCrowdAvoidance", UIMin = "1", UIMax = "4"))
	int32 DetourCrowdAvoidanceQuality = 4;
	
	UPROPERTY(EditDefaultsOnly, Category = "Detour Crowd Avoidance Config", meta= (EditCondition = "bEnableDetourCrowdAvoidance"))
	float CollisionQueryRange = 600.0f;
	
};
