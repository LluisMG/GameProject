#include "SceneMenu.h"
#include <iostream>

SceneMenu::SceneMenu()
{
	SceneMenu::sceneState = SCENESTATE::RUNNING;
	Renderer::Instance()->LoadTexture("MENU_BG", PATH_IMG + "bg.jpg");
	}

void SceneMenu::EventHandle() {
	
		
}

void SceneMenu::Update() {
	
		
}

void SceneMenu::Draw() {
	Renderer::Instance()->Clear();
	Renderer::Instance()->PushImage("MENU_BG", { 0,0, SCREEN_WIDTH, SCREEN_HEIGHT });
	Renderer::Instance()->Render();
	
}

SceneMenu::~SceneMenu()
 {
	}