#pragma once

class Cube {
	static enum Color {
		WHITE,
		RED,
		YELLOW,
		ORANGE,
		BLUE,
		GREEN,
		NUM_COLOURS
	};
	static enum Face {
		FRONT_FACE,
		RIGHT_FACE,
		BACK_FACE,
		LEFT_FACE,
		TOP_FACE,
		BOTTOM_FACE,
		NUM_FACES
	};
	static enum Position {
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

	void rotate4Squares(const Cube::Face& firstFace, const Cube::Position firstPosition, 
		const Cube::Face& secondFace, const Cube::Position secondPosition, 
		const Cube::Face& thirdFace, const Cube::Position thirdPosition, 
		const Cube::Face& fourthFace, const Cube::Position fourthPosition);
	
	void rotateFace(const Cube::Face& face);
public:
	Color cube[NUM_FACES][NUM_POSITIONS];
	Cube();
	void rightMove();
};
