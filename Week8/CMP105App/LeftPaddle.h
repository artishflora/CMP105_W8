#pragma once
#include "Framework/GameObject.h"
class LeftPaddle :
	public GameObject
{
	private:
		sf::RenderWindow* window;
		
	public:
		LeftPaddle(sf::RenderWindow* win, int sizex, int sizey);
		LeftPaddle();
		~LeftPaddle();

		void handleInput(float dt) override;
};

