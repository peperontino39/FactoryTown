#include "UiManager.h"

#include "cinder/Json.h"
#include "cinder/app/App.h"

#include "UiBase/UiBase.h"
#include "../../../Utility/Utility/Utility.h"

#include "Button/Button.h"
#include "Image/Image.h"


using namespace ci;
using namespace ci::app;


UiManager::UiManager()
{

}

UiManager::UiManager(const std::string & _json_path)
{
	setUiData(_json_path);
	uis["hoge"] = new Image();

	auto ima = new Image();
	ima->transform.position = Vec3f(50, 0,0);
	uis["hoge"]->addChild("test0", ima);

}

void UiManager::update()
{
	for (auto& ui : uis)
	{
		ui.second->treeUpdate();
	}
}

void UiManager::drawUI()
{
	ci::gl::pushMatrices();
	ci::gl::multModelView(transform.getMultiMatrix());

	for (auto& ui : uis)
	{
		ui.second->drawUI();
		ui.second->treeDrawUi();
	}

	ci::gl::popMatrices();

}


void UiManager::mouseDown()
{
	for (auto& ui : uis)
	{
		ui.second->mouseDown();
		ui.second->treeMouseDown();
	}
}


void UiManager::shutdown()
{
	dateClear();
}



void UiManager::setUiData(const std::string & _json_path)
{
	dateClear();
	addUiData(_json_path);
}

void UiManager::addUiData(const std::string & _json_path)
{
	JsonTree  json(loadAsset(_json_path));

	for (auto& date : json)
	{
		auto key = date.getValueForKey("Type");
		Log("key ",key);
		if (key == "") {

		}

	}

}

UiBase * UiManager::getUi(const std::string &, const std::string & ...)
{
	return nullptr;
}

UiBase * UiManager::getUi(const std::string &)
{
	return nullptr;
}

void UiManager::dateClear()
{
	for (auto& ui : uis)
	{
		ui.second->treeShutdown();
		ui.second->shutdown();
		delete ui.second;
	}
}




