#include "Moneda.h"

Moneda::Moneda(SDL_Renderer* _renderer, SDL_Texture* _monedaTexture, int _posicionX, int _posicionY, int _ancho, int _alto, int _anchoPantalla, int _altoPantalla) :
	GameObject(_posicionX, _posicionY, _ancho, _alto, _anchoPantalla, _altoPantalla)
{
	// Inicializa propiedade de de pacman
	valor = 1;
	tipoPoderMoneda = PODER_MONEDA_NINGUNO;
	tiempoPoderMoneda = 0;
	renderer = _renderer;
	monedaTexture = _monedaTexture;
}

void Moneda::render() {
	SDL_Rect renderQuad = { getPosicionX(), getPosicionY(), getAncho(), getAlto() };

	//Render to screen
	SDL_RenderCopyEx(renderer, monedaTexture, NULL, &renderQuad, 0.0, NULL, SDL_FLIP_NONE);
}
