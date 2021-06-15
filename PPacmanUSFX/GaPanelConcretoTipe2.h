#pragma once
#include "GamePanel.h"
class GaPanelConcretoTipe2 :
    public GamePanel
{
public:
    GaPanelConcretoTipe2(Texture* _texturaGamePanel, int _posicionX, int _posicionY);
    
    //Clonar
    GamePanel* Clonar();
};

