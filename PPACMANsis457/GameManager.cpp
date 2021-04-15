#include "GameManager.h"

using namespace std;

GameManager::GameManager() {
	gWindow = nullptr;
	gRenderer = nullptr;
	gScreenSurface = nullptr;
	//gPacManSurface = nullptr;
	gPacmanTexture = nullptr;

	juego_en_ejecucion = true;
}

int GameManager::onExecute() {
	if (onInit() == false) {
		return -1;
	}
	pacman = new Pacman(gRenderer, gPacmanTexture, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, 25, 25, SCREEN_WIDTH, SCREEN_HEIGHT, 5);
	fantasma = new Fantasma(gRenderer, gFantasmaTexture, 0, 0, 25, 25, SCREEN_WIDTH, SCREEN_HEIGHT, 5);
	fruta = new Fruta(gRenderer, gFrutasTextures, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, 25, 25, SCREEN_WIDTH, SCREEN_HEIGHT);
	srand(time(NULL));

	SDL_Event Event;

	while (juego_en_ejecucion) {
		while (SDL_PollEvent(&Event)) {
			onEvent(&Event);
			pacman->handleEvent(Event);
		}
		// Mover Pacman
		pacman->move();

		// Mover Fantasma
		fantasma->move();

		fruta->mostrar();
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
		gWindow = SDL_CreateWindow("Pacman USFX", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
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

			gPacmanTexture = loadTexture("Resources/PacMan_01.bmp");
			if (gPacmanTexture == NULL)
			{
				cout << "Fallo en la carga de la textura" << endl;
				success = false;
			}

			gFantasmaTexture = loadTexture("Resources/Fantasma.bmp");
			if (gFantasmaTexture == NULL)
			{
				cout << "Fallo en la carga de la textura aqui" << endl;
				success = false;
			}

			if ((gFrutasTextures[0] = loadTexture("Resources/Fruta01.png")) == NULL) {
				cout << "Fallo en la carga de la textura aqui" << endl;
				return false;
			}
			if ((gFrutasTextures[1] = loadTexture("Resources/Fruta04.png")) == NULL) {
				cout << "Fallo en la carga de la textura aqui" << endl;
				return false;
			}
			if ((gFrutasTextures[2] = loadTexture("Resources/Fruta03.png")) == NULL) {
				cout << "Fallo en la carga de la textura aqui" << endl;
				return false;
			}
			if ((gFrutasTextures[4] = loadTexture("Resources/Fruta02.png")) == NULL) {
				cout << "Fallo en la carga de la textura aqui" << endl;
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
	fantasma->render();
	fruta->render();
};

void GameManager::onCleanup() {
	SDL_FreeSurface(gScreenSurface);

	SDL_Quit();
};


SDL_Texture* GameManager::loadTexture(string path)
{
	// Textura final generada
	SDL_Texture* newTexture = nullptr;

	// Carga una imagen de una ruta especifica
	SDL_Surface* loadedSurface = IMG_Load(path.c_str());
	if (loadedSurface == NULL)
	{
		cout << "No se pudo cargarla imagen, SDL_image Error: " << IMG_GetError() << endl;
	}
	else
	{
		// Crea una textura a partir de una superficie de pixeles
		newTexture = SDL_CreateTextureFromSurface(gRenderer, loadedSurface);
		if (newTexture == NULL)
		{
			cout << "No se pudo crear la textura, SDL Error: " << SDL_GetError() << endl;
		}

		// Libera la superficie cargada
		SDL_FreeSurface(loadedSurface);
	}

	return newTexture;
}
