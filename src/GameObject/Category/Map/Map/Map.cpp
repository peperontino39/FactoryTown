#include "Map.h"

#include "../MapChipDate/MapChipDate.h"

#include "../../../../Utility/AssetManager/TextureManager/TextureManager.h"
#include "../../Item/ItemBase/ItemBase.h"
#include "../../../../Utility/Easing/Easing.h"
#include "../../../../Utility/Coroutine/Coroutine.h"


#include "cinder/Easing.h"
#include "cinder/Ray.h"
#include "cinder/app/App.h"

using namespace ci;
using namespace ci::app;

void Map::setup()
{
	setSize(10, 10);
	map_chip_texture = TextureM.get("mapchip");

}

void Map::mouseMove()
{


}

void Map::mouseDown()
{

}

void Map::shutdown()
{
	for (auto& y : map_chip) {
		for (auto& x : y) {
			x->shutdown();
		}
	}
	dateClear();
}

void Map::draw()
{
}

void Map::nonLightDraw()
{
	gl::color(Color::white());
	map_chip_texture->enableAndBind();
	for (auto& y : map_chip) {
		for (auto& x : y) {

			x->chipDraw();
		}
	}
	map_chip_texture->disable();
	for (auto& y : map_chip) {
		for (auto& x : y) {

			x->draw();
		}
	}

}

ci::Vec2i Map::touchSell(const ci::Ray & _ray)
{
	float t;
	_ray.calcPlaneIntersection(ci::Vec3f::zero(), ci::Vec3f::yAxis(), &t);
	auto pos = _ray.calcPosition(t).xz() + ci::Vec2f::one() * 0.5f;

	return pos;
}

void Map::setSize(const int & _x, const int & _y)
{

	dateClear();
	map_chip = MapChip(_y, std::vector<MapChipDate*>(_x, nullptr));
	for (size_t y = 0; y < map_chip.size(); y++)
	{
		for (size_t x = 0; x < map_chip[y].size(); x++)
		{
			map_chip[y][x] = new MapChipDate();
			map_chip[y][x]->transform.position = ci::Vec3f(x, 0, y);
			map_chip[y][x]->transform.rotate = Quatf(-M_PI / 2, 0, 0);
			map_chip[y][x]->setTipe(ChipTyap::GRASS);
		}
	}
}

void Map::setSize(const ci::Vec2i & _size)
{
	setSize(_size.x, _size.y);
}

void Map::changeConveyorDirection(const ci::Vec2i & _sell)
{
	map_chip[_sell.y][_sell.x]->changeDirection();
}

void Map::onItemMap(ItemBase * _item)
{
	auto _sell = _item->getSell();
	if (map_chip[_sell.y][_sell.x]->isEmpty())return;
	_sell += map_chip[_sell.y][_sell.x]->directionToVec();
	if (!isOutRange(_sell)) return;

	_item->setSell(_sell);

	Easing<Vec3f>::apply(_item->transform.position,
		map_chip[_sell.y][_sell.x]->transform.position
		+ (Vec3f::yAxis()/2),
		EaseInElastic(2, 1), 1.f);

	c_Coroutine(1.f, [_item, this]() {
		onItemMap(_item);
	});

}


bool Map::isOutRange(const ci::Vec2i& _sell)
{
	if (0 > _sell.y)return false;
	if (_sell.y >= map_chip.size())return false;
	if (0 > _sell.x)return false;
	if (_sell.x >= map_chip[_sell.y].size())return false;
	return true;
}





void Map::dateClear()
{
	for (auto& y : map_chip) {
		for (auto& x : y) {
			delete x;
		}
	}
	map_chip.clear();
}


