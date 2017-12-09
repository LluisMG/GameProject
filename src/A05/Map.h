#pragma once
#include "Cell.h"
#include "Renderer.h"

class Map {

	Cell*map[13][11];

public :

	Map();

	void SetMap();
	void PaintMap();

	~Map();

};