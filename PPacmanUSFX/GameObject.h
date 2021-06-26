#pragma once
#include <iostream>
#include <string>
#include "Texture.h"
#include "GameObjectType.h"

using namespace std;

class GameObject
{

private:
	static int numeroObjetosCreados;
	bool eliminar;

protected:
	int idObjeto;
	string nombre;
	GameObjectType tipoObjeto;
	
public:
	//Constructores y destructores
	GameObject();
	~GameObject() {};

	//Metodos accesores
	int getIdObjeto() { return idObjeto; }

	string getNombre() { return nombre; }
	bool getEliminar() { return eliminar; }
	
	void setNombre(string _nombre) { nombre = _nombre; }
	void setEliminar(bool _eliminar) { eliminar = _eliminar; }
	
	// Metodos varios
	virtual void render() = 0;
	virtual void update() = 0;
	virtual void handleEvent(SDL_Event* event) = 0;
	virtual void deleteGameObject() { eliminar = true; }
	virtual void free(){};

	void Delete() { deleteGameObject(); }
	void Free() { free(); }
};

