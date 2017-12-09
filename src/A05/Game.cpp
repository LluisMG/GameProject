#include "Game.h"

Game::Game()
 {
	currentScene = new SceneMenu();
	Game::gameState = GAMESTATE::MENU;
	}

void Game::Run() {
	
		while (gameState != GAMESTATE::EXIT) {
		
					//inici
			switch (currentScene->GetState()) {
			case SCENESTATE::RUNNING:
				currentScene->HandleEvent();
				currentScene->Update();
				currentScene->Draw();
				break;
				
					case SCENESTATE::EXIT:
						switch (gameState)
							{
							case GAMESTATE::MENU:
								delete currentScene;
								currentScene = nullptr;
								gameState = GAMESTATE::EXIT;
								break;
								default:
									break;
									}
						break;
						case SCENESTATE::GOTO:
							switch (gameState)
								{
								case GAMESTATE::MENU:
									delete currentScene;
									currentScene = new ScenePlay();
									gameState = GAMESTATE::PLAY;
									break;
									case GAMESTATE::PLAY:
										delete currentScene;
										currentScene = new SceneMenu();
										gameState = GAMESTATE::MENU;
										break;
										default:
											break;
											}
							break;
							default:
								break;
								
		}
			//fi
			
	}
	
}

Game::~Game()
 {
	}