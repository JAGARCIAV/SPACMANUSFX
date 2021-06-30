#pragma once
#include "GamePawnController.h"
class GamePawnControllerKey1 :
    public GamePawnController
{
public:
    GamePawnControllerKey1();
    void handleEvent(SDL_Event* event);
};

