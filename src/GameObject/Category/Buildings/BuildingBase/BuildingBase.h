#pragma once
#include "../../../GameObject.h"
#include <map>

class ItemBase;
enum ItemType;

class BuildingBase : public GameObject
{
public:
	virtual void draw();

	std::map<ItemType, ItemBase*> haveItems;
	ci::Vec2i size;
};