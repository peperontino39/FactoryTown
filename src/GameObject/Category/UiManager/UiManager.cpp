#include "UiManager.h"

#include "UiBase/UiBase.h"



UiManager::UiManager()
{

}

UiManager::UiManager(const std::string & _json_name)
{


}

void UiManager::update()
{
	for (auto& ui : uis)
	{
		ui.second->update();
	}
}

void UiManager::drawUI()
{
	for (auto& ui : uis)
	{
		ui.second->drawUI();
	}
}


void UiManager::mouseDown()
{
	for (auto& ui : uis)
	{
		ui.second->drawUI();
	}

}


void UiManager::shutdown()
{
	for (auto& ui : uis)
	{
		ui.second->shutdown();
		delete ui.second;
	}

}

void UiManager::UiData(const std::string & _json_name)
{

}


