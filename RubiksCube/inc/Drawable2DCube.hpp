#pragma once
#include "Cube.hpp"
#include <SFML\Graphics.hpp>
#include <SFML\Window.hpp>

class Drawable2DCube : public virtual Cube {
private:
	const Color white = WHITE;
protected:
	Drawable2DCube();
	int xFaceOffset(int face, const int& size);
	int yFaceOffset(int face, const int& size);
	int xPositionOffset(int position, const int& size);
	int yPositionOffset(int position, const int& size);

	void drawSquares(sf::RectangleShape visualSquare, sf::RenderWindow& window, const int& size, const int& xOffset, const int& yOffset);
public:
	virtual ~Drawable2DCube() = 0;
	void drawFlat(sf::RenderWindow& window, const int& size = 50, const int& xOffset = 800, const int& yOffset = 500);
};
