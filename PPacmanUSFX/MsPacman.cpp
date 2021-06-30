#include "MsPacman.h"

MsPacman::MsPacman(Tile* _tile, Texture* _textura) :Pacman(_tile, _textura)
{
	gamePawnController = new GamePawnControllerKey2();
}
