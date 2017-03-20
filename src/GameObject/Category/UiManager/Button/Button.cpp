#include "Button.h"
#include "cinder/gl/gl.h"

using namespace ci;
using namespace ci::app;

Button::Button()
{
	color = ColorA(0,0,0,0.5f);
	width = 100;
	height = 100;

}

void Button::drawUI()
{
	gl::pushMatrices();
	gl::multModelView(transform.getMultiMatrix());
	gl::color(color);
	gl::drawSolidRect(Rectf(-width / 2, -height / 2,
		width / 2, height / 2));
	gl::popMatrices();
}

void Button::mouseDown()
{
	
}

void Button::setOnClick(std::function<void()> Fn)
{
	onClick = Fn;
}
