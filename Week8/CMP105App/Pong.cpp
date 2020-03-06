#include "Pong.h"
#include <ctime>
#include <cstdlib>

Pong::Pong()
{
	speed = 300.f;
}

Pong::~Pong()
{

}

void Pong::update(float dt)
{
	setPosition(getPosition() + velocity * dt * speed);
	if ((getPosition().y <= 0) || (getPosition().y >= (window->getSize().y - getSize().y))) velocity.y = velocity.y * -1;
	if ((getPosition().x <= 0) || (getPosition().x >= (window->getSize().x - getSize().x)))
	{
		Pong();
		resetPosition();
	}
}

void Pong::velocityChanger()
{
	velocity.x = velocity.x * -1;
}

void Pong::getWindow(sf::RenderWindow* win)
{
	window = win;
}

void Pong::resetPosition()
{ 
	srand(0);
	setPosition(((window->getSize().x / 2) - (getSize().x / 2)), ((window->getSize().y / 2) - (getSize().y / 2)));
	int velx = rand() % 7 + 0;
	int vely = rand() % 3 + 2;
	velocity = sf::Vector2f(velx, vely);
	velocity = vector.normalise(velocity);
}