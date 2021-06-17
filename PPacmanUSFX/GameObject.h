#pragma once
#include <iostream>
#include <string>
#include "Texture.h"

using namespace std;

class TileGraph;

class GameObject//de aqui desienden las clases
{
public:
	string nombre;
	static TileGraph* tileGraph;
	static int numeroObjetosCreados;

protected:
	// Posicion en el eje X y Y
	int idObjeto;
	int posicionX;
	int posicionY;

	// Ancho y Alto de la imagen del objeto en pixeles
	int ancho;
	int alto;



	// Si el objeto es visible
	bool visible;
	bool eliminar;
	bool enMovimiento;

	// Textura para representacion grafica del objeto
	Texture* textura;

	int numeroFrame;
	int contadorFrames;
	int framesMovimiento;

	//propiedades de borrar
	bool toDelete;

	//propiedad de colision
	SDL_Rect* collider;

public:

	GameObject();

	//Constructores y destructores
	GameObject(Texture* _textura, int _posicionX, int _posicionY);
	virtual ~GameObject();

	//Metodos accesores
	int getIdObjeto() { return idObjeto; }
	int getPosicionX() { return posicionX; }
	int getPosicionY() { return posicionY; }
	int getAncho() { return ancho; }
	int getAlto() { return alto; }
	bool getVisible() { return visible; }
	bool getEliminar() { return eliminar; }
	bool getEnMovimiento() { return enMovimiento; }

	void setPosicionX(int _posicionX) { posicionX = _posicionX; }
	void setPosicionY(int _posicionY) { posicionY = _posicionY; }
	void setAncho(int _ancho) { ancho = _ancho; }
	void setAlto(int _alto) { alto = _alto; }
	void setVisible(bool _visible) { visible = _visible; }
	void setEliminar(bool _eliminar) { eliminar = _eliminar; }
	//void eliminarGameObject() { eliminar = true; }
	void setEnMovimiento(bool _enMovimiento) { enMovimiento = _enMovimiento; }

	// Metodos varios
	void setParametrosAnimacion(int _framesMovimiento) { framesMovimiento = _framesMovimiento; }

	// Renderizar imagen
	virtual void handleEvent(SDL_Event* event) {};
	virtual void render();
	virtual void update();
	//virtual void Muerte();

	//Liberar espacio
	virtual void free();


	//colisionador
	virtual SDL_Rect* getColisionador() { return  collider; }
	bool CheckForCollision(const SDL_Rect* otherCollider);
	bool CheckForCollision(const SDL_Rect* collider, const SDL_Rect* otherCollider);

	// Marque el objeto a eliminar
	virtual void Delete();

	// Devuelve verdadero si los objetos est�n marcados para su eliminaci�n
	bool ToDelete() const;

	//static bool AvoidInPathFinder(Tile* _tile);

	//PATRON ADAPTER DE WALL
	void Free() { free(); }
};