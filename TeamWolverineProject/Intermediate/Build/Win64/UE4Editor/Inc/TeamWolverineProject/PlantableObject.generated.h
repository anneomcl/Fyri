// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class ATile;
#ifdef TEAMWOLVERINEPROJECT_PlantableObject_generated_h
#error "PlantableObject.generated.h already included, missing '#pragma once' in PlantableObject.h"
#endif
#define TEAMWOLVERINEPROJECT_PlantableObject_generated_h

#define TeamWolverineProject_Source_TeamWolverineProject_Public_PlantableObject_h_21_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execOnSpawn) \
	{ \
		P_GET_OBJECT(ATile,Z_Param_closestTile); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->OnSpawn(Z_Param_closestTile); \
		P_NATIVE_END; \
	}


#define TeamWolverineProject_Source_TeamWolverineProject_Public_PlantableObject_h_21_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execOnSpawn) \
	{ \
		P_GET_OBJECT(ATile,Z_Param_closestTile); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->OnSpawn(Z_Param_closestTile); \
		P_NATIVE_END; \
	}


#define TeamWolverineProject_Source_TeamWolverineProject_Public_PlantableObject_h_21_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAPlantableObject(); \
	friend struct Z_Construct_UClass_APlantableObject_Statics; \
public: \
	DECLARE_CLASS(APlantableObject, AActor, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/TeamWolverineProject"), NO_API) \
	DECLARE_SERIALIZER(APlantableObject)


#define TeamWolverineProject_Source_TeamWolverineProject_Public_PlantableObject_h_21_INCLASS \
private: \
	static void StaticRegisterNativesAPlantableObject(); \
	friend struct Z_Construct_UClass_APlantableObject_Statics; \
public: \
	DECLARE_CLASS(APlantableObject, AActor, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/TeamWolverineProject"), NO_API) \
	DECLARE_SERIALIZER(APlantableObject)


#define TeamWolverineProject_Source_TeamWolverineProject_Public_PlantableObject_h_21_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API APlantableObject(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(APlantableObject) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, APlantableObject); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(APlantableObject); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API APlantableObject(APlantableObject&&); \
	NO_API APlantableObject(const APlantableObject&); \
public:


#define TeamWolverineProject_Source_TeamWolverineProject_Public_PlantableObject_h_21_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API APlantableObject(APlantableObject&&); \
	NO_API APlantableObject(const APlantableObject&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, APlantableObject); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(APlantableObject); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(APlantableObject)


#define TeamWolverineProject_Source_TeamWolverineProject_Public_PlantableObject_h_21_PRIVATE_PROPERTY_OFFSET
#define TeamWolverineProject_Source_TeamWolverineProject_Public_PlantableObject_h_18_PROLOG
#define TeamWolverineProject_Source_TeamWolverineProject_Public_PlantableObject_h_21_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	TeamWolverineProject_Source_TeamWolverineProject_Public_PlantableObject_h_21_PRIVATE_PROPERTY_OFFSET \
	TeamWolverineProject_Source_TeamWolverineProject_Public_PlantableObject_h_21_RPC_WRAPPERS \
	TeamWolverineProject_Source_TeamWolverineProject_Public_PlantableObject_h_21_INCLASS \
	TeamWolverineProject_Source_TeamWolverineProject_Public_PlantableObject_h_21_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define TeamWolverineProject_Source_TeamWolverineProject_Public_PlantableObject_h_21_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	TeamWolverineProject_Source_TeamWolverineProject_Public_PlantableObject_h_21_PRIVATE_PROPERTY_OFFSET \
	TeamWolverineProject_Source_TeamWolverineProject_Public_PlantableObject_h_21_RPC_WRAPPERS_NO_PURE_DECLS \
	TeamWolverineProject_Source_TeamWolverineProject_Public_PlantableObject_h_21_INCLASS_NO_PURE_DECLS \
	TeamWolverineProject_Source_TeamWolverineProject_Public_PlantableObject_h_21_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> TEAMWOLVERINEPROJECT_API UClass* StaticClass<class APlantableObject>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID TeamWolverineProject_Source_TeamWolverineProject_Public_PlantableObject_h


#define FOREACH_ENUM_EOBJECTTYPE(op) \
	op(EObjectType::Flower) \
	op(EObjectType::Bush) \
	op(EObjectType::Tree) 

enum class EObjectType;
template<> TEAMWOLVERINEPROJECT_API UEnum* StaticEnum<EObjectType>();

PRAGMA_ENABLE_DEPRECATION_WARNINGS
