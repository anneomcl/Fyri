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
	TEAMWOLVERINEPROJECT_API UFunction* Z_Construct_UFunction_APlantableObject_OnSpawn();
	TEAMWOLVERINEPROJECT_API UClass* Z_Construct_UClass_ATile_NoRegister();
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
		UClass* Class = APlantableObject::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "OnSpawn", &APlantableObject::execOnSpawn },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_APlantableObject_OnSpawn_Statics
	{
		struct PlantableObject_eventOnSpawn_Parms
		{
			ATile* closestTile;
		};
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_closestTile;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_APlantableObject_OnSpawn_Statics::NewProp_closestTile = { "closestTile", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(PlantableObject_eventOnSpawn_Parms, closestTile), Z_Construct_UClass_ATile_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_APlantableObject_OnSpawn_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_APlantableObject_OnSpawn_Statics::NewProp_closestTile,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_APlantableObject_OnSpawn_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/PlantableObject.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_APlantableObject_OnSpawn_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_APlantableObject, nullptr, "OnSpawn", sizeof(PlantableObject_eventOnSpawn_Parms), Z_Construct_UFunction_APlantableObject_OnSpawn_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_APlantableObject_OnSpawn_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_APlantableObject_OnSpawn_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_APlantableObject_OnSpawn_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_APlantableObject_OnSpawn()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_APlantableObject_OnSpawn_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_APlantableObject_NoRegister()
	{
		return APlantableObject::StaticClass();
	}
	struct Z_Construct_UClass_APlantableObject_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
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
	const FClassFunctionLinkInfo Z_Construct_UClass_APlantableObject_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_APlantableObject_OnSpawn, "OnSpawn" }, // 3946993470
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
		FuncInfo,
		nullptr,
		nullptr,
		ARRAY_COUNT(DependentSingletons),
		ARRAY_COUNT(FuncInfo),
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
	IMPLEMENT_CLASS(APlantableObject, 2321110501);
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
