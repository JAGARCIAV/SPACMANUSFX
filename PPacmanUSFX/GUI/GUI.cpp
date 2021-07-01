#include "GUI.h"

GUI::GUI()
{
    window = nullptr;
    renderer = nullptr;
    std::cout << "Construyendo GUI..." << std::endl;
    anchoWindow = 800;
    altoWindow = 600;
}


GUI::GUI(SDL_Window* _window, SDL_Renderer* _renderer)
{
    window = _window;
    renderer = _renderer;
	//std::cout << "Construyendo GUI..." << std::endl;
	anchoWindow = 800;
	altoWindow = 600;
}

int GUI::initializarSDL()
{
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) != 0) {
        SDL_Log("Failed to initialize SDL: %s", SDL_GetError());
        return EXIT_FAILURE;
    }

    // Create Window
    window = SDL_CreateWindow("Paintor", 100, 100, anchoWindow, altoWindow, SDL_WINDOW_SHOWN);
    if (window == nullptr) {
        SDL_Log("SDL_CreateWindow Error: %s", SDL_GetError());
        SDL_Quit();
        return EXIT_FAILURE;
    }

    // Create Renderer
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (renderer == nullptr) {
        SDL_Log("SDL_CreateRenderrer ErrorL %s", SDL_GetError());
        SDL_DestroyWindow(window);
        SDL_Quit();
        return EXIT_FAILURE;
    }

    std::cout << "SDL successfully initialized..." << std::endl;

    //std::cout << "Changing background color..." << std::endl;
    SDL_SetRenderDrawColor(renderer, 100, 100, 100, 255);
    SDL_RenderClear(renderer);

    return 0;
}

void GUI::agregarPanel(int _x, int _y, int _w, int _h, string _nombre, int _r, int _g, int _b, int _a, bool _flag)
{
    int offset = 1;
    Panel* panel_border = new Panel(renderer, _x - offset, _y - offset, _w + offset + offset, _h + offset + offset, _nombre + " border");
    panel_border->setPanelColorRGBA(0, 0, 0, 255);
    panel_border->setRevisarActividadMouse(false);

    paneles.push_back(panel_border);

    Panel* panel = new Panel(renderer, _x, _y, _w, _h, _nombre);
    panel->setPanelColorRGBA(_r, _g, _b, _a);
    panel->setRevisarActividadMouse(true);
    panel->setClickedOn(false);
    paneles.push_back(panel);
}

void GUI::render()
{
    for (Panel* panel : paneles) {
        panel->render();
    }
}

void GUI::terminarSDL()
{
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

void GUI::update()
{
    for (Panel* panel : paneles) {
        panel->update();
    }
}


void GUI::deleteGameObject()
{
    GameObject::deleteGameObject();
}

