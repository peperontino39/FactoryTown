#pragma once
#include "../../../GameObject.h"
#include "../../../../Utility/CinderFwd.h"


class ConveyorBase;
class ItemBase;

enum ChipTyap {	
	
	GRASS = 248//ëê
};

#define MAPCHIP_TEXTURE_WIDTH 31
#define MAPCHIP_TEXTURE_HEIGHT 16

class MapChipDate : public GameObject
{
public:
	MapChipDate();
	void draw()override;
	void shutdown()override;

	void chipDraw();

	ConveyorBase* getConveyor();
	void setTipe(const ChipTyap&);
	void setSell(const ci::Vec2i&);
	void setConveyorBase(ConveyorBase*);
	void setItem(ItemBase*);
	
	void changeDirection();
	ci::Vec2i directionToVec();
	bool isEmpty();///ñ≥Ç©Ç¡ÇΩÇÁtrueÇï‘ÇµÇ‹Ç∑

private:

	ci::Vec2f cut_pos;
	ci::Vec2i sell;
	ChipTyap type;
	ConveyorBase* conveyor;
	ItemBase* item;

};