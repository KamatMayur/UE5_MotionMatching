// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once
#include "Engine/DataAsset.h"
#include "CoreMinimal.h"
#include "MotionMatching.generated.h"

// This class has all the important settings for the motion matching system
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

// This class stores all the animations
UCLASS()
class MOTIONMATCHING_API UMotionDatabase : public UDataAsset
{
	GENERATED_BODY()
public:

	UPROPERTY(EditAnywhere, Category = "Motion Database")
		TArray<UAnimSequence*> Animations;

};


// This is a trajectory structure which can store values such as position, velocity and orientation
USTRUCT(BlueprintType)
struct MOTIONMATCHING_API FMotionTrajectory
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, Category = "Motion Trajectory")
		TArray<FVector> TrajectoryPoints;

	UPROPERTY(EditAnywhere, Category = "Motion Trajectory")
		TArray<FVector> TrajectoryVelocties;

	UPROPERTY(EditAnywhere, Category = "Motion Trajectory")
		TArray<FRotator> TrajectroyOrientations;

};