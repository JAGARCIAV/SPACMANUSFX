#include "FrutaClasico.h"
using namespace std;
FrutaClasico::FrutaClasico(Tile* _tile, Texture* _frutaTexture, int _posicionX, int _posicionY):
	Fruta(_tile, _frutaTexture, _posicionX, _posicionY){}


void FrutaClasico::update()
{
	if (contadorTiempoVisible >= tiempoVisible) {
		visible = false;
		if (contadorTiempoInvisible >= tiempoInvisible) {
			posicionX = 1 + rand() % 800;
			posicionY = 1 + rand() % 600;
			contadorTiempoVisible = 0;
			contadorTiempoInvisible = 0;
			visible = true;
			//numeroFrutaVisible = rand() % frutasTextures.size();
			numeroFrutaVisible = rand() % 4;
		}
		else {
			contadorTiempoInvisible++;
		}
	}
	else {
		contadorTiempoVisible++;
	}
}

