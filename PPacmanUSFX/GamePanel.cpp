#include "GamePanel.h"

GamePanel::GamePanel(Texture* _texturaGamePanel, int _posicionX, int _posicionY):GameObject(_texturaGamePanel, _posicionX, _posicionY)
{
	texto = "Pacman USFX, solo para universitarios.";
}

void GamePanel::render()
{
	TTF_Font* fuente = TTF_OpenFont("BarlowCondensed-Bold.ttf", 15);
	SDL_Color colorFuente = { 155, 25, 255 };
	textura->loadFromRenderedText(fuente, texto, colorFuente);
	SDL_Rect* cuadroTexto = new SDL_Rect({ 0, 0, textura->getAncho(), textura->getAlto() });
	textura->setColor(24, 56, 255);
	textura->render(posicionX, posicionY, cuadroTexto);
}
