#pragma once
#include <iostream>
#include <string>
#include "Texture.h"

using namespace std;

class GameObject
{
public:
	string nombre;
protected:
	// Posicion en el eje X y Y
	int idObjeto;
	int posicionX;
	int posicionY;

	// Ancho y Alto de la imagen del objeto en pixeles
	int ancho;
	int alto;

	// Ancho y alto de la pantalla del juego
	int anchoPantalla;
	int altoPantalla;

	// Si el objeto es visible
	bool visible;
	bool eliminar;

	// Textura para representacion grafica del objeto
	Texture* textura;

	int numeroFrame;
	int contadorFrames;
	int framesMovimiento;

	int escudo;

public:
	static int numeroObjetosCreados;

public:
	//Constructores y destructores
	GameObject(Texture* _textura, int _posicionX, int _posicionY, int _ancho, int _alto, int _anchoPantalla, int _altoPantalla);

	//Metodos accesores
	int getIdObjeto() { return idObjeto; }
	int getPosicionX() { return posicionX; }
	int getPosicionY() { return posicionY; }
	int getAncho() { return ancho; }
	int getAlto() { return alto; }
	int getAnchoPantalla() { return anchoPantalla; }
	int getAltoPantalla() { return altoPantalla; }
	bool getVisible() { return visible; }
	int getEscudo() { return escudo; }

	void setPosicionX(int _posicionX) { posicionX = _posicionX; }
	void setPosicionY(int _posicionY) { posicionY = _posicionY; }
	void setAncho(int _ancho) { ancho = _ancho; }
	void setAlto(int _alto) { alto = _alto; }
	void setAnchoPantalla(int _anchoPantalla) { anchoPantalla = _anchoPantalla; }
	void setAltoPantalla(int _altoPantalla) { altoPantalla = _altoPantalla; }
	void setVisible(bool _visible) { visible = _visible; }
	void setEscudo(int _escudo) { escudo = _escudo; }
	// Metodos varios
	virtual void setParametrosAnimacion(int _framesMovimiento) { framesMovimiento = _framesMovimiento; }

	// Renderizar imagen
	virtual void render();
	virtual void update();

	virtual void move() {};
	virtual void mostrar() {};
	virtual void handleEvent(SDL_Event& e) {};
};