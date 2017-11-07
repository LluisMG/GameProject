#pragma once
#include "Scene.h"

class Menu :

	public Scene
{
public:
	Menu();

	void EventHandle();
	void Update();
	void Draw();

	~Menu();
};

