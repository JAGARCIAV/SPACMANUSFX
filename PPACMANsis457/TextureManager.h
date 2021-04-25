#pragma once
#include <iostream>
#include <string>
#include "Texture.h"

using namespace std;

class TextureManager
{
protected:
	//numero de animaciones
	int numeroFrame;
	int contadorFrames;
	//const int framesMovimiento = 2;

	int posicionXEnTextura;
	int posicionYEnTextura;


public:
	TextureManager(int _numeroFrame, int _contadorFrames, int _posicionXEnTextura, int _posicionYEnTextura);
	//metodos accesores
	//int getnumeroFrame() { return ; }
	//int getcontadorFrames() { return contadorFrames; }
	//int getposicionXEnTextura() { return posicionXEnTextura; }
	//int getposicionYEnTextura() { return posicionYEnTextura; }

	//void setnumeroFrame(int _numeroFrame) { numeroFrame = _numeroFrame; }
	//void setcontadorFrames(int _contadorFrames) { contadorFrames = _contadorFrames; }
	//void setposicionXEnTextura(int _posicionXEnTextura) { posicionXEnTextura = _posicionXEnTextura; }
	//void setposicionYEnTextura(int _posicionYEnTextura) { posicionYEnTextura = _posicionYEnTextura; }

	////renderisador de imagen
	//void render();
	////textura
	//void update();







	virtual void render();
	virtual void move() {};
	virtual void update() { /*No se hace nada*/ };
	virtual void mostrar() {};
};
