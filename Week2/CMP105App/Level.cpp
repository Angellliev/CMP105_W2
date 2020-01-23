#include "Level.h"
#include <cmath>

Level::Level(sf::RenderWindow* hwnd, Input* in)
{
	window = hwnd;
	input = in;

	// initialise game objects

	font.loadFromFile("font/arial.ttf");
	text.setFont(font);
	text.setString("Mouse position: " + std::to_string(input->getMouseX()) + " " + std::to_string(input->getMouseY()));

	text.setCharacterSize(24);
	text.setFillColor(sf::Color::White);
}

Level::~Level()
{
	input = nullptr;
}

// handle user input
void Level::handleInput()
{
	if (input ->isKeyDown(sf::Keyboard::W))
	{
		input->setKeyUp(sf::Keyboard::W);
		std::cout << "'W' was pressed" << std::endl;
	}

	else if (input ->isKeyDown(sf::Keyboard::J) && input ->isKeyDown(sf::Keyboard::K) && input -> isKeyDown(sf::Keyboard::L))
	{
		input->setKeyUp(sf::Keyboard::L);
		input->setKeyUp(sf::Keyboard::K);
		input->setKeyUp(sf::Keyboard::J);
		std::cout << "Buttons 'j' , 'K' and 'L' were pressed" << std::endl;
	}
	else if (input ->isKeyDown(sf::Keyboard::Escape))
	{
		window->close();
	}
	text.setString("Mouse position: " + std::to_string(input->getMouseX()) + " " + std::to_string(input->getMouseY()));
	
	//Reads mouse input
	if (input ->isMouseLDown())
	{
		if (mouseIsPressed == false)
		{
			mousePressedX = input->getMouseX();
			mousePressedY = input->getMouseY();
		}
		mouseIsPressed = true;
		
	}
	if (!input->isMouseLDown() && mouseIsPressed)
	{
		mouseIsPressed = false;
		mousePressedX = input->getMouseX() - mousePressedX;
		mousePressedY = input->getMouseY() - mousePressedY;
		
		std::cout << "Mouse distance traveled in X axis: " << mousePressedX << "  Y axis: " << mousePressedY << std::endl;
	}

	
}

// Update game objects
void Level::update()
{

}

// Render level
void Level::render()
{
	beginDraw();
	window->draw(text);
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