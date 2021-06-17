#include "GaPanelConcretoTipe2.h"

GaPanelConcretoTipe2::GaPanelConcretoTipe2(Texture* _texturaGamePanel, int _posicionX, int _posicionY) :
	GamePanel(_texturaGamePanel, _posicionX, _posicionY)

{
	setTextoTipo("GamePanelTipo2 SCORE N1:");
}

GamePanel* GaPanelConcretoTipe2::Clonar()
{
	return new GaPanelConcretoTipe2(*this);
}