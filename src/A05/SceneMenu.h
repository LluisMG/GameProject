#pragma once
#include "Scene.h"

class SceneMenu : public Scene {
	public :
	SceneMenu();
	~SceneMenu();

	void EventHandler();
	void Update(float dtime);
	void Draw();
	void MuteGame();


	//text button play level1
	//rect button play level1

	//text button play level2
	//rect button play level2

	//text button seceneRanking
	//rect button senceRanking

	//text button exit
	//rect button exit

	//text button mute
	//rect button mute


};