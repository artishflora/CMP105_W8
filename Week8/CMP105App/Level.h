#pragma once

#include <SFML/Graphics.hpp>
#include "Framework/Input.h"
#include <string>
#include <iostream>
#include "Framework/GameObject.h"
#include "Framework/Collision.h"
#include "Pong.h"
#include "LeftPaddle.h"
#include "RightPaddle.h"

class Level{
public:
	Level(sf::RenderWindow* hwnd, Input* in);
	~Level();

	void handleInput(float dt);
	void update(float dt);
	void render();

private:
	// Default functions for rendering to the screen.
	void beginDraw();
	void endDraw();

	// Default variables for level class.
	sf::RenderWindow* window;
	Input* input;

	/*GameObject beachBall;
	GameObject beetchBoll;
	sf::Texture bowl;
	Collision thisCollision;
	sf::Vector2f beachSpeed;
	sf::Vector2f beetchSpeed;
	bool collided;

	GameObject goomBAH;
	GameObject GOOmba;
	sf::Texture gomba;
	sf::Vector2f bahspeed;
	sf::Vector2f goospeed;
	bool goomColl;*/

	Collision myCollision;
	sf::Texture pongText;

	Pong pong;
	LeftPaddle leftPaddle;
	RightPaddle rightPaddle;
	bool collided;
};