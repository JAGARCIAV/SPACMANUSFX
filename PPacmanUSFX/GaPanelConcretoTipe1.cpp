#include "GaPanelConcretoTipe1.h"


//Constructor
GaPanelConcretoTipe1::GaPanelConcretoTipe1(Texture* _texturaGamePanel, int _posicionX, int _posicionY) :
	GamePanel(_texturaGamePanel, _posicionX, _posicionY)
{
	type = "Type1";

}


GamePanel* GaPanelConcretoTipe1::Clonar()
{
	return new GaPanelConcretoTipe1(*this);
}