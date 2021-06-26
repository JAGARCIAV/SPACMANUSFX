#pragma once
#include "GameObject.h"
#include "Tile.h"
#include "MoveDirection.h"
#include "TileGraph.h"
#include "AnimationFrames.h"

class GameActor :
    public GameObject
{
private:
protected:
	//Posicion x, y en la textura de ventana principal
	int posicionX;
	int posicionY;

	// Ancho y Alto de la imagen del objeto en pixeles
	int ancho;
	int alto;

	bool solido;
	bool indestructible;
	bool visible;
	bool movil;
	bool enMovimiento;

	int velocidad;
	int energia;
	int vidas;

	// Representacion grafica del objeto
	Texture* textura;
	AnimationFrames* framesAnimacion;

	Tile* tileActual;
	Tile* tileSiguiente;

	MoveDirection direccionActual;
	MoveDirection direccionSiguiente;

	int numeroFrame;
	int contadorFrames;
	int framesDireccion;

	SDL_Rect* colisionador;

public:
	// Propiedades
	static TileGraph* tileGraph;

	//Constructores & destructores
	GameActor();
	GameActor(Texture* _textura);
	~GameActor();

	// Metodos accesores
	int getPosicionX() { return posicionX; }
	int getPosicionY() { return posicionY; }
	int getAncho() { return ancho; }
	int getAlto() { return alto; }
	bool getSolido() { return solido; }
	bool getIndestructible() { return indestructible; }
	bool getVisible() { return visible; }
	bool getMovil() { return movil; }
	bool getEnMovimiento() { return enMovimiento; }
	int getVelocidad() { return velocidad; }
	int getEnergia() { return energia; }
	int getVidas() { return vidas; }
	Texture* getTextura() { return textura; }
	AnimationFrames* getFramesAnimacion() { return framesAnimacion; }
	Tile* getTileActual() { return tileActual; }
	Tile* getTileSiguiente() { return tileSiguiente; }
	MoveDirection getDireccionActual() { return direccionActual; }
	MoveDirection getDireccionSiguiente() { return direccionSiguiente; }
	int getframesDireccion() { return framesDireccion; }
	SDL_Rect* getColisionador() { return colisionador; }

	void setPosicionX(int _posicionX) { posicionX = _posicionX; }
	void setPosicionY(int _posicionY) { posicionY = _posicionY; }
	void setAncho(int _ancho) { ancho = _ancho; }
	void setAlto(int _alto) { alto = _alto; }
	void setSolido(bool _solido) { solido = _solido; }
	void setIndestructible(bool _indestructible) { indestructible = _indestructible; }
	void setVisible(bool _visible) { visible = _visible; }
	void setMovil(bool _movil) { movil = _movil; }
	void setEnMovimiento(bool _enMovimiento) { enMovimiento = _enMovimiento; }
	void setVelocidad(int _velocidad) { velocidad = _velocidad; }
	void setEnergia(int _energia) { energia = _energia; }
	void setVidas(int _vidas) { vidas = _vidas; }
	void setTextura(Texture* _textura) { textura = _textura; }
	void setFramesAnimacion(AnimationFrames* _framesAnimacion) { framesAnimacion = _framesAnimacion; }
	virtual void setTileActual(Tile* _tileNuevo) = 0;
	void setTileSiguiente(Tile* _tileSiguiente) { tileSiguiente = _tileSiguiente; }
	void setDireccionActual(MoveDirection _direccionActual) { direccionActual = _direccionActual; }
	void setDireccionSiguiente(MoveDirection _direccionSiguiente) { direccionSiguiente = _direccionSiguiente; }
	void setFramesDireccion(int _framesDireccion) { framesDireccion = _framesDireccion; }
	void setColisionador(SDL_Rect* _colisionador) { colisionador = _colisionador; }
	
	// Metodos varios
	bool revisarColision(const SDL_Rect* _otroColisionador);
	bool revisarColision(const SDL_Rect* _colisionador1, const SDL_Rect* _colisionador2);
	bool tratarDeMover(MoveDirection _direccionNueva);
	int restarEnergia();
	int restarVida();

	//Metodos virtuales, redefinidos o sobrecargados
	virtual void render();
	virtual void update();
	virtual void handleEvent(SDL_Event* event) = 0;
	virtual void deleteGameObject();
};

