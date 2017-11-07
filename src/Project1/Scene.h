#pragma once
#include "Renderer.h"

enum class SCENESTATE { RUNNING, GOTO, EXIT };

class Scene
{
public:
	Scene();

	SCENESTATE sceneState;
	
	virtual void HandleEvent();
	virtual void Update();
	virtual void Draw();

	SCENESTATE GetState();

	~Scene();
};

