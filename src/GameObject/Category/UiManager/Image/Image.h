#pragma once
#include "../UiBase/UiBase.h"

class Image : public UiBase
{
public:
	Image();
	
	void drawUI();
	void setTexture(const std::string&);


private:
	ci::gl::TextureRef texture;
	std::function<void()> drawbegin = []{};
	std::function<void()> drawend = []{};

};


