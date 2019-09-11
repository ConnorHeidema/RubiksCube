#pragma once
#include "SFML\Graphics.hpp"

enum Moves {
	FRONT_MOVE,
	RIGHT_MOVE,
	BACK_MOVE,
	LEFT_MOVE,
	TOP_MOVE,
	BOTTOM_MOVE,
	FRONT_INVERSE_MOVE,
	RIGHT_INVERSE_MOVE,
	BACK_INVERSE_MOVE,
	LEFT_INVERSE_MOVE,
	TOP_INVERSE_MOVE,
	BOTTOM_INVERSE_MOVE,
	ROTATE_RIGHT_FRONT,
	ROTATE_TOP_FRONT,
	ROTATE_FRONT_FRONT,
	ROTATE_RIGHT_FRONT_INVERSE,
	ROTATE_TOP_FRONT_INVERSE,
	ROTATE_FRONT_FRONT_INVERSE,
	NUM_MOVES
};

enum Faces {
	FRONT_FACE,
	RIGHT_FACE,
	BACK_FACE,
	LEFT_FACE,
	TOP_FACE,
	BOTTOM_FACE,
	NUM_FACES
};

enum Positions {
	TOP_LEFT,
	TOP,
	TOP_RIGHT,
	RIGHT,
	BOTTOM_RIGHT,
	BOTTOM,
	BOTTOM_LEFT,
	LEFT,
	CENTER,
	NUM_POSITIONS
};

class RubiksCube {
	void rotate4Squares(Faces firstFace, Positions firstPosition,
		Faces secondFace, Positions secondPosition,
		Faces thirdFace, Positions thirdPosition,
		Faces fourthFace, Positions fourthPosition);
	void inverseRotate4Squares(Faces firstFace, Positions firstPosition,
		Faces secondFace, Positions secondPosition,
		Faces thirdFace, Positions thirdPosition,
		Faces fourthFace, Positions fourthPosition);
	void rotateFace(Faces face);
	void inverseRotateFace(Faces face);

public:
	void performFunction(Moves move);
	Moves getMove(std::string moveString);
	std::string getString(Moves move);
	static const sf::Color cubeColors[];
	static const int NUM_COLORS = 6;

	sf::Color thisCube[NUM_FACES][NUM_POSITIONS];

	RubiksCube();

	void frontMove();
	void rightMove();
	void backMove();
	void leftMove();
	void topMove();
	void bottomMove();
	void frontInverseMove();
	void rightInverseMove();
	void backInverseMove();
	void leftInverseMove();
	void topInverseMove();
	void bottomInverseMove();
	void rotateRightFront();
	void rotateTopFront();
	void rotateFrontFront();
	void rotateRightFrontInverse();
	void rotateTopFrontInverse();
	void rotateFrontFrontInverse();
};
