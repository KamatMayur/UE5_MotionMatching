// Copyright Epic Games, Inc. All Rights Reserved.

#include "MotionMatching.h"
#include "Modules/ModuleManager.h"

IMPLEMENT_PRIMARY_GAME_MODULE( FDefaultGameModuleImpl, MotionMatching, "MotionMatching" );

TArray<FName> UMotionSchema::GetBoneOptions() const
{
	

	TArray<FName> AllBones;
	if (Skeleton)
	{

		for (int32 i = 0; i < Skeleton->GetReferenceSkeleton().GetNum(); ++i)
			AllBones.Insert(Skeleton->GetReferenceSkeleton().GetBoneName(i), i);
		return AllBones;
	}

	else return TArray<FName>();
	
    
}
