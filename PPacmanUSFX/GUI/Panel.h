#pragma once
#include "../GUI/Component.h"
#include<iostream>
using namespace std;

class Panel :
    public Component
{

protected:
	SDL_Renderer* renderer = nullptr;
	
	SDL_Rect* panel;
	SDL_Color* panelSDLColor;
	int panelColorR;
	int panelColorG;
	int panelColorB;
	int panelColorA;

	SDL_Rect* etiqueta;
	string etiquetaTexto;

	string etiquetaTexto2;
	string etiquetaTexto3;
	string etiquetaTexto4;

	TTF_Font* etiquetaFuente;
	int etiquetaTamanoFuente;
	SDL_Color* etiquetaSDLColor;
	int etiquetaColorR;
	int etiquetaColorG;
	int etiquetaColorB;
	int etiquetaColorA;

	bool revisarActividadMouse;
	bool clickedOn;
public:
	//Constructores y destructores
	Panel(SDL_Renderer* _renderer, int _posicionX, int _posicionY, int _ancho, int _alto, std::string _nombre);
	~Panel() {};

	//Metodos accesores
	int getPanelX() { return panel->x; }
	int getPanelY() { return panel->y; }
	int getPanelW() { return panel->w; }
	int getPanelH() { return panel->h; }
	SDL_Color* getPanelSDLColor() { return panelSDLColor; }
	int getPanelColorR() { return panelColorR; }
	int getPanelColorG() { return panelColorG; }
	int getPanelColorB() { return panelColorB; }
	int getPanelColorA() { return panelColorA; }

	int getEtiquetaX() { return etiqueta->x; }
	int getEtiquetaY() { return etiqueta->y; }
	int getEtiquetaW() { return etiqueta->w; }
	int getEtiquetaH() { return etiqueta->h; }
	string getEtiquetaTexto() { return etiquetaTexto; }
	TTF_Font* getEtiquetaFuente() { return etiquetaFuente; }
	int getEtiquetaTamanoFuente() { return etiquetaTamanoFuente; }
	SDL_Color* getEtiquetaSDLColor() {return etiquetaSDLColor; }
	int getEtiquetaColorR() { return etiquetaColorR; }
	int getEtiquetaColorG() { return etiquetaColorG; }
	int getEtiquetaColorB() { return etiquetaColorB; }
	int getEtiquetaColorA() { return etiquetaColorA; }

	bool getRevisarActividadMouse() { return revisarActividadMouse; }
	bool getClickedOn() { return clickedOn; }

	void setPanelX(int _x) { panel->x = _x; }
	void setPanelY(int _y) { panel->y = _y; }
	void setPanelW(int _w) { panel->w = _w; }
	void setPanelH(int _h) { panel->h = _h; }
	void setPanelSDLColor(SDL_Color* _panelSDLColor) { panelSDLColor = _panelSDLColor; }
	void setPanelColorR(int _r) { panelColorR = _r; }
	void setPanelColorG(int _g) { panelColorG = _g; }
	void setPanelColorB(int _b) { panelColorB = _b; }
	void setPanelColorA(int _a) { panelColorA = _a; }
	void setPanelColorRGBA(int _r, int _g, int _b, int _a);

	void setEtiquetaX(int _x) { etiqueta->x = _x; }
	void setEtiquetaY(int _y) { etiqueta->y = _y; }
	void setEtiquetaW(int _w) { etiqueta->w = _w; }
	void setEtiquetaH(int _h) { etiqueta->h = _h; }
	void setEtiquetaTexto(string _etiquetaTexto) { etiquetaTexto = _etiquetaTexto; }
	void setEtiquetaFuente(TTF_Font* _etiquetaFuente) { etiquetaFuente = _etiquetaFuente; }
	void setEtiquetaTamanoFuente(int _etiquetaTamanoFuente) { etiquetaTamanoFuente = _etiquetaTamanoFuente; }
	void setEtiquetaSDLColor(SDL_Color* _etiquetaSDLColor) { etiquetaSDLColor = _etiquetaSDLColor; }
	void setEtiquetaColorR(int _r) { etiquetaColorR = _r; }
	void setEtiquetaColorG(int _g) { etiquetaColorG = _g; }
	void setEtiquetaColorB(int _b) { etiquetaColorB = _b; }
	void setEtiquetaColorA(int _a) { etiquetaColorA = _a; }
	void setEtiquetaColorRGBA(int _r, int _g, int _b, int _a);
	void setRevisarActividadMouse(bool _revisarActividadMouse) { revisarActividadMouse = _revisarActividadMouse; }
	void setClickedOn(bool _clickedOn) { clickedOn = _clickedOn; }
	
	// Metodos varios
	SDL_Rect* getPanelSDLRect() { return panel; }
	SDL_Rect* getEtiquetaSDLRect() { return etiqueta; }

	bool mouseDentroLimites();
	void onClickButton();
	//virtual void renderText(TTF_Font* _fuente, std::string _texto, SDL_Color* _colorTexto);
	SDL_Texture* SDLTextureFromRect(SDL_Rect* _rect, SDL_Color* _panelColor, SDL_TextureAccess = SDL_TEXTUREACCESS_STREAMING);
	SDL_Texture* SDLTextureFromText(TTF_Font* _fuente, string _texto, SDL_Color* _colorTexto);


	void add(Component*) {}
	void remove(Component*) {}
	virtual void render();
	virtual void update();
	virtual void handleEvent(SDL_Event* event);
	virtual void deleteGameObject();
};
