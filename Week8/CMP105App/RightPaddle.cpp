#include "RightPaddle.h"

RightPaddle::RightPaddle(sf::RenderWindow* win, int sizex, int sizey)
{
	window = win;
	setPosition(window->getSize().x - 100, window->getSize().y / 2 - (sizey / 2));
	setSize(sf::Vector2f(sizex, sizey));
}

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