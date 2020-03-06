#pragma once
#include "Framework/GameObject.h"
class LeftPaddle :
	public GameObject
{
	private:
		sf::RenderWindow* window;
		
	public:
		LeftPaddle();
		~LeftPaddle();

		void handleInput(float dt) override;
		void getWindow(sf::RenderWindow* win);
		void resetPosition();
};

