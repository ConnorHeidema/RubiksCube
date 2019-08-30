#pragma once
#include "Cube.hpp"
#include <SFML\Graphics.hpp>
#include <SFML\Window.hpp>
#include <iostream>

class Drawable2DCube : public virtual Cube {
private:
	const Color white = WHITE;
	sf::RectangleShape squares[NUM_FACES][NUM_POSITIONS];
	const int SIZE = 50;
	const int OUTLINE_THICKNESS = -5;
	const sf::Color OUTLINE_COLOUR = sf::Color(32, 32, 32, 255);
	bool squareClicked = false;
protected:
	Drawable2DCube();
	int xFaceOffset(int face, const int& SIZE);
	int yFaceOffset(int face, const int& SIZE);
	int xPositionOffset(int position, const int& SIZE);
	int yPositionOffset(int position, const int& SIZE);

public:
	virtual ~Drawable2DCube() = 0;
	void drawFlat(sf::RenderWindow& window, const int& SIZE = 50, const int& xOffset = 800, const int& yOffset = 500);
	void squareClick(const sf::Vector2i&);
};
