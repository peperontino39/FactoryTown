#include "ItemHolder.h"
#include "cinder/gl/gl.h"

#include "../ItemBase/ItemBase.h"
//#include "IItem/Wood/Wood.h"

using namespace ci;
using namespace ci::app;

void ItemHolder::setup()
{
	
	//instans(new Wood());
}

void ItemHolder::nonLightDraw()
{
	ci::gl::color(ci::Color::white());
	for (auto& ite : items) {
		ite->draw();
	}
}



void ItemHolder::shutdown()
{
	for (auto& ite : items) {
		delete ite;
	}
}

void ItemHolder::instans(ItemBase * _item)
{
	items.push_back(_item);
}

void ItemHolder::nullCheck()
{
	for (auto it = items.begin();
	it != items.end(); )
	{
		if (*(it) == nullptr) {
			it = items.erase(it);

			continue;
		}
		it++;
	}
}
