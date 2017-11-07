#include "Scene.h"

Scene::Scene()
{
}

void Scene::HandleEvent() {}
void Scene::Update(){}
void Scene::Draw() {}

SCENESTATE Scene::GetState() {
	return sceneState;
}

Scene::~Scene()
{
}
