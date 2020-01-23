#pragma once

#include <SFML/Graphics.hpp>
#include "Framework/Input.h"
#include <string.h>
#include <iostream>


class Level{
public:
	Level(sf::RenderWindow* hwnd, Input* in);
	~Level();

	void handleInput();
	void update();
	void render();

private:
	// Default functions for rendering to the screen.
	void beginDraw();
	void endDraw();

	// Default variables for level class.
	sf::RenderWindow* window;
	sf::Font font;
	sf::Text text;
	Input* input;

	//Mouse controlls
	bool mouseIsPressed = false;
	int mousePressedX;
	int mousePressedY;
	int mouseDistanceDragged;

	// Add your object here
	sf::CircleShape circle;
	bool circleDrawn = false;
};