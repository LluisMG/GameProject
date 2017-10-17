#include <SDL.h>		// Always needs to be included for an SDL app
#include <SDL_image.h> 
#include <SDL_ttf.h>
#include <SDL_mixer.h>

//Game general information
#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600

int main(int, char*[]) {

	// --- INIT ---
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0) throw "No es pot inicialitzar SDL subsystems";

	// --- WINDOW ---
	SDL_Window *window{ SDL_CreateWindow("SDL...", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN) };
	if (window == nullptr) throw "No es pot inicialitzar SDL_Window";

	// --- RENDERER ---
	SDL_Renderer *renderer{ SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC) };
	if (renderer == nullptr) throw "No es pot inicialitzar SDL_Renderer";

	// --- SPRITES ---
	const Uint8 imgFlags{ IMG_INIT_PNG | IMG_INIT_JPG };
	if (!(IMG_Init(imgFlags) & imgFlags)) throw "Error: SDL_image init";

	//Background Init
	SDL_Texture *bgTexture{ IMG_LoadTexture(renderer, "../../res/img/bg.jpg") };
	if (bgTexture == nullptr) throw "No s'han pogut crear les Textures";
	
	SDL_Rect bgRect{ 0,0,SCREEN_WIDTH,SCREEN_HEIGHT };

	//Player Init
	SDL_Texture *playerTexture{ IMG_LoadTexture(renderer, "../../res/img/kintoun.png") };
	if (playerTexture == nullptr) throw "No s'han pogut crear les Textures";

	SDL_Rect playerRect{ 0,0,175,95 };
	SDL_Rect playerTarget{ 0,0,175,95 };	//Per suavitzar el moviment del jugador

		// --- Animated Sprite ---

	// --- TEXT ---
	//Font Init
	if (TTF_Init() != 0) throw "No es pot inicialitzar SDL_ttf";

	TTF_Font *font{ TTF_OpenFont("../../res/ttf/saiyan.ttf",80) };
	if (font == nullptr) throw "No es pot inicialitzar la TTF_Font";
	SDL_Surface *tmpSurf{ TTF_RenderText_Blended(font," Krilin la chupa",SDL_Color{255,150,0,255}) };
	if (tmpSurf == nullptr) throw "Unable to create the SDL text surface";
	SDL_Texture *textTexture{ SDL_CreateTextureFromSurface(renderer,tmpSurf) };
	SDL_Rect textRect{ 100,50,tmpSurf->w,tmpSurf->h };
	SDL_FreeSurface(tmpSurf);
	TTF_CloseFont(font);

	// --- AUDIO ---
	//Audio Init
	const Uint8 mixFlags{ MIX_INIT_MP3 | MIX_INIT_OGG };
	if (!(Mix_Init(mixFlags) & mixFlags)) throw "Error_ SDL_mixer Init";

	if (Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, 2, 1024) == -1) {
		throw "Unable to Init SDL_mixer audio systems";
	}
	Mix_Music *soundtrack{ Mix_LoadMUS("../../res/au/mainTheme.mp3") };
	if (!soundtrack) throw "Unable to load the Mix_Music soundtrack";
	Mix_VolumeMusic(MIX_MAX_VOLUME);
	Mix_PlayMusic(soundtrack, -1);

	// --- GAME LOOP ---
	SDL_Event event;
	bool isRunning = true;
	while (isRunning){
		// HANDLE EVENTS
		while (SDL_PollEvent(&event)) {
			switch (event.type) {
			case SDL_QUIT:		isRunning = false; break;
			case SDL_KEYDOWN:	if (event.key.keysym.sym == SDLK_ESCAPE) isRunning = false; break;

			//Moviment del jugador
			//case SDL_MOUSEMOTION:playerRect.x = event.motion.x - 87; playerRect.y = event.motion.y - 43; break;
			case SDL_MOUSEMOTION:playerTarget.x = event.motion.x - 87; playerTarget.y = event.motion.y - 43; break;		//Per suavitzar el moviment del jugador

			default:;
			}
		}

		// UPDATE

		//Per suavitzar el moviment del jugador
		playerRect.x += (playerTarget.x - playerRect.x) / 10;	
		playerRect.y += (playerTarget.y - playerRect.y) / 10;

		// DRAW
		SDL_RenderClear(renderer);		//Primera Linea Update
			//Background
			SDL_RenderCopy(renderer, bgTexture, nullptr, &bgRect);
			//Text
			SDL_RenderCopy(renderer, textTexture, nullptr, &textRect);

			//Player
			SDL_RenderCopy(renderer, playerTexture, nullptr, &playerRect);
		
			//Animated Sprite
		
		SDL_RenderPresent(renderer);	//Ùltima Linea Update
	}

	// --- DESTROY ---
	SDL_DestroyTexture(bgTexture);
	SDL_DestroyTexture(playerTexture);
	SDL_DestroyTexture(textTexture);
	Mix_CloseAudio();

	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);

	// --- QUIT ---
	Mix_Quit();		//Audio
	TTF_Quit();		//Text
	IMG_Quit();		//Sprites
	SDL_Quit();
	return 0;
}