#include "Menu.h"
#include <iostream>

Menu::Menu()
{
	Menu::sceneState = SCENESTATE::RUNNING;
	Renderer::Instance()->LoadTexture("MENU_BG", PATH_IMG + "bg.jpg");
}

void Menu::EventHandle() {

}

void Menu::Update() {

}

void Menu::Draw() {
	Renderer::Instance()->Clear();
	Renderer::Instance()->PushImage("MENU_BG", {0,0, SCREEN_WIDTH, SCREEN_HEIGHT});
	Renderer::Instance()->Render();
}

Menu::~Menu()
{
}
