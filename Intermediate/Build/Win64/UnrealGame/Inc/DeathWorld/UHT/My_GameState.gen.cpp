// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "DeathWorld/My_GameState.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeMy_GameState() {}
// Cross Module References
	DEATHWORLD_API UClass* Z_Construct_UClass_AMy_GameState();
	DEATHWORLD_API UClass* Z_Construct_UClass_AMy_GameState_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_AGameState();
	UPackage* Z_Construct_UPackage__Script_DeathWorld();
// End Cross Module References
	void AMy_GameState::StaticRegisterNativesAMy_GameState()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AMy_GameState);
	UClass* Z_Construct_UClass_AMy_GameState_NoRegister()
	{
		return AMy_GameState::StaticClass();
	}
	struct Z_Construct_UClass_AMy_GameState_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AMy_GameState_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AGameState,
		(UObject* (*)())Z_Construct_UPackage__Script_DeathWorld,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AMy_GameState_Statics::DependentSingletons) < 16);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMy_GameState_Statics::Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "HideCategories", "Input Movement Collision Rendering HLOD WorldPartition DataLayers Transformation" },
		{ "IncludePath", "My_GameState.h" },
		{ "ModuleRelativePath", "My_GameState.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_AMy_GameState_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AMy_GameState>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_AMy_GameState_Statics::ClassParams = {
		&AMy_GameState::StaticClass,
		"Game",
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
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AMy_GameState_Statics::Class_MetaDataParams), Z_Construct_UClass_AMy_GameState_Statics::Class_MetaDataParams)
	};
	UClass* Z_Construct_UClass_AMy_GameState()
	{
		if (!Z_Registration_Info_UClass_AMy_GameState.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AMy_GameState.OuterSingleton, Z_Construct_UClass_AMy_GameState_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_AMy_GameState.OuterSingleton;
	}
	template<> DEATHWORLD_API UClass* StaticClass<AMy_GameState>()
	{
		return AMy_GameState::StaticClass();
	}
	AMy_GameState::AMy_GameState(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
	DEFINE_VTABLE_PTR_HELPER_CTOR(AMy_GameState);
	AMy_GameState::~AMy_GameState() {}
	struct Z_CompiledInDeferFile_FID_Users_User_Documents_Unreal_Projects_DeathWorld_Source_DeathWorld_My_GameState_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_User_Documents_Unreal_Projects_DeathWorld_Source_DeathWorld_My_GameState_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_AMy_GameState, AMy_GameState::StaticClass, TEXT("AMy_GameState"), &Z_Registration_Info_UClass_AMy_GameState, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AMy_GameState), 1515798334U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_User_Documents_Unreal_Projects_DeathWorld_Source_DeathWorld_My_GameState_h_2906969879(TEXT("/Script/DeathWorld"),
		Z_CompiledInDeferFile_FID_Users_User_Documents_Unreal_Projects_DeathWorld_Source_DeathWorld_My_GameState_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_User_Documents_Unreal_Projects_DeathWorld_Source_DeathWorld_My_GameState_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
