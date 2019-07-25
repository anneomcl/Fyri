#pragma once

UENUM()
enum class EObjectType : uint8
{
	EPlantable,
	ETerrain
};

UENUM()
enum class ETileType : uint8
{
	Grass,
	Water,
	Stone
};

UENUM(BlueprintType)
enum class EPlantableObjectType : uint8
{
	Plant,
	Food,
	Tree
};

UENUM(BlueprintType)
enum class EGrowingStage : uint8
{
	Sprout,
	Young,
	Old,
	VeryOld,

	MAX UMETA(Hidden)
};

enum class ENeighborLocationType : uint8
{
	Left,
	Right,
	Up,
	Down
};

UENUM()
enum class ESpawnTier : uint8
{
	Common,
	Fancy,
	Mythical
};