#pragma once
#include "Constants.h"
#include "Renderer.h"

class Cell {
public:

	SDL_Rect cellRect, selectRect;
	SDL_Rect celRect2, selector;
	int textWidth, textHeight, frameWidth, frameHeight;
	bool destructible;
	Point lloc;

public :

	void InitBlack(int x, int y);
	void AutoDrawBlack();

	void InitGray(int x, int y);
	void AutoDrawGray();

	~Cell();


};