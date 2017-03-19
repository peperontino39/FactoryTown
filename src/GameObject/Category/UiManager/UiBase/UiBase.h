#pragma once
#include "../../../GameObject.h"
#include <map>

class UiBase : public GameObject
{
public:


	void drawUI() override final;
	void update()override final;
	void shutdown()override final;
	void mouseDown()override final;

	bool getIsActive();
	void setIsActive(const bool&);
	UiBase* getUi(const std::string&, const std::string&...);
	UiBase* getUi(const std::string&);

private:
	bool is_active;
	int width;
	int height;
	ci::Vec2f pivot;
	UiBase* parent;
	std::map<std::string, UiBase*> uis;

};