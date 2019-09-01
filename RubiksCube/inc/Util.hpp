#pragma once
#include "Button.hpp"
#include "SFML\Graphics.hpp"
#include <algorithm>
#include <iostream>

class Util {
public:
	static bool isWithin(const sf::Vector2i& mouse, const sf::RectangleShape& rectangle);
};

class DebugButton : public Button {
	virtual void leftButtonClicked() override;
	virtual void rightButtonClicked() override;
public:
	DebugButton(int xPosition = 0, int yPosition = 0,
		int xSize = 1920, int ySize = 1280, int thickness = -5,
		sf::Color color = sf::Color::Red, sf::Color outlineColour = sf::Color::Blue,
		sf::Text text = sf::Text(), sf::Font font = sf::Font(), std::string buttonText = "null");
};