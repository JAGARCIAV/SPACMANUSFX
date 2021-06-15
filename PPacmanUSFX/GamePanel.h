#pragma once
#include<string>
#include<SDL_ttf.h>

#include "GameObject.h"

class GamePanel :
    public GameObject
{
private:
    string textoTipo;
    //string texto;

public:
    GamePanel(Texture* _texturaGamePanel, int _posicionX, int _posicionY);

    //acorde al patron prototype, debemos crear un metodo de tipo virtual y abstracto para poder clorar
    virtual GamePanel* Clonar() = 0;



    //Metodos accesores
    string getTextoTipo() { return textoTipo; }

    void setTextoTipo(string _textoTipo) { textoTipo = _textoTipo; }


    void render() override;
};

