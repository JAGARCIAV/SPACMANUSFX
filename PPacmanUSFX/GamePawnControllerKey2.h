#pragma once
#include "GamePawnController.h"
class GamePawnControllerKey2 :
    public GamePawnController
{
public:
    GamePawnControllerKey2();
    void handleEvent(SDL_Event* event);
};

