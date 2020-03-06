#include "Pong.h"

Pong::Pong(sf::RenderWindow *win, int sizex, int sizey)
{
	window = win;
	speed = 300.f;
	velocity = sf::Vector2f(rand() % 700 + -700, rand() % 500 + 0);
	velocity = vector.normalise(velocity);
	setSize(sf::Vector2f(sizex, sizey));
	
	setPosition(((window->getSize().x / 2) - (sizex / 2)), ((window->getSize().y / 2) - (sizey / 2)));
}

Pong::Pong()
{

}

Pong::~Pong()
{

}

void Pong::update(float dt)
{
	setPosition(getPosition() + velocity * dt * speed);
	if ((getPosition().y <= 0) || (getPosition().y >= (window->getSize().y - getSize().y))) velocity.y = velocity.y * -1;
	if ((getPosition().x <= 0) || (getPosition().x >= (window->getSize().x - getSize().x))) Pong(window, getSize().x, getSize().y);
}

void Pong::velocityChanger()
{
	velocity.y = velocity.y * -1;
}