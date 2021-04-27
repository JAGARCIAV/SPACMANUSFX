#include "Pared.h"

Pared::Pared(Texture* _paredTexture, int _posicionX, int _posicionY, int _ancho, int _alto,
	int _anchoPantalla, int _altoPantalla, int _numeroFrame, int _contadorFrames) :
	GameObject( _paredTexture,_posicionX, _posicionY, _ancho, _alto, _anchoPantalla, _altoPantalla, _numeroFrame,  _contadorFrames)

{
	// Inicializa propiedade de de pacman
	valor = 1;
	//tipoPoderMoneda = PODER_MONEDA_NINGUNO;
	//tiempoPoderMoneda = 0;
	paredTexture = _paredTexture;
}

//void Pared::render() {
//	//SDL_Rect renderQuad = { getPosicionX(), getPosicionY(), getAncho(), getAlto() };
//
//	////Render to screen
//	//SDL_RenderCopyEx(renderer, monedaTexture, NULL, &renderQuad, 0.0, NULL, SDL_FLIP_NONE);
//
//	SDL_Rect renderQuad = { 0, 0, getAncho(), getAlto() };
//
//	//Render to screen
//	paredTexture->render(getPosicionX(), getPosicionY(), &renderQuad);
//	//SDL_RenderCopyEx(renderer, fantasmaTexture, NULL, &renderQuad, 0.0, NULL, SDL_FLIP_NONE);
//}
