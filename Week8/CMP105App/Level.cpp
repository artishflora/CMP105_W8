#include "Level.h"

Level::Level(sf::RenderWindow* hwnd, Input* in)
{
	window = hwnd;
	input = in;

	// initialise game objects
	bowl.loadFromFile("gfx/Beach_Ball.png");
	beachBall.setSize(sf::Vector2f(100, 100));
	beachBall.setPosition(0, 300);
	beachBall.setTexture(&bowl);
	//beachBall.setCollisionBox(0, 0, 100, 100);
	beachSpeed = sf::Vector2f(100, 0);

	beetchBoll.setSize(sf::Vector2f(100, 100));
	beetchBoll.setPosition(700, 300);
	//beetchBoll.setCollisionBox(0, 0, 100, 100);
	beetchBoll.setTexture(&bowl);
	beetchSpeed = sf::Vector2f(-100, 0);

	collided = false;
}

Level::~Level()
{

}

// handle user input
void Level::handleInput(float dt)
{

}

// Update game objects
void Level::update(float dt)
{
	beachBall.setPosition(beachBall.getPosition() + (beachSpeed * dt));
	beetchBoll.setPosition(beetchBoll.getPosition() + (beetchSpeed * dt));
	/*if ((thisCollision.checkBoundingBox(&beachBall, &beetchBoll)) && (!collided))
	{
		collided = true;
		beachSpeed = sf::Vector2f((beachSpeed.x * -1), beachSpeed.y);
		beetchSpeed = sf::Vector2f((beetchSpeed.x * -1), beetchSpeed.y);
	}*/
	if ((thisCollision.checkBoundingCircle(&beachBall, &beetchBoll)) && (!collided))
	{
		collided = true;
		beachSpeed = sf::Vector2f((beachSpeed.x * -1), beachSpeed.y);
		beetchSpeed = sf::Vector2f((beetchSpeed.x * -1), beetchSpeed.y);
	}
}

// Render level
void Level::render()
{
	beginDraw();

	window->draw(beachBall);
	window->draw(beetchBoll);

	endDraw();
}

// Begins rendering to the back buffer. Background colour set to light blue.
void Level::beginDraw()
{
	window->clear(sf::Color(100, 149, 237));
}

// Ends rendering to the back buffer, and swaps buffer to the screen.
void Level::endDraw()
{
	window->display();
}