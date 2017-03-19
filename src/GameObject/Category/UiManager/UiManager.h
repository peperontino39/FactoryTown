#pragma once
#include "../../GameObject.h"
#include <map>

class UiBase;

class UiManager : public GameObject
{
public:
	UiManager();
	UiManager(const std::string&);
	void update()override;
	void drawUI()override;
	void mouseDown()override;
	void shutdown()override;

	void UiData(const std::string&);

	UiBase* getUi(const std::string&, const std::string&...);
	UiBase* getUi(const std::string&);

	template<typename T>
	static T* createUi(const std::string&);

private:

	std::map<std::string, UiBase*> uis;
};

template<typename T>
inline T * UiManager::createUi(const std::string & _type)
{
	if (_type == "Button")return new Button();


	return new UiBase();
}
