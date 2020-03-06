#pragma once
#include "Framework/GameObject.h"
class RightPaddle :
	public GameObject
{
	private:
		sf::RenderWindow* window;

	public:
		RightPaddle(sf::RenderWindow* win, int sizex, int sizey);
		RightPaddle();
		~RightPaddle();

		void handleInput(float dt) override;
};

