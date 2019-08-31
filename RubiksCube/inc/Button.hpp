#pragma once
#include "Image.hpp"
#include "Util.hpp"
#include "SFML\Graphics.hpp"
#include "SFML\Window.hpp"
#include <functional>
#include <algorithm>
#include <string>
#include <iostream>
class Button {
private:
	Image image;
	bool leftClicked;
	bool rightClicked;
public:
	Button(int xPosition = 0, int yPosition = 0,
		int xSize = 50, int ySize = 50, int thickness = -5,
		sf::Color color = sf::Color::Red, sf::Color outlineColour = sf::Color::Blue,
		sf::Text text = sf::Text(), sf::Font font = sf::Font(), std::string buttonText = "null");
	Image getButtonImage();
	void action(sf::Vector2i mousePosition);
	virtual void leftButtonClicked() = 0;
	virtual void rightButtonClicked() = 0;
};