#pragma once
#include "Menu.h"
#include "Play.h"

enum class GAMESTATE { MENU, PLAY, EXIT };

class Game
{
public:
	Game();

	Scene *currentScene;
	GAMESTATE gameState;

	void Run();
	~Game();
};

