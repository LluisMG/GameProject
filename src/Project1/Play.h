#pragma once
#include "Scene.h"

class Play :
	public Scene
{
public:
	Play();

	void EventHandle();
	void Update();
	void Draw();

	~Play();
};

