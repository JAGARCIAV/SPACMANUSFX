#include "GameObject.h"

int GameObject::numeroObjetosCreados = 0;

GameObject::GameObject() {
	numeroObjetosCreados++;
	idObjeto = numeroObjetosCreados;
	eliminar = false;
}