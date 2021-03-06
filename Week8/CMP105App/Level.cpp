#include "Level.h"
#include <ctime>
#include <cstdlib>

Level::Level(sf::RenderWindow* hwnd, Input* in)
{
	window = hwnd;
	input = in;

	// initialise game objects
	/*bowl.loadFromFile("gfx/Beach_Ball.png");
	beachBall.setSize(sf::Vector2f(100, 100));
	beachBall.setPosition(0, 300);
	beachBall.setTexture(&bowl);
	//beachBall.setCollisionBox(0, 0, 100, 100);
	beachSpeed = sf::Vector2f(200, 0);

	beetchBoll.setSize(sf::Vector2f(100, 100));
	beetchBoll.setPosition(700, 300);
	//beetchBoll.setCollisionBox(0, 0, 100, 100);
	beetchBoll.setTexture(&bowl);
	beetchSpeed = sf::Vector2f(-200, 0);

	collided = false;

	gomba.loadFromFile("gfx/Goomba.png");
	goomBAH.setSize(sf::Vector2f(100, 100));
	goomBAH.setPosition(400, 0);
	goomBAH.setTexture(&gomba);
	goomBAH.setCollisionBox(0, 0, 100, 100);
	bahspeed = sf::Vector2f(0, 300);

	GOOmba.setSize(sf::Vector2f(100, 100));
	GOOmba.setPosition(400, window->getSize().y-GOOmba.getSize().y);
	GOOmba.setCollisionBox(0, 0, 100, 100);
	GOOmba.setTexture(&gomba);
	goospeed = sf::Vector2f(0, -300);

	goomColl = false;
	srand(0);*/

	pongText.loadFromFile("gfx/Beach_Ball.png");
	pong.setTexture(&pongText);
	pong.setSize(sf::Vector2f(70, 70));
	pong.setCollisionBox(0, 0, 70, 70);
	pong.getWindow(window);
	pong.resetPosition();

	leftPaddle.setFillColor(sf::Color::Cyan);
	leftPaddle.setCollisionBox(50, 0, 0, 200);
	leftPaddle.setInput(input);
	leftPaddle.getWindow(window);
	leftPaddle.setSize(sf::Vector2f(50, 200));
	leftPaddle.resetPosition();

	rightPaddle.setFillColor(sf::Color::Magenta);
	rightPaddle.setCollisionBox(0, 0, 0, 200);
	rightPaddle.setInput(input);
	rightPaddle.setSize(sf::Vector2f(50, 200));
	rightPaddle.getWindow(window);
	rightPaddle.resetPosition();

	leftcollided = false;
	rightcollided = false;
}

Level::~Level()
{

}

// handle user input
void Level::handleInput(float dt)
{
	leftPaddle.handleInput(dt);
	rightPaddle.handleInput(dt);
}

// Update game objects
void Level::update(float dt)
{
	/*beachBall.setPosition(beachBall.getPosition() + (beachSpeed * dt));
	beetchBoll.setPosition(beetchBoll.getPosition() + (beetchSpeed * dt));
	if ((thisCollision.checkBoundingCircle(&beachBall, &beetchBoll)) && (!collided))
	{
		collided = true;
		if (beachSpeed.x > 0) beachSpeed.x = rand() % 300 + 150;
		else beachSpeed.x = (rand() % 300 + 150) * -1;
		if (beetchSpeed.x > 0) beetchSpeed.x = rand() % 300 + 150;
		else beetchSpeed.x = (rand() % 300 + 150) * -1;
		beachSpeed.x = (beachSpeed.x * -1);
		beetchSpeed.x = (beetchSpeed.x * -1);
	}
	else if (collided) collided = false;
	if (beachBall.getPosition().x <= 0)
	{
		if (beachSpeed.x > 0) beachSpeed.x = rand() % 300 + 150;
		else beachSpeed.x = (rand() % 300 + 150) * -1;
		beachSpeed.x = (beachSpeed.x * -1);
	}
	if (beetchBoll.getPosition().x >= (window->getSize().x - beetchBoll.getSize().x))
	{
		if (beetchSpeed.x > 0) beetchSpeed.x = rand() % 300 + 150;
		else beetchSpeed.x = (rand() % 300 + 150) * -1;
		beetchSpeed.x = (beetchSpeed.x * -1);
	}

	goomBAH.setPosition(goomBAH.getPosition() + (bahspeed * dt));
	GOOmba.setPosition(GOOmba.getPosition() + (goospeed * dt));
	if ((thisCollision.checkBoundingBox(&goomBAH, &GOOmba)) && (!goomColl))
	{
		goomColl = true;
		bahspeed.y = bahspeed.y * -1;
		goospeed.y = goospeed.y * -1;
	}
	else if (goomColl) goomColl = false;
	if (goomBAH.getPosition().y <= 0) bahspeed.y = bahspeed.y * -1;
	if (GOOmba.getPosition().y >= (window->getSize().y - GOOmba.getSize().y)) goospeed.y = goospeed.y * -1;*/

	pong.update(dt);
	if ((myCollision.checkBoundingBox(&pong, &leftPaddle)) && (!leftcollided))
	{
		leftcollided = true;
		std::cout << "ouch" << std::endl;
		pong.velocityChanger();
	}
	else if (leftcollided) leftcollided = false;

	if ((myCollision.checkBoundingBox(&pong, &rightPaddle)) && (!rightcollided))
	{
		rightcollided = true;
		std::cout << "ouch" << std::endl;
		pong.velocityChanger();
	}
	else if (rightcollided) rightcollided = false;
}

// Render level
void Level::render()
{
	beginDraw();

	/*window->draw(goomBAH);
	window->draw(beachBall);
	window->draw(beetchBoll);
	window->draw(GOOmba);*/

	window->draw(leftPaddle);
	window->draw(rightPaddle);
	window->draw(pong);

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