#pragma once
#include "ScenePlay.h"

class Player {

private:

	//sprite
	int PosX;
	int PosY;
	int speed;
	int numPlayer;
	int lives;
	bool status;
	bool canBomb;
	bool hasPowerup;
	int score;
	void setbomb(int PosX, int PosY);
	void ThrowBomb(); //controls player 1 i player 2
	void GetHit();

	

};
