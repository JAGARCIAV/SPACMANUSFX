#include "ParedClasicoAdapter.h"

ParedClasicoAdapter::ParedClasicoAdapter(Tile* _tile, Texture* _paredTextura, int _posicionX, int _posicionY):
	Pared(_tile, _paredTextura, _posicionX, _posicionY), Wall(_tile, _paredTextura)
{
	Wall::CreateClips();
}
