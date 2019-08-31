#pragma once
#include "SFML\Graphics.hpp"
#include "SFML\Window.hpp"
#include <functional>
#include <algorithm>
class Button {
private:
	void (*leftClickAction)();
	void (*rightClickAction)();
public:
	Button(int xPosition = 0, int yPosition = 0,
		int xSize = 50, int ySize = 50, int thickness = -5,
		sf::Color color = sf::Color::Red, sf::Color outlineColour = sf::Color::Blue,
		void(*onLeftClick)() = []() {}, void(*onRightClick)() = []() {});
	void drawButton(sf::RenderWindow);
	void action();
};
