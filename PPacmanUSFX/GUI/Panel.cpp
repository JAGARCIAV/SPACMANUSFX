#include "Panel.h"
#include "Panel.h"


Panel::Panel(SDL_Renderer* _renderer, int _posicionX, int _posicionY, int _ancho, int _alto, string _nombre){
    renderer = _renderer;
    panel = new SDL_Rect({ _posicionX, _posicionY, _ancho, _alto });
	nombre = _nombre;

    panelSDLColor = new SDL_Color({ 155, 25, 255});
    setPanelColorRGBA(255, 255, 255, 255);
    etiqueta = new SDL_Rect({ _posicionX + 1, _posicionY + 1, _ancho, _alto });
    etiquetaTamanoFuente = 10;

    etiquetaTexto = " |||||||||||||||||||||||| ";

    etiquetaFuente = TTF_OpenFont("Resources/Fuentes/BarlowCondensed-Bold.ttf", etiquetaTamanoFuente);
    etiquetaSDLColor = new SDL_Color({ 89, 253, 11});
    setEtiquetaColorRGBA(20, 120, 220, 250);
    revisarActividadMouse = true;
    clickedOn = false;


}

//Color Panel::get_panel_color()


void Panel::handleEvent(SDL_Event* event)
{
    if (event->type == SDL_MOUSEBUTTONDOWN && !clickedOn)
        clickedOn = true;
    if (event->type == SDL_MOUSEBUTTONUP && clickedOn)
        clickedOn = false;
}

void Panel::deleteGameObject()
{
	GameObject::deleteGameObject();
}

void Panel::setPanelColorRGBA(int _r, int _g, int _b, int _a)
{
    if (_r > 255 || _r < 0)
        _r %= 255;
    if (_g > 255 || _g < 0)
        _g %= 255;
    if (_b > 255 || _b < 0)
        _b %= 255;
    if (_a > 255 || _a < 0)
        _a %= 255;

    panelColorR = _r;
    panelColorG = _g;
    panelColorB = _b;
    panelColorA = _a;
}

void Panel::setEtiquetaColorRGBA(int _r, int _g, int _b, int _a)
{
    if (_r > 255 || _r < 0)
        _r %= 255;
    if (_g > 255 || _g < 0)
        _g %= 255;
    if (_b > 255 || _b < 0)
        _b %= 255;
    if (_a > 255 || _a < 0)
        _a %= 255;

    etiquetaColorR = _r;
    etiquetaColorG = _g;
    etiquetaColorB = _b;
    etiquetaColorA = _a;
}

bool Panel::mouseDentroLimites()
{
	int mouse_x;
	int mouse_y;
	SDL_GetMouseState(&mouse_x, &mouse_y);
	return (((mouse_x >= panel->x) && (mouse_x <= (panel->x + panel->w))) &&
		((mouse_y >= panel->y) && (mouse_y <= (panel->y + panel->h))));
}

void Panel::render()
{
    SDL_SetRenderDrawColor(renderer, panelColorR, panelColorG, panelColorB, panelColorA);
    //SDL_RenderDrawRect(renderer, panel);
    SDL_RenderFillRect(renderer, panel);
    SDL_Texture* etiquetaTextura = SDLTextureFromText(etiquetaFuente, etiquetaTexto, etiquetaSDLColor);
    SDL_Rect* cuadroTexto = new SDL_Rect({ 0, 0, etiqueta->w, etiqueta->h });
    SDL_SetRenderDrawColor(renderer, etiquetaColorR, etiquetaColorG, etiquetaColorB, etiquetaColorA);
    double angle = 0.0;
    SDL_Point* center = nullptr;
    SDL_RendererFlip renderFlip = SDL_FLIP_NONE;
    SDL_RenderCopyEx(renderer, etiquetaTextura, cuadroTexto, etiqueta, angle, center, renderFlip);
}

SDL_Texture* Panel::SDLTextureFromRect(SDL_Rect* _rect, SDL_Color* _panelColor, SDL_TextureAccess _access)
{
    SDL_Texture* textureRect = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888, _access, _rect->w, _rect->h);
    if (textureRect == NULL)
    {
        printf("Unable to create blank texture! SDL Error: %s\n", SDL_GetError());
    }
    // Set width and height of the texture
    return textureRect;
}

SDL_Texture* Panel::SDLTextureFromText(TTF_Font* _fuente, string _texto, SDL_Color* _colorTexto)
{
    // Return if the renderer was not set
    if (renderer == nullptr)
        return nullptr;

    // Render the text using SDL_ttf library
    SDL_Surface* loadedSurface = TTF_RenderText_Solid(_fuente, _texto.c_str(),  *_colorTexto);

    if (loadedSurface == nullptr) {
        std::cout << "Unable to render text! SDL_ttf Error: " << TTF_GetError() << endl;
        return nullptr;
    }

    // Create a texture from generated surface
    SDL_Texture* textura = SDL_CreateTextureFromSurface(renderer, loadedSurface);
    if (textura == nullptr) {
        cout << "Unable to create texture from surface!SDL Error : " << SDL_GetError() << endl;
        return nullptr;
    }

    // Set width and height of the texture
    etiqueta->w = loadedSurface->w;
    etiqueta->h = loadedSurface->h;

    // Free the surface
    SDL_FreeSurface(loadedSurface);
    return textura;
}

void Panel::update()
{
    if (getRevisarActividadMouse() && mouseDentroLimites() && clickedOn) {

        std::cout << getNombre() << ": CLICKED" << std::endl;
        // Insert button action here (below)
        if (getNombre() == "BUTTON A") {
            onClickButton();
        }
        // ...
        clickedOn = false;
    }
}


void Panel::onClickButton()
{
    std::cout << "BUTTON A: FUNCTION ACTIVATED!" << std::endl;
}

