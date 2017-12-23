#pragma once

#include "SceneMenu.h"
#include "ScenePlay.h"
#include "Types.h"
#include "Renderer.h"

enum class GAMESTATE { MENU, PLAY, EXIT };

class Game
 {
 private :

	 Renderer *window;
	static Game *Instance;
	public:
		Game();
		
			Scene *currentScene;
		GAMESTATE gameState;
		static Game* Instance();
			void Run();
		~Game();
		};
