// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "DeathWorld/My_PlayerController.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeMy_PlayerController() {}
// Cross Module References
	DEATHWORLD_API UClass* Z_Construct_UClass_AMy_PlayerController();
	DEATHWORLD_API UClass* Z_Construct_UClass_AMy_PlayerController_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_APlayerController();
	UPackage* Z_Construct_UPackage__Script_DeathWorld();
// End Cross Module References
	void AMy_PlayerController::StaticRegisterNativesAMy_PlayerController()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AMy_PlayerController);
	UClass* Z_Construct_UClass_AMy_PlayerController_NoRegister()
	{
		return AMy_PlayerController::StaticClass();
	}
	struct Z_Construct_UClass_AMy_PlayerController_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AMy_PlayerController_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_APlayerController,
		(UObject* (*)())Z_Construct_UPackage__Script_DeathWorld,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AMy_PlayerController_Statics::DependentSingletons) < 16);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMy_PlayerController_Statics::Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "HideCategories", "Collision Rendering Transformation" },
		{ "IncludePath", "My_PlayerController.h" },
		{ "ModuleRelativePath", "My_PlayerController.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_AMy_PlayerController_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AMy_PlayerController>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_AMy_PlayerController_Statics::ClassParams = {
		&AMy_PlayerController::StaticClass,
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
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AMy_PlayerController_Statics::Class_MetaDataParams), Z_Construct_UClass_AMy_PlayerController_Statics::Class_MetaDataParams)
	};
	UClass* Z_Construct_UClass_AMy_PlayerController()
	{
		if (!Z_Registration_Info_UClass_AMy_PlayerController.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AMy_PlayerController.OuterSingleton, Z_Construct_UClass_AMy_PlayerController_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_AMy_PlayerController.OuterSingleton;
	}
	template<> DEATHWORLD_API UClass* StaticClass<AMy_PlayerController>()
	{
		return AMy_PlayerController::StaticClass();
	}
	AMy_PlayerController::AMy_PlayerController(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
	DEFINE_VTABLE_PTR_HELPER_CTOR(AMy_PlayerController);
	AMy_PlayerController::~AMy_PlayerController() {}
	struct Z_CompiledInDeferFile_FID_Users_User_Documents_Unreal_Projects_DeathWorld_Source_DeathWorld_My_PlayerController_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_User_Documents_Unreal_Projects_DeathWorld_Source_DeathWorld_My_PlayerController_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_AMy_PlayerController, AMy_PlayerController::StaticClass, TEXT("AMy_PlayerController"), &Z_Registration_Info_UClass_AMy_PlayerController, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AMy_PlayerController), 2170157614U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_User_Documents_Unreal_Projects_DeathWorld_Source_DeathWorld_My_PlayerController_h_1676293177(TEXT("/Script/DeathWorld"),
		Z_CompiledInDeferFile_FID_Users_User_Documents_Unreal_Projects_DeathWorld_Source_DeathWorld_My_PlayerController_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_User_Documents_Unreal_Projects_DeathWorld_Source_DeathWorld_My_PlayerController_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
