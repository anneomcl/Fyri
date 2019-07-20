// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "TeamWolverineProject/Public/ObjectManager.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeObjectManager() {}
// Cross Module References
	TEAMWOLVERINEPROJECT_API UClass* Z_Construct_UClass_UInteractionResult_NoRegister();
	TEAMWOLVERINEPROJECT_API UClass* Z_Construct_UClass_UInteractionResult();
	ENGINE_API UClass* Z_Construct_UClass_UDataAsset();
	UPackage* Z_Construct_UPackage__Script_TeamWolverineProject();
	ENGINE_API UClass* Z_Construct_UClass_UParticleSystem_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_USoundBase_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UAnimInstance_NoRegister();
	TEAMWOLVERINEPROJECT_API UClass* Z_Construct_UClass_UObjectInteraction_NoRegister();
	TEAMWOLVERINEPROJECT_API UClass* Z_Construct_UClass_UObjectInteraction();
	TEAMWOLVERINEPROJECT_API UEnum* Z_Construct_UEnum_TeamWolverineProject_EObjectType();
	TEAMWOLVERINEPROJECT_API UClass* Z_Construct_UClass_UObjectManagerComponent_NoRegister();
	TEAMWOLVERINEPROJECT_API UClass* Z_Construct_UClass_UObjectManagerComponent();
	ENGINE_API UClass* Z_Construct_UClass_UActorComponent();
	TEAMWOLVERINEPROJECT_API UClass* Z_Construct_UClass_APlantableObject_NoRegister();
	TEAMWOLVERINEPROJECT_API UClass* Z_Construct_UClass_ATile_NoRegister();
// End Cross Module References
	void UInteractionResult::StaticRegisterNativesUInteractionResult()
	{
	}
	UClass* Z_Construct_UClass_UInteractionResult_NoRegister()
	{
		return UInteractionResult::StaticClass();
	}
	struct Z_Construct_UClass_UInteractionResult_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_mParticleEffect_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_mParticleEffect;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_mSound_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_mSound;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_mAnimation_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_mAnimation;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UInteractionResult_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UDataAsset,
		(UObject* (*)())Z_Construct_UPackage__Script_TeamWolverineProject,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UInteractionResult_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "ObjectManager.h" },
		{ "ModuleRelativePath", "Public/ObjectManager.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UInteractionResult_Statics::NewProp_mParticleEffect_MetaData[] = {
		{ "Category", "InteractionResult" },
		{ "ModuleRelativePath", "Public/ObjectManager.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UInteractionResult_Statics::NewProp_mParticleEffect = { "mParticleEffect", nullptr, (EPropertyFlags)0x0040000000000001, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UInteractionResult, mParticleEffect), Z_Construct_UClass_UParticleSystem_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UInteractionResult_Statics::NewProp_mParticleEffect_MetaData, ARRAY_COUNT(Z_Construct_UClass_UInteractionResult_Statics::NewProp_mParticleEffect_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UInteractionResult_Statics::NewProp_mSound_MetaData[] = {
		{ "Category", "InteractionResult" },
		{ "ModuleRelativePath", "Public/ObjectManager.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UInteractionResult_Statics::NewProp_mSound = { "mSound", nullptr, (EPropertyFlags)0x0040000000000001, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UInteractionResult, mSound), Z_Construct_UClass_USoundBase_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UInteractionResult_Statics::NewProp_mSound_MetaData, ARRAY_COUNT(Z_Construct_UClass_UInteractionResult_Statics::NewProp_mSound_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UInteractionResult_Statics::NewProp_mAnimation_MetaData[] = {
		{ "Category", "InteractionResult" },
		{ "ModuleRelativePath", "Public/ObjectManager.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UInteractionResult_Statics::NewProp_mAnimation = { "mAnimation", nullptr, (EPropertyFlags)0x0040000000000001, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UInteractionResult, mAnimation), Z_Construct_UClass_UAnimInstance_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UInteractionResult_Statics::NewProp_mAnimation_MetaData, ARRAY_COUNT(Z_Construct_UClass_UInteractionResult_Statics::NewProp_mAnimation_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UInteractionResult_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UInteractionResult_Statics::NewProp_mParticleEffect,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UInteractionResult_Statics::NewProp_mSound,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UInteractionResult_Statics::NewProp_mAnimation,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UInteractionResult_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UInteractionResult>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UInteractionResult_Statics::ClassParams = {
		&UInteractionResult::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_UInteractionResult_Statics::PropPointers,
		nullptr,
		ARRAY_COUNT(DependentSingletons),
		0,
		ARRAY_COUNT(Z_Construct_UClass_UInteractionResult_Statics::PropPointers),
		0,
		0x000000A0u,
		METADATA_PARAMS(Z_Construct_UClass_UInteractionResult_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_UInteractionResult_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UInteractionResult()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UInteractionResult_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UInteractionResult, 1730959460);
	template<> TEAMWOLVERINEPROJECT_API UClass* StaticClass<UInteractionResult>()
	{
		return UInteractionResult::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UInteractionResult(Z_Construct_UClass_UInteractionResult, &UInteractionResult::StaticClass, TEXT("/Script/TeamWolverineProject"), TEXT("UInteractionResult"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UInteractionResult);
	void UObjectInteraction::StaticRegisterNativesUObjectInteraction()
	{
	}
	UClass* Z_Construct_UClass_UObjectInteraction_NoRegister()
	{
		return UObjectInteraction::StaticClass();
	}
	struct Z_Construct_UClass_UObjectInteraction_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_mInteractionResult_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_mInteractionResult;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_mTypeB_MetaData[];
#endif
		static const UE4CodeGen_Private::FEnumPropertyParams NewProp_mTypeB;
		static const UE4CodeGen_Private::FUnsizedIntPropertyParams NewProp_mTypeB_Underlying;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_mTypeA_MetaData[];
#endif
		static const UE4CodeGen_Private::FEnumPropertyParams NewProp_mTypeA;
		static const UE4CodeGen_Private::FUnsizedIntPropertyParams NewProp_mTypeA_Underlying;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UObjectInteraction_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UDataAsset,
		(UObject* (*)())Z_Construct_UPackage__Script_TeamWolverineProject,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UObjectInteraction_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "ObjectManager.h" },
		{ "ModuleRelativePath", "Public/ObjectManager.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UObjectInteraction_Statics::NewProp_mInteractionResult_MetaData[] = {
		{ "Category", "ObjectInteraction" },
		{ "ModuleRelativePath", "Public/ObjectManager.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UObjectInteraction_Statics::NewProp_mInteractionResult = { "mInteractionResult", nullptr, (EPropertyFlags)0x0040000000000001, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UObjectInteraction, mInteractionResult), Z_Construct_UClass_UInteractionResult_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UObjectInteraction_Statics::NewProp_mInteractionResult_MetaData, ARRAY_COUNT(Z_Construct_UClass_UObjectInteraction_Statics::NewProp_mInteractionResult_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UObjectInteraction_Statics::NewProp_mTypeB_MetaData[] = {
		{ "Category", "ObjectInteraction" },
		{ "ModuleRelativePath", "Public/ObjectManager.h" },
	};
#endif
	const UE4CodeGen_Private::FEnumPropertyParams Z_Construct_UClass_UObjectInteraction_Statics::NewProp_mTypeB = { "mTypeB", nullptr, (EPropertyFlags)0x0040000000000001, UE4CodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UObjectInteraction, mTypeB), Z_Construct_UEnum_TeamWolverineProject_EObjectType, METADATA_PARAMS(Z_Construct_UClass_UObjectInteraction_Statics::NewProp_mTypeB_MetaData, ARRAY_COUNT(Z_Construct_UClass_UObjectInteraction_Statics::NewProp_mTypeB_MetaData)) };
	const UE4CodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UClass_UObjectInteraction_Statics::NewProp_mTypeB_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UObjectInteraction_Statics::NewProp_mTypeA_MetaData[] = {
		{ "Category", "ObjectInteraction" },
		{ "ModuleRelativePath", "Public/ObjectManager.h" },
	};
#endif
	const UE4CodeGen_Private::FEnumPropertyParams Z_Construct_UClass_UObjectInteraction_Statics::NewProp_mTypeA = { "mTypeA", nullptr, (EPropertyFlags)0x0040000000000001, UE4CodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UObjectInteraction, mTypeA), Z_Construct_UEnum_TeamWolverineProject_EObjectType, METADATA_PARAMS(Z_Construct_UClass_UObjectInteraction_Statics::NewProp_mTypeA_MetaData, ARRAY_COUNT(Z_Construct_UClass_UObjectInteraction_Statics::NewProp_mTypeA_MetaData)) };
	const UE4CodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UClass_UObjectInteraction_Statics::NewProp_mTypeA_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UObjectInteraction_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UObjectInteraction_Statics::NewProp_mInteractionResult,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UObjectInteraction_Statics::NewProp_mTypeB,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UObjectInteraction_Statics::NewProp_mTypeB_Underlying,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UObjectInteraction_Statics::NewProp_mTypeA,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UObjectInteraction_Statics::NewProp_mTypeA_Underlying,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UObjectInteraction_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UObjectInteraction>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UObjectInteraction_Statics::ClassParams = {
		&UObjectInteraction::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_UObjectInteraction_Statics::PropPointers,
		nullptr,
		ARRAY_COUNT(DependentSingletons),
		0,
		ARRAY_COUNT(Z_Construct_UClass_UObjectInteraction_Statics::PropPointers),
		0,
		0x000000A0u,
		METADATA_PARAMS(Z_Construct_UClass_UObjectInteraction_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_UObjectInteraction_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UObjectInteraction()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UObjectInteraction_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UObjectInteraction, 4201455464);
	template<> TEAMWOLVERINEPROJECT_API UClass* StaticClass<UObjectInteraction>()
	{
		return UObjectInteraction::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UObjectInteraction(Z_Construct_UClass_UObjectInteraction, &UObjectInteraction::StaticClass, TEXT("/Script/TeamWolverineProject"), TEXT("UObjectInteraction"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UObjectInteraction);
	void UObjectManagerComponent::StaticRegisterNativesUObjectManagerComponent()
	{
	}
	UClass* Z_Construct_UClass_UObjectManagerComponent_NoRegister()
	{
		return UObjectManagerComponent::StaticClass();
	}
	struct Z_Construct_UClass_UObjectManagerComponent_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_mObjectInteractions_MetaData[];
#endif
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_mObjectInteractions;
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_mObjectInteractions_Inner;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_mObjects_MetaData[];
#endif
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_mObjects;
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_mObjects_Inner;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_mTiles_MetaData[];
#endif
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_mTiles;
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_mTiles_Inner;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UObjectManagerComponent_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UActorComponent,
		(UObject* (*)())Z_Construct_UPackage__Script_TeamWolverineProject,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UObjectManagerComponent_Statics::Class_MetaDataParams[] = {
		{ "BlueprintSpawnableComponent", "" },
		{ "IncludePath", "ObjectManager.h" },
		{ "ModuleRelativePath", "Public/ObjectManager.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UObjectManagerComponent_Statics::NewProp_mObjectInteractions_MetaData[] = {
		{ "Category", "ObjectManagerComponent" },
		{ "ModuleRelativePath", "Public/ObjectManager.h" },
	};
#endif
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UObjectManagerComponent_Statics::NewProp_mObjectInteractions = { "mObjectInteractions", nullptr, (EPropertyFlags)0x0040000000000001, UE4CodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UObjectManagerComponent, mObjectInteractions), METADATA_PARAMS(Z_Construct_UClass_UObjectManagerComponent_Statics::NewProp_mObjectInteractions_MetaData, ARRAY_COUNT(Z_Construct_UClass_UObjectManagerComponent_Statics::NewProp_mObjectInteractions_MetaData)) };
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UObjectManagerComponent_Statics::NewProp_mObjectInteractions_Inner = { "mObjectInteractions", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UClass_UObjectInteraction_NoRegister, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UObjectManagerComponent_Statics::NewProp_mObjects_MetaData[] = {
		{ "Category", "ObjectManagerComponent" },
		{ "ModuleRelativePath", "Public/ObjectManager.h" },
	};
#endif
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UObjectManagerComponent_Statics::NewProp_mObjects = { "mObjects", nullptr, (EPropertyFlags)0x0040000000000001, UE4CodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UObjectManagerComponent, mObjects), METADATA_PARAMS(Z_Construct_UClass_UObjectManagerComponent_Statics::NewProp_mObjects_MetaData, ARRAY_COUNT(Z_Construct_UClass_UObjectManagerComponent_Statics::NewProp_mObjects_MetaData)) };
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UObjectManagerComponent_Statics::NewProp_mObjects_Inner = { "mObjects", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UClass_APlantableObject_NoRegister, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UObjectManagerComponent_Statics::NewProp_mTiles_MetaData[] = {
		{ "Category", "ObjectManagerComponent" },
		{ "ModuleRelativePath", "Public/ObjectManager.h" },
	};
#endif
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UObjectManagerComponent_Statics::NewProp_mTiles = { "mTiles", nullptr, (EPropertyFlags)0x0040000000000001, UE4CodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UObjectManagerComponent, mTiles), METADATA_PARAMS(Z_Construct_UClass_UObjectManagerComponent_Statics::NewProp_mTiles_MetaData, ARRAY_COUNT(Z_Construct_UClass_UObjectManagerComponent_Statics::NewProp_mTiles_MetaData)) };
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UObjectManagerComponent_Statics::NewProp_mTiles_Inner = { "mTiles", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UClass_ATile_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UObjectManagerComponent_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UObjectManagerComponent_Statics::NewProp_mObjectInteractions,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UObjectManagerComponent_Statics::NewProp_mObjectInteractions_Inner,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UObjectManagerComponent_Statics::NewProp_mObjects,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UObjectManagerComponent_Statics::NewProp_mObjects_Inner,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UObjectManagerComponent_Statics::NewProp_mTiles,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UObjectManagerComponent_Statics::NewProp_mTiles_Inner,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UObjectManagerComponent_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UObjectManagerComponent>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UObjectManagerComponent_Statics::ClassParams = {
		&UObjectManagerComponent::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_UObjectManagerComponent_Statics::PropPointers,
		nullptr,
		ARRAY_COUNT(DependentSingletons),
		0,
		ARRAY_COUNT(Z_Construct_UClass_UObjectManagerComponent_Statics::PropPointers),
		0,
		0x00B000A4u,
		METADATA_PARAMS(Z_Construct_UClass_UObjectManagerComponent_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_UObjectManagerComponent_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UObjectManagerComponent()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UObjectManagerComponent_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UObjectManagerComponent, 255886859);
	template<> TEAMWOLVERINEPROJECT_API UClass* StaticClass<UObjectManagerComponent>()
	{
		return UObjectManagerComponent::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UObjectManagerComponent(Z_Construct_UClass_UObjectManagerComponent, &UObjectManagerComponent::StaticClass, TEXT("/Script/TeamWolverineProject"), TEXT("UObjectManagerComponent"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UObjectManagerComponent);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
