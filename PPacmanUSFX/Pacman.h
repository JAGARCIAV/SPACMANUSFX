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
#include "SuperMoneda.h"
#include "Fruta.h"
#include "GamePawnControllerKey1.h"

using namespace std;

class Pacman : public GamePawn
{
protected:
	GameObjectType returType() { return PACMAN; }
public:
	//Constructores y destructores
	Pacman(Tile* _tile, Texture* _textura);
	~Pacman() {};

	void setTileActual(Tile* _tileNuevo) override;

	// Metodos varios
	void update();
	// Renderizar imagen pacman
	void render() override;
	//void update();
	void deleteGameObject() override;

};