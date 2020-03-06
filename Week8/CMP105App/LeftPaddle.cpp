#include "LeftPaddle.h"

LeftPaddle::LeftPaddle()
{
}

LeftPaddle::~LeftPaddle()
{

}

void LeftPaddle::handleInput(float dt)
{
	if (getPosition().y <= 0);
	else if (input->isKeyDown(sf::Keyboard::W)) setPosition(getPosition().x, getPosition().y - 1);
	if (getPosition().y >= window->getSize().y - getSize().y);
	else if (input->isKeyDown(sf::Keyboard::S)) setPosition(getPosition().x, getPosition().y + 1);
}

void LeftPaddle::getWindow(sf::RenderWindow* win)
{
	window = win;
}

void LeftPaddle::resetPosition()
{
	setPosition(100, window->getSize().y / 2 - (getSize().y / 2));
}