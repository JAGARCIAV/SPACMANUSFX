#pragma once
#include "GameActor.h"
#include "GamePawnController.h"
class GamePawn :
    public GameActor
{
private:
protected:
    GamePawnController* gamePawnController;
public:
    // Constructores y destructores
    GamePawn();
    GamePawn(Texture* _textura);
    ~GamePawn();
    //Metodos accesores
    //Metodos varios

    //Metodos virtuales, redefinidos o sobrecargados
    virtual void render();
    virtual void update();
    virtual void handleEvent(SDL_Event* event);
    virtual void deleteGameObject();

};


