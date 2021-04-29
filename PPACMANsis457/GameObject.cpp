#include "GameObject.h"

int GameObject::numeroObjetosCreados = 0;

GameObject::GameObject(Texture* _texture, int _posicionX, int _posicionY, int _ancho, int _alto,
	int _anchoPantalla, int _altoPantalla, int _numeroFrame, int _contadorFrames) {
	posicionX = _posicionX;
	posicionY = _posicionY;
	ancho = _ancho;
	alto = _alto;
	anchoPantalla = _anchoPantalla;
	altoPantalla = _altoPantalla;
	visible = true;
	numeroObjetosCreados++;
	idObjeto = numeroObjetosCreados;
	
	numeroFrame = _numeroFrame;
	contadorFrames = _contadorFrames;
}

void GameObject::render()

{
	SDL_Rect renderQuad = { 25 * numeroFrame, 50, ancho, alto };

	//Render to screen
	texture->render(posicionX, posicionY, &renderQuad);
};