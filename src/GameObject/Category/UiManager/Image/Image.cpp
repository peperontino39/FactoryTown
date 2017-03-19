#include "Image.h"

#include "cinder/gl/gl.h"

#include "../../../../Utility/AssetManager/TextureManager/TextureManager.h"
#include "cinder/app/App.h"

using namespace ci;
using namespace ci::app;


Image::Image()
{

	setTexture("default");
	color = ColorA::white();
	width = 100;
	height = 100;

}

void Image::drawUI()
{
	gl::pushMatrices();
	gl::multModelView(transform.getMultiMatrix());
	drawbegin();
	gl::color(color);
	gl::drawSolidRect(Rectf(-width / 2, -height / 2,
		width / 2, height/2));
	drawend();
	gl::popMatrices();

}

void Image::setTexture(const std::string & texture_name)
{
	texture = TextureM.get(texture_name);
	if (texture != nullptr) {
		drawbegin = [this] {texture->enableAndBind(); };
		drawend = [this] {texture->unbind(); };
	}
	else
	{
		drawbegin = [] {};
		drawend = [] {};

	}

}