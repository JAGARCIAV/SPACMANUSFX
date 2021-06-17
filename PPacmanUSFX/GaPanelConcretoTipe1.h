#pragma once
#include "GamePanel.h"
class GaPanelConcretoTipe1 :
    public GamePanel
{

public:

    GaPanelConcretoTipe1(Texture* _texturaGamePanel, int _posicionX, int _posicionY);

    // clonar
    GamePanel* Clonar();




};

