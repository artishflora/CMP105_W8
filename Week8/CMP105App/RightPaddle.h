#pragma once
#include "Framework/GameObject.h"
class RightPaddle :
	public GameObject
{
	private:
		sf::RenderWindow* window;

	public:
		RightPaddle();
		~RightPaddle();

		void handleInput(float dt) override;
		void getWindow(sf::RenderWindow* win);
		void resetPosition();
};

