#pragma once
#include "Framework/GameObject.h"
#include "Framework/Vector.h"

class Pong :
	public GameObject
{
	private:
		float speed;
		sf::Vector2f velocity;
		Vector vector;
		sf::RenderWindow* window;

	public:
		Pong();
		~Pong();

		void update(float dt) override;
		void getWindow(sf::RenderWindow* win);
		void resetPosition();
		void velocityChanger();
};

