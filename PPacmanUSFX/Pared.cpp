#include "Pared.h"
SDL_Rect Pared::textureClips[16];

void Pared::CreateClips()
{


	textureClips[0] = { 0, 0, 25, 25 };
	textureClips[DIR_N] = { 25, 0, 25, 25 };
	textureClips[DIR_E] = { 50, 0, 25, 25 };
	textureClips[DIR_S] = { 75, 0, 25, 25 };
	textureClips[DIR_W] = { 0, 25, 25, 25 };
	textureClips[DIR_N | DIR_E] = { 25, 25, 25, 25 };
	textureClips[DIR_S | DIR_E] = { 50, 25, 25, 25 };
	textureClips[DIR_S | DIR_W] = { 75, 25, 25, 25 };
	textureClips[DIR_N | DIR_W] = { 0, 50, 25, 25 };
	textureClips[DIR_N | DIR_S] = { 50, 100, 25, 25 };
	textureClips[DIR_E | DIR_W] = { 75, 100, 25, 25 };
	textureClips[DIR_N | DIR_E | DIR_W] = { 25, 50, 25, 25 };
	textureClips[DIR_N | DIR_E | DIR_S] = { 50, 50, 25, 25 };
	textureClips[DIR_E | DIR_S | DIR_W] = { 75, 50, 25, 25 };
	textureClips[DIR_N | DIR_S | DIR_W] = { 0, 75, 25, 25 };
	textureClips[DIR_N | DIR_E | DIR_S | DIR_W] = { 25, 75, 25, 25 };
}


Pared::Pared(Tile* _tile, Texture* _textura) :
	GameActor(_textura) {


	tileActual = _tile;
	if (tileActual != nullptr) {
		tileActual->setPared(this);

		posicionX = tileActual->getPosicionX() * Tile::anchoTile;
		posicionY = tileActual->getPosicionY() * Tile::altoTile;

		ancho = Tile::anchoTile;
		alto = Tile::altoTile;
	}
	else {
		posicionX = 0;
		posicionY = 0;
	}

	UpdateConnections();

	std::array<Tile*, 4> neighbours = tileGraph->GetNeighbours(this->tileActual);
	for (int i = 0; i < 4; i++) {
		if (CheckForWall(neighbours[i]))
			neighbours[i]->getPared()->UpdateConnections();
	}
};

void Pared::setTileActual(Tile* _tileNuevo) {
	if (tileActual != nullptr)
		tileActual->setPared(nullptr);

	tileActual = _tileNuevo;

	if (tileActual != nullptr) {
		tileActual->setPared(this);

		posicionX = tileActual->getPosicionX() * Tile::anchoTile;
		posicionY = tileActual->getPosicionY() * Tile::altoTile;
	}
	else {
		posicionX = 0;
		posicionY = 0;
	}

};
void Pared::UpdateConnections()
{
	std::array<Tile*, 4> neighbours = tileGraph->GetNeighbours(this->tileActual);

	connections = 0;

	if (CheckForWall(neighbours[0]))
		connections |= DIR_S;
	if (CheckForWall(neighbours[1]))
		connections |= DIR_E;
	if (CheckForWall(neighbours[2]))
		connections |= DIR_N;
	if (CheckForWall(neighbours[3]))
		connections |= DIR_W;
}


void Pared::Render()
{
	textura->Render(posicionX, posicionY, &textureClips[connections]);
}


bool Pared::CheckForWall(Tile* _tile)
{
	if (_tile != nullptr && _tile->getPared() != nullptr)
		return true;

	return false;
}

void Pared::deleteGameObject()
{
	GameObject::deleteGameObject();
	tileActual->setPared(nullptr);
}
