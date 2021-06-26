#pragma once
#include<vector>
#include<iostream>
#include<string>
#include <fstream>

#include "Texture.h"
#include "TileGraph.h"
#include "MazeObject.h"

using namespace std;


class Laberinto
{
private:
	vector<MazeObject*> vectorMazeObjects;
	Texture* fondosuperficie;
	TileGraph* tileGraph;
public:
	bool load(string path);

};

