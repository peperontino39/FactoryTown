#pragma once
#include "../../GameObject.h"
#include <map>

#include "Button/Button.h"
#include "Image/Image.h"

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

	void setUiData(const std::string&); //jsonのパスからUiの情報を作ります
	void addUiData(const std::string&); //jsonのパスからUiの情報を追加します

	UiBase* getUi(const std::string&, const std::string&...);
	UiBase* getUi(const std::string&);

	template<typename T>
	static T createUi(const std::string& _type);

private:

	void dateClear();
	std::map<std::string, UiBase*> uis;
};

template<typename T>
inline T UiManager::createUi(const std::string& _type)
{
	if (_type == "Button") return new Button();
	if (_type == "Image")return new Image();
	return nullptr;
}
