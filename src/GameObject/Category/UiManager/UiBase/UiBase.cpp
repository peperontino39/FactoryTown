#include "UiBase.h"
#include "cinder/gl/gl.h"
#include "cinder/Json.h"
#include "../../../../Utility/Utility/Utility.h"

using namespace ci;


bool UiBase::getIsActive()
{
	return is_active;
}

void UiBase::setIsActive(const bool & _is_active)
{
	is_active = _is_active;
}

void UiBase::addChild(const std::string & _key, UiBase * _ui)
{
	uis[_key] = _ui;
}

UiBase* UiBase::getParent()
{
	return nullptr;

}

UiBase * UiBase::getUi(const std::string &, const std::string & ...)
{
	return nullptr;
}

UiBase * UiBase::getUi(const std::string &)
{
	return nullptr;
}

void UiBase::setDate(const ci::JsonTree & _json)
{
	std::string name;
	name = "position";
	if (_json.hasChild(name)) {
		auto j = _json.getChild(name);
		transform.position = JtoVec3f(j);
	}

	name = "width";
	if (_json.hasChild(name)) {
		width = _json.getValueForKey<int>(name);
	}

}

void UiBase::treeDrawUi()
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

void UiBase::treeUpdate()
{
	for (auto& ui : uis)
	{
		ui.second->update();
		ui.second->treeUpdate();
	}
}

void UiBase::treeMouseDown()
{
	for (auto& ui : uis)
	{
		ui.second->mouseDown();
		ui.second->treeMouseDown();
	}
}

void UiBase::treeShutdown()
{

	for (auto& ui : uis)
	{
		ui.second->treeShutdown();
		ui.second->shutdown();
		delete ui.second;
	}

}
