#pragma once
#include "..\Button.hpp"
#include <SFML\Graphics.hpp>
#include <map>
#include <list>

 class Cube {
protected:
	Cube();
 public:
	enum Rotations {
		RIGHT_FRONT,
		TOP_FRONT,
		FRONT_FRONT,
		NUM_ROTATIONS
	};
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
		CENTRE,
		NUM_POSITIONS
	};
 public:
	virtual ~Cube() = 0;
	std::map<Color, const sf::Color> colorMapping;
	Color cube[NUM_FACES][NUM_POSITIONS];
	std::list<Button*> buttons;
};
