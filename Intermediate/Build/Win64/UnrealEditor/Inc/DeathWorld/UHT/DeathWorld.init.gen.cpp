// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeDeathWorld_init() {}
	static FPackageRegistrationInfo Z_Registration_Info_UPackage__Script_DeathWorld;
	FORCENOINLINE UPackage* Z_Construct_UPackage__Script_DeathWorld()
	{
		if (!Z_Registration_Info_UPackage__Script_DeathWorld.OuterSingleton)
		{
			static const UECodeGen_Private::FPackageParams PackageParams = {
				"/Script/DeathWorld",
				nullptr,
				0,
				PKG_CompiledIn | 0x00000000,
				0x1AAF640F,
				0xF7D57A39,
				METADATA_PARAMS(0, nullptr)
			};
			UECodeGen_Private::ConstructUPackage(Z_Registration_Info_UPackage__Script_DeathWorld.OuterSingleton, PackageParams);
		}
		return Z_Registration_Info_UPackage__Script_DeathWorld.OuterSingleton;
	}
	static FRegisterCompiledInInfo Z_CompiledInDeferPackage_UPackage__Script_DeathWorld(Z_Construct_UPackage__Script_DeathWorld, TEXT("/Script/DeathWorld"), Z_Registration_Info_UPackage__Script_DeathWorld, CONSTRUCT_RELOAD_VERSION_INFO(FPackageReloadVersionInfo, 0x1AAF640F, 0xF7D57A39));
PRAGMA_ENABLE_DEPRECATION_WARNINGS
