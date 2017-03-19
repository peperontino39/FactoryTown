#pragma once
#include "../../../GameObject.h"

#include <list>
//////Œš•¨‚ð‚Ü‚Æ‚ß‚éƒNƒ‰ƒX///////

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


