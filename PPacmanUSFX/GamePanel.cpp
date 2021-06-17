#include "GamePanel.h"

GamePanel::GamePanel(Texture* _texturaGamePanel, int _posicionX, int _posicionY)
	:GameObject(_texturaGamePanel, _posicionX, _posicionY)
{
	type = " SCORE :";
}

void GamePanel::render()
{
	TTF_Font* fuente = TTF_OpenFont("LanterosySansSerifFont.ttf", 30);
	SDL_Color colorFuente = { 155,222,50 };
	textura->loadFromRenderedText(fuente, type, colorFuente);
	SDL_Rect* cuadroTexto = new SDL_Rect({ 0,0,textura->getAncho(),textura->getAlto() });
	textura->render(posicionX, posicionY, cuadroTexto);
}

