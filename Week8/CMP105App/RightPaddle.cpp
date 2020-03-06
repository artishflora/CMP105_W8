#include "RightPaddle.h"

RightPaddle::RightPaddle()
{
}

RightPaddle::~RightPaddle()
{

}

void RightPaddle::handleInput(float dt)
{
	int mousey = input->getMouseY();
	if (((mousey - getSize().y / 2) > 0) || ((mousey + getSize().y / 2) < window->getSize().y)) setPosition(getPosition().x, mousey-(getSize().y/2));
}

void RightPaddle::getWindow(sf::RenderWindow* win)
{
	window = win;
}

void RightPaddle::resetPosition()
{
	setPosition(window->getSize().x - 100, window->getSize().y / 2 - (getSize().y / 2));
}