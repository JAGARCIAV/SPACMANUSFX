#include "Pared.h"


Pared::Pared(Texture* _paredTextura, int _posicionX, int _posicionY, int _ancho, int _alto, int _anchoPantalla, int _altoPantalla) :

	GameObject(_paredTextura, _posicionX, _posicionY, _ancho, _alto, _anchoPantalla, _altoPantalla)
{

	valor = 1;

}
