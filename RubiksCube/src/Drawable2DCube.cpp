#include "../inc/Drawable2DCube.hpp"

Drawable2DCube::Drawable2DCube() {};

int Drawable2DCube::xFaceOffset(int face, const int& size) {
	if (face == LEFT_FACE) {
		return -3 * size;
	} else if (face == RIGHT_FACE) {
		return 3 * size;
	} else if (face == BACK_FACE) {
		return 6 * size;
	} else {
		return 0;
	}
}

int Drawable2DCube::yFaceOffset(int face, const int& size) {
	if (face == TOP_FACE) {
		return -3 * size;
	} else if (face == BOTTOM_FACE) {
		return 3 * size;
	} else {
		return 0;
	}
}

int Drawable2DCube::xPositionOffset(int position, const int& size) {
	switch (position) {
	case TOP_LEFT:
	case LEFT:
	case BOTTOM_LEFT:
		return -size;
	case TOP_RIGHT:
	case RIGHT:
	case BOTTOM_RIGHT:
		return size;
	}
	return 0;
}

int Drawable2DCube::yPositionOffset(int position, const int& size) {
	switch (position) {
	case TOP_LEFT:
	case TOP:
	case TOP_RIGHT:
		return -size;
	case BOTTOM_LEFT:
	case BOTTOM:
	case BOTTOM_RIGHT:
		return size;
	}
	return 0;
}

void Drawable2DCube::drawSides(sf::RectangleShape visualSquare, sf::RenderWindow& window, const int& size, const int& xOffset, const int& yOffset) {
	int xAdditionalOffset = 0;
	int yAdditionalOffset = 0;
	for (auto face = 0; face < NUM_FACES; face++) {
		for (auto position = 0; position < NUM_POSITIONS; position++) {
			xAdditionalOffset = 0;
			yAdditionalOffset = 0;
			xAdditionalOffset += xFaceOffset(face, size);
			yAdditionalOffset += yFaceOffset(face, size);
			xAdditionalOffset += xPositionOffset(position, size);
			yAdditionalOffset += yPositionOffset(position, size);
			visualSquare.setPosition(sf::Vector2f(xOffset + xAdditionalOffset, yOffset + yAdditionalOffset));
			visualSquare.setFillColor((*colorMapping.find(cube[face][position])).second);
			window.draw(visualSquare);
		}
	}

}

void Drawable2DCube::colourSquare(sf::RenderWindow& window, sf::RectangleShape visualSquare, const int& xOffset, const int& yOffset, Color colour) {
	visualSquare.setPosition(sf::Vector2f(xOffset, yOffset));
	visualSquare.setFillColor((*colorMapping.find(colour)).second);
	window.draw(visualSquare);
}

void Drawable2DCube::drawCentres(sf::RectangleShape visualSquare, sf::RenderWindow& window, const int& size, const int& xOffset, const int& yOffset) {
	int xAdditionalOffset = 3 * size;
	int yAdditionalOffset = 0;
	colourSquare(window, visualSquare, xOffset + xAdditionalOffset, yOffset + yAdditionalOffset, RED);
	xAdditionalOffset += 3 * size;
	colourSquare(window, visualSquare, xOffset + xAdditionalOffset, yOffset + yAdditionalOffset, YELLOW);
	xAdditionalOffset -= 9 * size;
	colourSquare(window, visualSquare, xOffset + xAdditionalOffset, yOffset + yAdditionalOffset, ORANGE);
	xAdditionalOffset += 3 * size;
	colourSquare(window, visualSquare, xOffset + xAdditionalOffset, yOffset + yAdditionalOffset, WHITE);
	yAdditionalOffset -= 3 * size;
	colourSquare(window, visualSquare, xOffset + xAdditionalOffset, yOffset + yAdditionalOffset, BLUE);
	yAdditionalOffset += 6 * size;
	colourSquare(window, visualSquare, xOffset + xAdditionalOffset, yOffset + yAdditionalOffset, GREEN);
}

Drawable2DCube::~Drawable2DCube() {};

void Drawable2DCube::drawFlat(sf::RenderWindow& window, const int& size, const int& xOffset, const int& yOffset) {
	sf::RectangleShape visualSquare(sf::Vector2f(size, size));
	visualSquare.setOutlineThickness(-5);
	visualSquare.setOutlineColor(sf::Color(64, 64, 64, 255));
	drawCentres(visualSquare, window, size, xOffset, yOffset);
	drawSides(visualSquare, window, size, xOffset, yOffset);
}