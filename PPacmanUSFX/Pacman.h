#pragma once
#include <iostream>
#include <string>
#include <algorithm>

#include <SDL.h>

#include "GamePawn.h"
#include "Texture.h"
#include "Tile.h"
#include "TileGraph.h"
#include "MoveDirection.h"
#include "Moneda.h"
#include "Fruta.h"


using namespace std;

class Pacman : public GamePawn
{
protected:
	
	//static Pacman* instancia;

	//int estado;

	GameObjectType returType() { return PACMAN; }
public:
	//Constructores y destructores
	Pacman(Tile* _tile, Texture* _textura);
	~Pacman() {};

	//	static Pacman* crearInstancia(Tile* _tile, Texture* _texturaPacman, int _posicionX, int _posicionY, int _ancho, int _alto, int _anchoPantalla, int _altoPantalla, int _velocidadPatron);

	//Metodos accesores
	/*int getEstado() { return estado; }
	void setEstado(int _estado) { estado = _estado; }*/
	void setTileActual(Tile* _tileNuevo) override;

	// Metodos varios

	//Metodos virtuales, redefinidos o sobrecargados
	//void handleEvent(SDL_Event* event);
	// Mover pacman
	void update();
	// Renderizar imagen pacman
	void render() override;
	//void update();
	void deleteGameObject() override;

};