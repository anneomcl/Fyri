// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef TEAMWOLVERINEPROJECT_Tile_generated_h
#error "Tile.generated.h already included, missing '#pragma once' in Tile.h"
#endif
#define TEAMWOLVERINEPROJECT_Tile_generated_h

#define TeamWolverineProject_Source_TeamWolverineProject_Public_Tile_h_20_RPC_WRAPPERS
#define TeamWolverineProject_Source_TeamWolverineProject_Public_Tile_h_20_RPC_WRAPPERS_NO_PURE_DECLS
#define TeamWolverineProject_Source_TeamWolverineProject_Public_Tile_h_20_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesATile(); \
	friend struct Z_Construct_UClass_ATile_Statics; \
public: \
	DECLARE_CLASS(ATile, AActor, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/TeamWolverineProject"), NO_API) \
	DECLARE_SERIALIZER(ATile)


#define TeamWolverineProject_Source_TeamWolverineProject_Public_Tile_h_20_INCLASS \
private: \
	static void StaticRegisterNativesATile(); \
	friend struct Z_Construct_UClass_ATile_Statics; \
public: \
	DECLARE_CLASS(ATile, AActor, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/TeamWolverineProject"), NO_API) \
	DECLARE_SERIALIZER(ATile)


#define TeamWolverineProject_Source_TeamWolverineProject_Public_Tile_h_20_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ATile(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ATile) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ATile); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ATile); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ATile(ATile&&); \
	NO_API ATile(const ATile&); \
public:


#define TeamWolverineProject_Source_TeamWolverineProject_Public_Tile_h_20_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ATile(ATile&&); \
	NO_API ATile(const ATile&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ATile); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ATile); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(ATile)


#define TeamWolverineProject_Source_TeamWolverineProject_Public_Tile_h_20_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__mColor() { return STRUCT_OFFSET(ATile, mColor); } \
	FORCEINLINE static uint32 __PPO__mTileType() { return STRUCT_OFFSET(ATile, mTileType); }


#define TeamWolverineProject_Source_TeamWolverineProject_Public_Tile_h_17_PROLOG
#define TeamWolverineProject_Source_TeamWolverineProject_Public_Tile_h_20_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	TeamWolverineProject_Source_TeamWolverineProject_Public_Tile_h_20_PRIVATE_PROPERTY_OFFSET \
	TeamWolverineProject_Source_TeamWolverineProject_Public_Tile_h_20_RPC_WRAPPERS \
	TeamWolverineProject_Source_TeamWolverineProject_Public_Tile_h_20_INCLASS \
	TeamWolverineProject_Source_TeamWolverineProject_Public_Tile_h_20_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define TeamWolverineProject_Source_TeamWolverineProject_Public_Tile_h_20_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	TeamWolverineProject_Source_TeamWolverineProject_Public_Tile_h_20_PRIVATE_PROPERTY_OFFSET \
	TeamWolverineProject_Source_TeamWolverineProject_Public_Tile_h_20_RPC_WRAPPERS_NO_PURE_DECLS \
	TeamWolverineProject_Source_TeamWolverineProject_Public_Tile_h_20_INCLASS_NO_PURE_DECLS \
	TeamWolverineProject_Source_TeamWolverineProject_Public_Tile_h_20_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> TEAMWOLVERINEPROJECT_API UClass* StaticClass<class ATile>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID TeamWolverineProject_Source_TeamWolverineProject_Public_Tile_h


#define FOREACH_ENUM_ETILETYPE(op) \
	op(ETileType::Grass) \
	op(ETileType::Water) \
	op(ETileType::Sand) 

enum class ETileType;
template<> TEAMWOLVERINEPROJECT_API UEnum* StaticEnum<ETileType>();

PRAGMA_ENABLE_DEPRECATION_WARNINGS
