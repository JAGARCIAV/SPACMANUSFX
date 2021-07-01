#pragma once
#include "../GameObject.h"
#include <iostream>
#include <vector>
#include <string>
#include <SDL.h>
#include "Panel.h"

class GUI :
    public GameObject
{
protected:
	SDL_Window* window = nullptr;
	SDL_Renderer* renderer = nullptr;
	int anchoWindow;
	int altoWindow;
	std::vector<Panel*> paneles;
public:
	GUI();
	GUI(SDL_Window* _window, SDL_Renderer* _renderer);
	int initializarSDL();
	void agregarPanel(int x, int y, int w, int h, std::string name, int r, int g, int b, int a, bool flag);
	virtual void render();
	void terminarSDL();

	virtual void update();
	virtual void handleEvent(SDL_Event* event) {};
	virtual void deleteGameObject();
};
