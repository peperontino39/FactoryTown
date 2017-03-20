#pragma once
#include "../../../GameObject.h"
#include "cinder/Color.h"
#include <map>

class UiBase : public GameObject
{
public:
	
	
	bool getIsActive();
	void setIsActive(const bool&);

	UiBase* addChild(const std::string&, UiBase*);
	UiBase* getParent();
	UiBase* getUi(const std::string&, const std::string&...);
	UiBase* getUi(const std::string&);
	
protected:

	void setDate(const ci::JsonTree&);
	virtual void setDateEach(const ci::JsonTree&) {};
	void drawUI() override {};
	void update() override {};
	void shutdown() override {};
	void mouseDown() override {};

	int width;
	int height;
	ci::Vec2f pivot;

	bool is_active = true;
	UiBase* parent;
	ci::ColorA color;

	std::map<std::string, UiBase*> uis;

private:

	friend class UiManager;
	void treeDrawUi();
	void treeUpdate();
	void treeMouseDown();
	void treeShutdown();
};