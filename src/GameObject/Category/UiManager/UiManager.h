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

	void setUiData(const std::string&); //json�̃p�X����Ui�̏������܂�
	void addUiData(const std::string&); //json�̃p�X����Ui�̏���ǉ����܂�

	UiBase* getUi(const std::string&, const std::string&...);
	UiBase* getUi(const std::string&);


private:

	void dateClear();
	std::map<std::string, UiBase*> uis;
};








