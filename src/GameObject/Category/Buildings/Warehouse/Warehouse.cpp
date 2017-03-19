#include "Warehouse.h"

#include "cinder/gl/gl.h"

void Warehouse::draw()
{
	ci::gl::drawCube(ci::Vec3f::zero(), ci::Vec3f::one());
}

Warehouse::Warehouse()
{
	size = ci::Vec2i::one();
}
