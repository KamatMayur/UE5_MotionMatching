// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once
#include "Engine/DataAsset.h"
#include "CoreMinimal.h"
#include "MotionMatching.generated.h"


UCLASS()
class MOTIONMATCHING_API UMotionSchema : public UDataAsset
{
	GENERATED_BODY()

public:
	// The skeleton whose animations and bones will be used in motion matching 
	UPROPERTY(EditAnywhere, Category = "Motion Schema")
		USkeleton* Skeleton;
	
	// The bones to be used in motion matching
	UPROPERTY(EditAnywhere, Category = "Motion Schema", meta = (GetOptions = "GetBoneOptions"))
		TArray<FName> Bones;

	// Just creates a drop-down of all bones that the Skeleton has
	UFUNCTION(CallInEditor)
		TArray<FName> GetBoneOptions() const;

	UPROPERTY(EditAnywhere, Category = "Motion Schema", meta = (ClampMin = "1", ClampMax = "60"))
		float SampleRate = 10.f;

	UPROPERTY(EditAnywhere, Category = "Motion Schema")
		bool bUseBoneVelocities;

	UPROPERTY(EditAnywhere, Category = "Motion Schema")
		bool bUseTrajectoryVelocities;

	UPROPERTY(EditAnywhere, Category = "Motion Schema")
		bool bUseTrajectoryPositions;

	UPROPERTY(EditAnywhere, Category = "Motion Schema")
		TArray<float> PoseSampleTimes;

	UPROPERTY(EditAnywhere, Category = "Motion Schema")
		TArray<float> TrajectorySampleTimes;

};