// Copyright Epic Games, Inc. All Rights Reserved.

#include "MotionSynthesis.h"

#define LOCTEXT_NAMESPACE "FMotionSynthesisModule"

void FMotionSynthesisModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
}

void FMotionSynthesisModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FMotionSynthesisModule, MotionSynthesis)

TArray<FName> UMotionSchema::GetBoneOptions() const
{
	TArray<FName> BoneList;
	if (Skeleton)
	{
		for (int i = 0; i < Skeleton->GetReferenceSkeleton().GetNum(); i++)
		{
			BoneList.Insert(Skeleton->GetReferenceSkeleton().GetBoneName(i), i);
		}
		return BoneList;
	}
	else return TArray<FName>();
}
