#pragma once

#ifndef __EINVENTORYTYPE__H__
#define __EINVENTORYTYPE__H__

#include <cstdint>

#include "magic_enum.hpp"

static const uint8_t NUMBER_OF_INVENTORIES = 17;
/**
 * Represents the different types of inventories an entity may have
 */
enum eInventoryType : uint32_t {
	ITEMS = 0,
	VAULT_ITEMS,
	BRICKS,
	MODELS_IN_BBB,
	TEMP_ITEMS,
	MODELS,
	TEMP_MODELS,
	BEHAVIORS,
	PROPERTY_DEEDS,
	BRICKS_IN_BBB,
	VENDOR,
	VENDOR_BUYBACK,
	QUEST, //Used for mission items
	DONATION,
	VAULT_MODELS,
	ITEM_SETS, //internal, technically this is BankBehaviors.
	INVALID, // made up, for internal use!!!, Technically this called the ALL inventory.
	ALL, // Use this to search all inventories instead of a specific one.
};

class InventoryType {
public:
	static const char* InventoryTypeToString(eInventoryType inventory) {
		const char* eInventoryTypeTable[NUMBER_OF_INVENTORIES] = {
				"ITEMS",
				"VAULT_ITEMS",
				"BRICKS",
				"MODELS_IN_BBB",
				"TEMP_ITEMS",
				"MODELS",
				"TEMP_MODELS",
				"BEHAVIORS",
				"PROPERTY_DEEDS",
				"BRICKS_IN_BBB",
				"VENDOR",
				"VENDOR_BUYBACK",
				"QUEST", //Used for mission items
				"DONATION",
				"VAULT_MODELS",
				"ITEM_SETS", //internal, technically this is BankBehaviors.
				"INVALID" // made up, for internal use!!!, Technically this called the ALL inventory.
		};

		if (inventory > NUMBER_OF_INVENTORIES - 1) return nullptr;
		return eInventoryTypeTable[inventory];
	};
};

template <>
struct magic_enum::customize::enum_range<eInventoryType> {
	static constexpr int min = 0;
	static constexpr int max = 16;
};

#endif  //!__EINVENTORYTYPE__H__
