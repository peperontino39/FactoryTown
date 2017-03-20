#pragma once
#include "../UiBase/UiBase.h"

class Button : public UiBase
{
public:
	Button();
	

	void drawUI() override;
	void mouseDown() override;

	void setOnClick(std::function<void()>);


private:
	std::function<void()> onClick;
};