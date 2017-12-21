#pragma once
#include "Renderer.h"

enum class SCENESTATE { RUNNING, GOTO, EXIT };

class Scene {
protected:
	bool isMuted;
	Scene();
	SCENESTATE sceneState;


	~Scene();

};