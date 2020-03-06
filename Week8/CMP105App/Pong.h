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
		Pong(sf::RenderWindow *win, int sizex, int size);
		Pong();
		~Pong();

		void update(float dt) override;
		void velocityChanger();
};

