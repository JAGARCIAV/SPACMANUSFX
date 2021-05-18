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
#include "MoveDirection.h"
#include "TextureManager.h" 

using namespace std;

class Pacman : public GameObject
{
private:
	//PROPIEDADES
	
	// Intenta mover el pacman en la dirección deseada
	// Devuelve verdadero si tiene éxito, falso en caso contrario
	//bool TryToMove(MoveDirection direction);

	// Compruebe si pacman está colisionando con otro colisionador
	bool CheckForCollision(const SDL_Rect& otherCollider);

	// Compruebe si el colisionador dado está colisionando con otro colisionador
	bool CheckForCollision(const SDL_Rect& collider, const SDL_Rect& otherCollider);

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


	// Mark the object to be deleted
	//void Delete();
	void setVelocidadX(int _velocidadX) { velocidadX = _velocidadX; }
	void setVelocidadY(int _velocidadY) { velocidadY = _velocidadY; }
	void setVelocidadPatron(int _velocidadPatron) { velocidadPatron = _velocidadPatron; }
	void setTile(Tile* _tileNuevo);
	void setTileSiguiente(Tile* _tileSiguienteNuevo) { tileSiguiente = _tileSiguienteNuevo; }




	// Metodos varios
	bool tratarDeMover(MoveDirection _direccionNueva);
	// Manejador de eventos de pacman
	void handleEvent(SDL_Event* event) override;


	// Actualiza la posición y comprueba la colisión.
	void update() override;


	// Renderizar imagen pacman
	void render() override;

	// Marque el objeto a eliminar
	void Delete();

	// Devuelve la ficha de pacman
	Tile* GetTile();






};



