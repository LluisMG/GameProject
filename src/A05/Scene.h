#pragma once
#include "Renderer.h"

enum class SCENESTATE { RUNNING, GOTO, EXIT };

class Scene {
protected:
	bool isMuted;
	Scene();
	virtual ~Scene() {};
	virtual void eventhandler() = 0;
	virtual void update(float dtime, SDL_Event *event) = 0;
	virtual void draw() = 0;
	SCENESTATE sceneState;

};