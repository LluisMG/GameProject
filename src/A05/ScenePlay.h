#pragma once
#include "Scene.h"

class ScenePlay :
	public Scene
	 {
	public:
		ScenePlay();
		
		void EventHandle();
		void Update();
		void Draw();
		
			~ScenePlay();
		};
