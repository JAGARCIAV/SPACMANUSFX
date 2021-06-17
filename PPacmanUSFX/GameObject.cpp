#include "GameObject.h"

int GameObject::numeroObjetosCreados = 0;
TileGraph* GameObject::tileGraph = nullptr;


GameObject::GameObject() {
	posicionX = 0;
	posicionY = 0;
	alto = 0;
	ancho = 0;
	visible = true;
	eliminar = false;
	enMovimiento = false;
	numeroObjetosCreados++;
	idObjeto = numeroObjetosCreados;
	textura = nullptr;
	numeroFrame = 0;
	contadorFrames = 0;
	framesMovimiento = 1;
	collider = new SDL_Rect({ 0, 0, alto, ancho });
}

GameObject::GameObject(Texture* _textura, int _posicionX, int _posicionY) {
	posicionX = _posicionX;
	posicionY = _posicionY;
	alto = 0;
	ancho = 0;
	visible = true;
	eliminar = false;
	enMovimiento = false;
	numeroObjetosCreados++;
	idObjeto = numeroObjetosCreados;
	textura = _textura;
	numeroFrame = 0;
	contadorFrames = 0;
	framesMovimiento = 1;
	collider = new SDL_Rect({ _posicionX, _posicionY, alto, ancho });
}



void GameObject::render()
{
	SDL_Rect renderQuad = { 25 * numeroFrame, 0, getAncho(), getAlto() };

	// Renderizar en la pantalla
	textura->render(getPosicionX(), getPosicionY(), &renderQuad);
}

//COLISION 1
//comprobacion de que esta colisionando
bool GameObject::CheckForCollision(const SDL_Rect* otherCollider)

{	//otro colisionador.x > colisionador.x + colisionador.w
	if (otherCollider->x > collider->x + collider->w) {
		//printf("1");
		return false;
	}

	if (otherCollider->y > collider->y + collider->h) {
		//printf("2");
		return false;
	}

	if (otherCollider->x + otherCollider->w < collider->x) {
		//printf("3");
		return false;
	}

	if (otherCollider->y + otherCollider->h < collider->y) {
		//printf("4");
		return false;
	}

	return true;
}

//COLISION 2

//comprobando si colisiono, el OtroColisionador
bool GameObject::CheckForCollision(const SDL_Rect* collider, const SDL_Rect* otherCollider)
{
	if (otherCollider->x > collider->x + collider->w) {
		//printf("1");
		return false;
	}

	if (otherCollider->y > collider->y + collider->h) {
		//printf("2");
		return false;
	}

	if (otherCollider->x + otherCollider->w < collider->x) {
		//printf("3");
		return false;
	}

	if (otherCollider->y + otherCollider->h < collider->y) {
		//printf("4");
		return false;
	}

	return true;
}

void GameObject::update() {
	contadorFrames++;
	numeroFrame = contadorFrames / 8;

	if (numeroFrame > framesMovimiento - 1) {
		numeroFrame = 0;
		contadorFrames = 0;
	}

}

void HandleEvent(SDL_Event* event) {};

void GameObject::free() {}

GameObject::~GameObject() {}



//funcion para eliminar clase que contenga delete=borrar
void GameObject::Delete()
{
	eliminar = true;
}
// Devuelve verdadero si los objetos están marcados para su eliminación

bool GameObject::ToDelete() const
{
	return eliminar;
};