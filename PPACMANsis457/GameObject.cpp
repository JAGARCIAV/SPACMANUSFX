#include "GameObject.h"

int GameObject::numeroObjetosCreados = 0;

GameObject::GameObject(int _posicionX, int _posicionY, int _ancho, int _alto, int _anchoPantalla, int _altoPantalla) {
	posicionX = _posicionX;
	posicionY = _posicionY;
	ancho = _ancho;
	alto = _alto;
	anchoPantalla = _anchoPantalla;
	altoPantalla = _altoPantalla;
	visible = true;
	numeroObjetosCreados++;
	idObjeto = numeroObjetosCreados;
}

void GameObject::render() {};