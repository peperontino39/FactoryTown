#pragma once
#include "../../../GameObject.h"
#include <list>


///////�A�C�e�����܂Ƃ߂�N���X///////

class ItemBase;

class ItemHolder : public GameObject
{
public:
	void setup()override;

	void nonLightDraw() override;
	void shutdown()override;
	void instans(ItemBase*);

	void nullCheck();

private:
	

	std::list<ItemBase*> items;

};