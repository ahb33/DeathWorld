// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "DeathWorld/Custom_GameMode.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeCustom_GameMode() {}
// Cross Module References
	DEATHWORLD_API UClass* Z_Construct_UClass_ACustom_GameMode();
	DEATHWORLD_API UClass* Z_Construct_UClass_ACustom_GameMode_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_AGameMode();
	UPackage* Z_Construct_UPackage__Script_DeathWorld();
// End Cross Module References
	void ACustom_GameMode::StaticRegisterNativesACustom_GameMode()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ACustom_GameMode);
	UClass* Z_Construct_UClass_ACustom_GameMode_NoRegister()
	{
		return ACustom_GameMode::StaticClass();
	}
	struct Z_Construct_UClass_ACustom_GameMode_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ACustom_GameMode_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AGameMode,
		(UObject* (*)())Z_Construct_UPackage__Script_DeathWorld,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ACustom_GameMode_Statics::DependentSingletons) < 16);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ACustom_GameMode_Statics::Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering HLOD WorldPartition DataLayers Transformation" },
		{ "IncludePath", "Custom_GameMode.h" },
		{ "ModuleRelativePath", "Custom_GameMode.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_ACustom_GameMode_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ACustom_GameMode>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_ACustom_GameMode_Statics::ClassParams = {
		&ACustom_GameMode::StaticClass,
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
		0x009002ACu,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ACustom_GameMode_Statics::Class_MetaDataParams), Z_Construct_UClass_ACustom_GameMode_Statics::Class_MetaDataParams)
	};
	UClass* Z_Construct_UClass_ACustom_GameMode()
	{
		if (!Z_Registration_Info_UClass_ACustom_GameMode.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ACustom_GameMode.OuterSingleton, Z_Construct_UClass_ACustom_GameMode_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_ACustom_GameMode.OuterSingleton;
	}
	template<> DEATHWORLD_API UClass* StaticClass<ACustom_GameMode>()
	{
		return ACustom_GameMode::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(ACustom_GameMode);
	ACustom_GameMode::~ACustom_GameMode() {}
	struct Z_CompiledInDeferFile_FID_Users_User_Documents_Unreal_Projects_DeathWorld_Source_DeathWorld_Custom_GameMode_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_User_Documents_Unreal_Projects_DeathWorld_Source_DeathWorld_Custom_GameMode_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_ACustom_GameMode, ACustom_GameMode::StaticClass, TEXT("ACustom_GameMode"), &Z_Registration_Info_UClass_ACustom_GameMode, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ACustom_GameMode), 582351679U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_User_Documents_Unreal_Projects_DeathWorld_Source_DeathWorld_Custom_GameMode_h_1838959736(TEXT("/Script/DeathWorld"),
		Z_CompiledInDeferFile_FID_Users_User_Documents_Unreal_Projects_DeathWorld_Source_DeathWorld_Custom_GameMode_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_User_Documents_Unreal_Projects_DeathWorld_Source_DeathWorld_Custom_GameMode_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
