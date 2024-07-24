// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "DeathWorld/Game_PlayerState.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeGame_PlayerState() {}
// Cross Module References
	DEATHWORLD_API UClass* Z_Construct_UClass_AGame_PlayerState();
	DEATHWORLD_API UClass* Z_Construct_UClass_AGame_PlayerState_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_APlayerState();
	UPackage* Z_Construct_UPackage__Script_DeathWorld();
// End Cross Module References
	void AGame_PlayerState::StaticRegisterNativesAGame_PlayerState()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AGame_PlayerState);
	UClass* Z_Construct_UClass_AGame_PlayerState_NoRegister()
	{
		return AGame_PlayerState::StaticClass();
	}
	struct Z_Construct_UClass_AGame_PlayerState_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AGame_PlayerState_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_APlayerState,
		(UObject* (*)())Z_Construct_UPackage__Script_DeathWorld,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AGame_PlayerState_Statics::DependentSingletons) < 16);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AGame_PlayerState_Statics::Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "HideCategories", "Input Movement Collision Rendering HLOD WorldPartition DataLayers Transformation" },
		{ "IncludePath", "Game_PlayerState.h" },
		{ "ModuleRelativePath", "Game_PlayerState.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_AGame_PlayerState_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AGame_PlayerState>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_AGame_PlayerState_Statics::ClassParams = {
		&AGame_PlayerState::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x009002A4u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AGame_PlayerState_Statics::Class_MetaDataParams), Z_Construct_UClass_AGame_PlayerState_Statics::Class_MetaDataParams)
	};
	UClass* Z_Construct_UClass_AGame_PlayerState()
	{
		if (!Z_Registration_Info_UClass_AGame_PlayerState.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AGame_PlayerState.OuterSingleton, Z_Construct_UClass_AGame_PlayerState_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_AGame_PlayerState.OuterSingleton;
	}
	template<> DEATHWORLD_API UClass* StaticClass<AGame_PlayerState>()
	{
		return AGame_PlayerState::StaticClass();
	}
	AGame_PlayerState::AGame_PlayerState(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
	DEFINE_VTABLE_PTR_HELPER_CTOR(AGame_PlayerState);
	AGame_PlayerState::~AGame_PlayerState() {}
	struct Z_CompiledInDeferFile_FID_Users_User_Documents_Unreal_Projects_DeathWorld_Source_DeathWorld_Game_PlayerState_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_User_Documents_Unreal_Projects_DeathWorld_Source_DeathWorld_Game_PlayerState_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_AGame_PlayerState, AGame_PlayerState::StaticClass, TEXT("AGame_PlayerState"), &Z_Registration_Info_UClass_AGame_PlayerState, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AGame_PlayerState), 2914827459U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_User_Documents_Unreal_Projects_DeathWorld_Source_DeathWorld_Game_PlayerState_h_2981320100(TEXT("/Script/DeathWorld"),
		Z_CompiledInDeferFile_FID_Users_User_Documents_Unreal_Projects_DeathWorld_Source_DeathWorld_Game_PlayerState_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_User_Documents_Unreal_Projects_DeathWorld_Source_DeathWorld_Game_PlayerState_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
