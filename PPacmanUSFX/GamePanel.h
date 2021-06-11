#pragma once
#include<string>
#include<SDL_ttf.h>

#include "GameObject.h"

class GamePanel :
    public GameObject
{
private:
    string texto;
public:
    GamePanel(Texture* _texturaGamePanel, int _posicionX, int _posicionY);
    void render() override;
};

