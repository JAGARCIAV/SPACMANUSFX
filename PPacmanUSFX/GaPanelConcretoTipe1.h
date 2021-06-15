#pragma once
#include "GamePanel.h"
class GaPanelConcretoTipe1 :
    public GamePanel
{

private:
    string textoTipo1;
    int valorT1;

public:
    GaPanelConcretoTipe1(Texture* _texturaGamePanel, int _posicionX, int _posicionY);

    // clonar
    GamePanel* Clonar();


    //Metodos accesores
    string getTextoTipo1() { return textoTipo1; }

    void setTextoTipo1(string _textoTipo1) { textoTipo1 = _textoTipo1; }


};

