// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "DeathWorld/My_GameInstance.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeMy_GameInstance() {}
// Cross Module References
	DEATHWORLD_API UClass* Z_Construct_UClass_UMy_GameInstance();
	DEATHWORLD_API UClass* Z_Construct_UClass_UMy_GameInstance_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UGameInstance();
	UPackage* Z_Construct_UPackage__Script_DeathWorld();
// End Cross Module References
	void UMy_GameInstance::StaticRegisterNativesUMy_GameInstance()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UMy_GameInstance);
	UClass* Z_Construct_UClass_UMy_GameInstance_NoRegister()
	{
		return UMy_GameInstance::StaticClass();
	}
	struct Z_Construct_UClass_UMy_GameInstance_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UMy_GameInstance_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UGameInstance,
		(UObject* (*)())Z_Construct_UPackage__Script_DeathWorld,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UMy_GameInstance_Statics::DependentSingletons) < 16);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UMy_GameInstance_Statics::Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "IncludePath", "My_GameInstance.h" },
		{ "ModuleRelativePath", "My_GameInstance.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UMy_GameInstance_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UMy_GameInstance>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UMy_GameInstance_Statics::ClassParams = {
		&UMy_GameInstance::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x009000A8u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UMy_GameInstance_Statics::Class_MetaDataParams), Z_Construct_UClass_UMy_GameInstance_Statics::Class_MetaDataParams)
	};
	UClass* Z_Construct_UClass_UMy_GameInstance()
	{
		if (!Z_Registration_Info_UClass_UMy_GameInstance.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UMy_GameInstance.OuterSingleton, Z_Construct_UClass_UMy_GameInstance_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UMy_GameInstance.OuterSingleton;
	}
	template<> DEATHWORLD_API UClass* StaticClass<UMy_GameInstance>()
	{
		return UMy_GameInstance::StaticClass();
	}
	UMy_GameInstance::UMy_GameInstance(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UMy_GameInstance);
	UMy_GameInstance::~UMy_GameInstance() {}
	struct Z_CompiledInDeferFile_FID_Users_User_Documents_Unreal_Projects_DeathWorld_Source_DeathWorld_My_GameInstance_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_User_Documents_Unreal_Projects_DeathWorld_Source_DeathWorld_My_GameInstance_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UMy_GameInstance, UMy_GameInstance::StaticClass, TEXT("UMy_GameInstance"), &Z_Registration_Info_UClass_UMy_GameInstance, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UMy_GameInstance), 3972057477U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_User_Documents_Unreal_Projects_DeathWorld_Source_DeathWorld_My_GameInstance_h_634920230(TEXT("/Script/DeathWorld"),
		Z_CompiledInDeferFile_FID_Users_User_Documents_Unreal_Projects_DeathWorld_Source_DeathWorld_My_GameInstance_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_User_Documents_Unreal_Projects_DeathWorld_Source_DeathWorld_My_GameInstance_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
