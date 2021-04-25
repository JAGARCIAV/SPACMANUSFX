#include "TextureManager.h"

//int TextureObjetc::numeroTextureCreados = 0;

TextureManager::TextureManager(int _numeroFrame, int _contadorFrames, int _posicionXEnTextura, int _posicionYEnTextura) {
	numeroFrame = _numeroFrame;
	contadorFrames = _contadorFrames;
	//framesMovimiento = _framesMovimiento;
	posicionXEnTextura = _posicionXEnTextura;
	posicionYEnTextura = _posicionYEnTextura;

	//	numeroTextureCreados++;
	//	idObjeto = numeroTextureCreados;

}
void TextureManager::render() {};