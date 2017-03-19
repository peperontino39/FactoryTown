#include "BuildingHolder.h"

#include "../BuildingBase/BuildingBase.h"


#include "../Warehouse/Warehouse.h"

void BuildingHolder::setup()
{

}

void BuildingHolder::draw()
{
	for (auto& buil : building_holder)
	{
		buil->draw();
	}
}

void BuildingHolder::shutdown()
{
	for (auto& buil : building_holder)
	{
		delete buil;
	}
}
