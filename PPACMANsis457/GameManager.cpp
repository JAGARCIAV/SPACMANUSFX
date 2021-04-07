#include "GameManager.h"

using namespace std;

GameManager::GameManager() {
	gWindow = nullptr;
	gRenderer = nullptr;
	gScreenSurface = nullptr;
	gPacManSurface = nullptr;
	gFantasmaSurface = nullptr;
	gCeresaSurface = nullptr;

	juego_en_ejecucion = true;
	pacman = new Pacman();
}

int GameManager::onExecute() {
	if (onInit() == false) {
		return -1;
	}

	pacman->window = gWindow;
	pacman->renderer = gRenderer;
	pacman->screenSurface = gScreenSurface;
	pacman->pacmanSurface = gPacManSurface;

	fantasma.window = gWindow;
	fantasma.renderer = gRenderer;
	fantasma.screenSurface = gScreenSurface;
	fantasma.fantasmaSurface = gFantasmaSurface;

	ceresa.window = gWindow;
	ceresa.renderer = gRenderer;
	ceresa.screenSurface = gScreenSurface;
	ceresa.ceresaSurface = gCeresaSurface;

	SDL_Event Event;

	while (juego_en_ejecucion) {
		while (SDL_PollEvent(&Event)) {
			onEvent(&Event);
			pacman->handleEvent(Event);
		}
		// Mover Pacman
		pacman->move();

		// Mover Fantasma
		fantasma.move();

		// Mover Ceresa
		ceresa.move();

		//Clear screen
		SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
		SDL_RenderClear(gRenderer);

		//Update screen

		onLoop();
		onRender();
		SDL_RenderPresent(gRenderer);
	}

	onCleanup();

	return 0;
}

bool GameManager::onInit() {
	//Initialization flag
	bool success = true;

	//Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		cout << "SDL could not initialize! SDL_Error: " << SDL_GetError() << endl;
		success = false;
	}
	else
	{
		//Create window
		gWindow = SDL_CreateWindow("Pacman sis 457", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (gWindow == NULL)
		{
			cout << "Window could not be created! SDL_Error: " << SDL_GetError() << endl;
			success = false;
		}
		else
		{

			//Create vsynced renderer for window
			gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
			if (gRenderer == NULL)
			{
				cout << "Renderer could not be created! SDL Error: " << SDL_GetError() << endl;
				success = false;
			}
			else
			{
				//Initialize renderer color
				SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
			}


			//Get window surface
			gScreenSurface = SDL_GetWindowSurface(gWindow);

			/*if ((gPacManSurface = loadMediaToSurface("Resources/PacMan_01.bmp")) == NULL) {
				return false;
			}*/

			if ((gPacManSurface = SDL_LoadBMP("Resources/PacMan_01.bmp")) == NULL) {
				return false;
			}

			if ((gFantasmaSurface = SDL_LoadBMP("Resources/Fantasma.bmp")) == NULL) {
				return false;
			}
			if ((gCeresaSurface = SDL_LoadBMP("Resources/Ceresa.bmp")) == NULL) {
				return false;
			}

		}
	}

	return success;
};

void GameManager::onEvent(SDL_Event* Event) {
	if (Event->type == SDL_QUIT) {
		juego_en_ejecucion = false;
	}
};
void GameManager::onLoop() {};
void GameManager::onRender() {
	pacman->render();
	fantasma.render();
	ceresa.render();
};

void GameManager::onCleanup() {
	SDL_FreeSurface(gScreenSurface);
	SDL_FreeSurface(gPacManSurface);
	SDL_Quit();
};
//
//SDL_Surface* GameManager::loadMediaToSurface(string _mediaFile){
//	SDL_Surface* Surf_Temp = nullptr;
//	//SDL_Surface* Surf_Return = NULL;
//
//	if ((Surf_Temp = SDL_LoadBMP(_mediaFile.c_str())) == nullptr) {
//		return nullptr;
//	}
//
//	/*Surf_Return = SDL_DisplayFormat(Surf_Temp);
//	SDL_FreeSurface(Surf_Temp);
//
//	return Surf_Return;*/
//	return Surf_Temp;
//};
