#pragma once
#include "Scene.h"

class SceneMenu : public Scene {

	SceneMenu();

	void EventHandle();
	void Update();
	void Draw();

	~SceneMenu();

};