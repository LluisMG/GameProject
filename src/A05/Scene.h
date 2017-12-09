#pragma once
#include "Renderer.h"

enum class SCENESTATE { RUNNING, GOTO, EXIT };

class Scene {
protected:

	Scene();
	SCENESTATE sceneState;


	~Scene();

};