#include "Scene.h"
#include "SceneMenu.h"
#include "ScenePlay.h"
#include "SceneRanking.h"
#include "Game.h"
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <stack>   
#include "Renderer.h"


int main() {

	bool quit = false;
	SDL_Event event;
	int this_tick = 0;
	int next_tick = 1000/SCREEN_FPS;

	Scene *curr_scene = new SceneMenu;

	while (!quit) {
		this_tick = SDL_GetTicks();
		if (this_tick < next_tick) {

			SDL_Delay(next_tick - this_tick);
		}
		next_tick = this_tick + (1000 / SCREEN_FPS);
		event = game->run(curr_scene);
	}

	return 0;
}