#pragma once
#include "../../../GameObject.h"

#include <list>
//////�������܂Ƃ߂�N���X///////

class BuildingBase;

class BuildingHolder : public GameObject
{
public:

	void setup() override;
	void draw() override;

	void shutdown()override;


private:
	std::list<BuildingBase*> building_holder;


};


