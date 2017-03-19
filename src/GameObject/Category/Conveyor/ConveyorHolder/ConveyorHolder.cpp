#include "ConveyorHolder.h"

#include "../ConveyorBase/ConveyorBase.h"
#include "cinder/app/App.h"

void ConveyorHolder::draw()
{
	for (auto& y : conveyor_2d)
	{
		for (auto& x : y)
		{
			x->draw();
		}
	}
}

void ConveyorHolder::setup()
{
	setSize(10,10);

}

void ConveyorHolder::shutdown()
{
	clear();
}

void ConveyorHolder::setSize(const int & _x, const int & _y)
{
	setSize(ci::Vec2i(_x, _y));
}

void ConveyorHolder::setSize(const ci::Vec2i & _size)
{
	size = _size;
	clear();
	conveyor_2d = 
		Conveyor2D(size.y, std::vector<ConveyorBase*>(size.x,nullptr));
	for (size_t y = 0; y < conveyor_2d.size(); y++)
	{
		for (size_t x = 0; x < conveyor_2d[y].size(); x++)
		{
			conveyor_2d[y][x] = new ConveyorBase();
			conveyor_2d[y][x]->transform.position = ci::Vec3f(x, 0, y);
		}
	}
}

void ConveyorHolder::setDirection(const ci::Vec2i & _sell , const ConveyorDirection & _dire)
{
	conveyor_2d[_sell.y][_sell.x]->setDirection(_dire);
}

void ConveyorHolder::changeDirection(const ci::Vec2i & _sell)
{
	ConveyorDirection dir = ConveyorDirection((conveyor_2d[_sell.y][_sell.x]->getDirection() + 1) % ConveyorDirection::NON);
	conveyor_2d[_sell.y][_sell.x]->setDirection(dir);
}



void ConveyorHolder::clear()
{
	for (auto& y : conveyor_2d)
	{
		for (auto& x : y)
		{
			if (x != nullptr)
				delete x;
		}
	}
	conveyor_2d.clear();
}

void ConveyorHolder::setConveyor(const int & _x, const int & _y, const ConveyorBase &_conveyor)
{


}
