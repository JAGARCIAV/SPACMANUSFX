#pragma once
//#include "GameObject.h"
#include "Pacman.h"
#include "Tile.h"

class PacmanGalactico :
    public Pacman
{
protected:
	//PROPIEDADES


public:
    PacmanGalactico(Tile* _tile, Texture* _texturaPacman, int _posicionX, int _posicionY, int _velocidadPatron);
  // ~PacmanGalactico();

   // virtual void RestarVida();

   // virtual void setTile(Tile* _tileNuevo);

   // virtual void handleEvent(SDL_Event* event);

   //bool tratarDeMover(MoveDirection _direccionNueva);

   //virtual void update();

   //virtual void render();

   //virtual void Delete();

};

