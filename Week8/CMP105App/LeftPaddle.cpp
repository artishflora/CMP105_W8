#include "LeftPaddle.h"

LeftPaddle::LeftPaddle(sf::RenderWindow* win, int sizex, int sizey)
{
	window = win;
	setPosition(100, window->getSize().y / 2 - (sizey / 2));
	setSize(sf::Vector2f(sizex, sizey));
}

LeftPaddle::LeftPaddle()
{

}

LeftPaddle::~LeftPaddle()
{

}

void LeftPaddle::handleInput(float dt)
{
	if (getPosition().y <= 0);
	else if (input->isKeyDown(sf::Keyboard::W)) setPosition(getPosition().x, getPosition().y - 300*dt);
	if (getPosition().y >= window->getSize().y - getSize().y);
	else if (input->isKeyDown(sf::Keyboard::S)) setPosition(getPosition().x, getPosition().y + 300*dt);
}
