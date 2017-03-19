#include "GameMain.h"


#include "../../../GameObject/Category/MyEditCamera/MyEditCamera.h"
#include "../../../GameObject/Category/Conveyor/ConveyorHolder/ConveyorHolder.h"
#include "../../../GameObject/Category/Map/Map/Map.h"
#include "../../../GameObject/Category/GameMainTask/GameMainTask.h"
#include "../../../GameObject/Category/Item/ItemHolder/ItemHolder.h"
#include "../../../GameObject/Category/Buildings/BuildingHolder/BuildingHolder.h"
#include "../../../GameObject/Category/UiManager/UiManager.h"


void GameMain::onCreate()
{
	auto camera = Instantiate(new MyEditCamera());
	auto map = Instantiate(new Map());
	auto item_holder = Instantiate(new ItemHolder());
	auto building_holder = Instantiate(new BuildingHolder());
	auto uimanager = Instantiate(new UiManager("UiJson/GameMainUi.json"));

	auto game_main_task = Instantiate(new GameMainTask());

	game_main_task->camera = camera;
	game_main_task->map = map;
	game_main_task->map_item = item_holder;

}
