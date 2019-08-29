#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <map>

class Cube {
private:
	enum Color {
		WHITE,
		RED,
		YELLOW,
		ORANGE,
		BLUE,
		GREEN,
		NUM_COLOURS
	};
	enum Face {
		FRONT_FACE,
		RIGHT_FACE,
		BACK_FACE,
		LEFT_FACE,
		TOP_FACE,
		BOTTOM_FACE,
		NUM_FACES
	};
	enum Position {
		TOP_LEFT,
		TOP,
		TOP_RIGHT,
		RIGHT,
		BOTTOM_RIGHT,
		BOTTOM,
		BOTTOM_LEFT,
		LEFT,
		NUM_POSITIONS
	};
	Color white = WHITE;
	std::map<Color, const sf::Color> colorMapping;

	void rotate4Squares(const Cube::Face& firstFace, const Cube::Position firstPosition, 
		const Cube::Face& secondFace, const Cube::Position secondPosition, 
		const Cube::Face& thirdFace, const Cube::Position thirdPosition, 
		const Cube::Face& fourthFace, const Cube::Position fourthPosition);
	void rotateFace(const Cube::Face& face);
	void drawSquare(const Face& face, const Position& position, const int& size = 50, const int& xOffset = 800, const int& yOffset = 500);

	int xFaceOffset(int face, const int& size);

	int yFaceOffset(int face, const int& size);

	int xPositionOffset(int position, const int& size);

	int yPositionOffset(int position, const int& size);

	void drawSides(sf::RectangleShape visualSquare, sf::RenderWindow& window, const int& size, const int& xOffset, const int& yOffset);

	void colourSquare(sf::RenderWindow& window, sf::RectangleShape visualSquare, const int& xOffset, const int& yOffset, Color colour);

	void drawCentres(sf::RectangleShape visualSquare, sf::RenderWindow& window, const int& size, const int& xOffset, const int& yOffset);

public:
	Color cube[NUM_FACES][NUM_POSITIONS];
	Cube();
	void frontMove();
	void rightMove();
	void backMove();
	void leftMove();
	void topMove();
	void bottomMove();
	void drawFlat(sf::RenderWindow& window, const int& size = 50, const int& xOffset = 800, const int& yOffset = 500);
};
