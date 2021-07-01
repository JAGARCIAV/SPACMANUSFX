#pragma once
#include "GameActor.h"
#include "TipoTexturaPared.h"
#include "TileGraph.h"

enum WorldDirections {
    DIR_N = 1 << 0,
    DIR_E = 1 << 1,
    DIR_S = 1 << 2,
    DIR_W = 1 << 3
};

class Pared :
    public GameActor
{
private:
    GameObjectType returType() { return PARED; }
    Texture* textura;
    int connections;
    static SDL_Rect textureClips[16];
    bool CheckForWall(Tile* tile);

public:
    // Creates connection clips
    static void CreateClips();

    Pared(Tile* _tile, Texture* _textura);
    void setTileActual(Tile* _tileNuevo);

    void handleEvent(SDL_Event* event) {};

    void deleteGameObject();
    void UpdateConnections();
    void Render();
};

