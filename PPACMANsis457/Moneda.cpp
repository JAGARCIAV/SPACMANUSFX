#include "stdio.h"

#include "Moneda.h"


Moneda::Moneda(Texture* _texture, int _posicionX, int _posicionY, int _ancho, int _alto, int _anchoPantalla, int _altoPantalla) :
	GameObject(_posicionX, _posicionY, _ancho, _alto, _anchoPantalla, _altoPantalla)
{
	// Inicializa propiedade de de pacman
	valor = 1;
	tipoPoderMoneda = PODER_MONEDA_NINGUNO;
	tiempoPoderMoneda = 0;
	//renderer = _renderer;
	//monedaTexture = _monedaTexture;
	texture = _texture;
	numeroFrame = 0;
	contadorFrames = 0;

}

//void Moneda::render(){
//	SDL_Rect renderQuad = { getPosicionX(), getPosicionY(), getAncho(), getAlto() };
//
//	//Render to screen
//	SDL_RenderCopyEx(renderer, monedaTexture, NULL, &renderQuad, 0.0, NULL, SDL_FLIP_NONE);
//}
void Moneda::render()
{
	SDL_Rect renderQuad = { 25 * numeroFrame, 25, ancho, alto };

	//Render to screen
	texture->render(posicionX, posicionY, &renderQuad);
}

void Moneda::update() {
	contadorFrames++;
	numeroFrame = contadorFrames / 8;

	if (numeroFrame > framesMovimiento - 1) {
		numeroFrame = 0;
		contadorFrames = 0;
	}

}