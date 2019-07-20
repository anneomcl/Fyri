// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "TeamWolverineProject/Public/PlantableObject.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodePlantableObject() {}
// Cross Module References
	TEAMWOLVERINEPROJECT_API UEnum* Z_Construct_UEnum_TeamWolverineProject_EObjectType();
	UPackage* Z_Construct_UPackage__Script_TeamWolverineProject();
	TEAMWOLVERINEPROJECT_API UClass* Z_Construct_UClass_APlantableObject_NoRegister();
	TEAMWOLVERINEPROJECT_API UClass* Z_Construct_UClass_APlantableObject();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
// End Cross Module References
	static UEnum* EObjectType_StaticEnum()
	{
		static UEnum* Singleton = nullptr;
		if (!Singleton)
		{
			Singleton = GetStaticEnum(Z_Construct_UEnum_TeamWolverineProject_EObjectType, Z_Construct_UPackage__Script_TeamWolverineProject(), TEXT("EObjectType"));
		}
		return Singleton;
	}
	template<> TEAMWOLVERINEPROJECT_API UEnum* StaticEnum<EObjectType>()
	{
		return EObjectType_StaticEnum();
	}
	static FCompiledInDeferEnum Z_CompiledInDeferEnum_UEnum_EObjectType(EObjectType_StaticEnum, TEXT("/Script/TeamWolverineProject"), TEXT("EObjectType"), false, nullptr, nullptr);
	uint32 Get_Z_Construct_UEnum_TeamWolverineProject_EObjectType_Hash() { return 989440035U; }
	UEnum* Z_Construct_UEnum_TeamWolverineProject_EObjectType()
	{
#if WITH_HOT_RELOAD
		UPackage* Outer = Z_Construct_UPackage__Script_TeamWolverineProject();
		static UEnum* ReturnEnum = FindExistingEnumIfHotReloadOrDynamic(Outer, TEXT("EObjectType"), 0, Get_Z_Construct_UEnum_TeamWolverineProject_EObjectType_Hash(), false);
#else
		static UEnum* ReturnEnum = nullptr;
#endif // WITH_HOT_RELOAD
		if (!ReturnEnum)
		{
			static const UE4CodeGen_Private::FEnumeratorParam Enumerators[] = {
				{ "EObjectType::Flower", (int64)EObjectType::Flower },
				{ "EObjectType::Bush", (int64)EObjectType::Bush },
				{ "EObjectType::Tree", (int64)EObjectType::Tree },
			};
#if WITH_METADATA
			const UE4CodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
				{ "ModuleRelativePath", "Public/PlantableObject.h" },
			};
#endif
			static const UE4CodeGen_Private::FEnumParams EnumParams = {
				(UObject*(*)())Z_Construct_UPackage__Script_TeamWolverineProject,
				nullptr,
				"EObjectType",
				"EObjectType",
				Enumerators,
				ARRAY_COUNT(Enumerators),
				RF_Public|RF_Transient|RF_MarkAsNative,
				UE4CodeGen_Private::EDynamicType::NotDynamic,
				(uint8)UEnum::ECppForm::EnumClass,
				METADATA_PARAMS(Enum_MetaDataParams, ARRAY_COUNT(Enum_MetaDataParams))
			};
			UE4CodeGen_Private::ConstructUEnum(ReturnEnum, EnumParams);
		}
		return ReturnEnum;
	}
	void APlantableObject::StaticRegisterNativesAPlantableObject()
	{
	}
	UClass* Z_Construct_UClass_APlantableObject_NoRegister()
	{
		return APlantableObject::StaticClass();
	}
	struct Z_Construct_UClass_APlantableObject_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_APlantableObject_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_TeamWolverineProject,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_APlantableObject_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "PlantableObject.h" },
		{ "ModuleRelativePath", "Public/PlantableObject.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_APlantableObject_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<APlantableObject>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_APlantableObject_Statics::ClassParams = {
		&APlantableObject::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x009000A0u,
		METADATA_PARAMS(Z_Construct_UClass_APlantableObject_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_APlantableObject_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_APlantableObject()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_APlantableObject_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(APlantableObject, 2761083310);
	template<> TEAMWOLVERINEPROJECT_API UClass* StaticClass<APlantableObject>()
	{
		return APlantableObject::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_APlantableObject(Z_Construct_UClass_APlantableObject, &APlantableObject::StaticClass, TEXT("/Script/TeamWolverineProject"), TEXT("APlantableObject"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(APlantableObject);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
