#pragma once
#include <iostream>
#include <string>
#include <algorithm>

#include <SDL.h>

#include "GameObject.h"
#include "Texture.h"
#include "Tile.h"
#include "TileGraph.h"
#include "Moneda.h"
#include "Fantasma.h"
#include "Fruta.h"
#include "MoveDirection.h"
#include "TextureManager.h" 

using namespace std;

class Pacman : public GameObject
{
private:
	//PROPIEDADES

	Tile* tileActual;
	Tile* tileSiguiente;

	MoveDirection direccionActual;
	MoveDirection direccionSiguiente;

	// Velocidad en eje X e Y
	int velocidadX;
	int velocidadY;

	// Velocidad a la que mueve el fantasma en cualquier eje
	int velocidadPatron;

	int posicionXEnTextura;
	int posicionYEnTextura;

	int vida;
	int portal;
	

public:
	//METODOS 

	//Constructores y destructores
	Pacman(Tile* _tile, Texture* _texturaPacman, int _posicionX, int _posicionY, int _ancho, int _alto, int _anchoPantalla, int _altoPantalla, int _velocidadPatron);
	~Pacman();

	static const int Width = 25;
	static const int Height = 25;


	//Metodos accesores
	int getVelocidadX() { return velocidadX; }
	int getVelocidadY() { return velocidadY; }
	int getVelocidadPatron() { return velocidadPatron; }
	Tile* getTile() { return tileActual; }
	Tile* getTileSiguiente() { return tileSiguiente; }
	int getVida() { return vida; }

	int getPortales() { return portal; }


	// Mark the object to be deleted
	//void Delete();
	void setVelocidadX(int _velocidadX) { velocidadX = _velocidadX; }
	void setVelocidadY(int _velocidadY) { velocidadY = _velocidadY; }
	void setVelocidadPatron(int _velocidadPatron) { velocidadPatron = _velocidadPatron; }
	void setTile(Tile* _tileNuevo);
	void setTileSiguiente(Tile* _tileSiguienteNuevo) { tileSiguiente = _tileSiguienteNuevo; }
	void setVida(int _vida) { vida = _vida; }
	void setPortales(int _portal) { portal = _portal; }




	// Metodos varios
	bool tratarDeMover(MoveDirection _direccionNueva);
	//vida del pacman
	void RestarVida();
	//portales atajos
	void PortalesXY();

	// Manejador de eventos de pacman
	void handleEvent(SDL_Event* event) override;


	// Actualiza la posición y comprueba la colisión.
	void update() override;


	// Renderizar imagen pacman
	void render() override;

	//void Muerte() override;

	// Marque el objeto a eliminar
	void Delete()override;

	// Devuelve la ficha de pacman
	Tile* GetTile();

};

