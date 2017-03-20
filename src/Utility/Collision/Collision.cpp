#include "Collision.h"
#include "cinder/Vector.h"


bool hit_PointToPlane_2d(const ci::Vec2f & point, const ci::Vec2f & plane_center, const ci::Vec2f & plane_size)
{
	if (plane_center.x - plane_size.x / 2 >= point.x) return false;
	if (point.x >= plane_size.x + plane_center.x / 2)return false;
	if (plane_center.y - plane_size.y / 2 >= point.y)return false;
	if (point.y >= plane_size.y + plane_center.y / 2)return false;
	
	return true;
}

