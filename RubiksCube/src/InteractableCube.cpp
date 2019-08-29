#include "../inc/InteractableCube.hpp"

void InteractableCube::rotate4Squares(const Cube::Face& firstFace, const Cube::Position firstPosition,
	const Cube::Face& secondFace, const Cube::Position secondPosition,
	const Cube::Face& thirdFace, const Cube::Position thirdPosition,
	const Cube::Face& fourthFace, const Cube::Position fourthPosition) {
	Color tempSquare = cube[fourthFace][fourthPosition];
	cube[fourthFace][fourthPosition] = cube[thirdFace][thirdPosition];
	cube[thirdFace][thirdPosition] = cube[secondFace][secondPosition];
	cube[secondFace][secondPosition] = cube[firstFace][firstPosition];
	cube[firstFace][firstPosition] = tempSquare;
}

void InteractableCube::rotateFace(const Cube::Face& face) {
	Color tempSquare = cube[face][NUM_POSITIONS - 1];
	for (auto index = NUM_POSITIONS - 1; index >= 0; index--) {
		if (index == 0) {
			cube[face][index] = cube[face][6];
		} else if (index == 1) {
			cube[face][index] = tempSquare;
		} else {
			cube[face][index] = cube[face][index - 2];
		}
	}
}

InteractableCube::InteractableCube() {};
InteractableCube::~InteractableCube() {};

void InteractableCube::frontMove() {
	rotate4Squares(TOP_FACE, BOTTOM_LEFT, RIGHT_FACE, TOP_LEFT, BOTTOM_FACE, TOP_RIGHT, LEFT_FACE, BOTTOM_RIGHT);
	rotate4Squares(TOP_FACE, BOTTOM, RIGHT_FACE, LEFT, BOTTOM_FACE, TOP, LEFT_FACE, RIGHT);
	rotate4Squares(TOP_FACE, BOTTOM_RIGHT, RIGHT_FACE, BOTTOM_LEFT, BOTTOM_FACE, TOP_LEFT, LEFT_FACE, TOP_RIGHT);
	rotateFace(FRONT_FACE);
}

void InteractableCube::rightMove() {
	rotate4Squares(FRONT_FACE, TOP_RIGHT, TOP_FACE, TOP_RIGHT, BACK_FACE, BOTTOM_LEFT, BOTTOM_FACE, TOP_RIGHT);
	rotate4Squares(FRONT_FACE, RIGHT, TOP_FACE, RIGHT, BACK_FACE, LEFT, BOTTOM_FACE, RIGHT);
	rotate4Squares(FRONT_FACE, BOTTOM_RIGHT, TOP_FACE, BOTTOM_RIGHT, BACK_FACE, TOP_LEFT, BOTTOM_FACE, BOTTOM_RIGHT);
	rotateFace(RIGHT_FACE);
}

void InteractableCube::backMove() {
	rotate4Squares(TOP_FACE, TOP_LEFT, LEFT_FACE, BOTTOM_LEFT, BOTTOM_FACE, BOTTOM_RIGHT, RIGHT_FACE, TOP_RIGHT);
	rotate4Squares(TOP_FACE, TOP, LEFT_FACE, LEFT, BOTTOM_FACE, BOTTOM, RIGHT_FACE, RIGHT);
	rotate4Squares(TOP_FACE, TOP_RIGHT, LEFT_FACE, TOP_LEFT, BOTTOM_FACE, BOTTOM_LEFT, RIGHT_FACE, BOTTOM_RIGHT);
	rotateFace(BACK_FACE);
}

void InteractableCube::leftMove() {
	rotate4Squares(FRONT_FACE, TOP_LEFT, BOTTOM_FACE, TOP_LEFT, BACK_FACE, BOTTOM_RIGHT, TOP_FACE, TOP_LEFT);
	rotate4Squares(FRONT_FACE, LEFT, BOTTOM_FACE, LEFT, BACK_FACE, RIGHT, TOP_FACE, LEFT);
	rotate4Squares(FRONT_FACE, TOP_RIGHT, BOTTOM_FACE, TOP_RIGHT, BACK_FACE, BOTTOM_LEFT, TOP_FACE, TOP_RIGHT);
	rotateFace(LEFT_FACE);
}

void InteractableCube::topMove() {
	rotate4Squares(FRONT_FACE, TOP_LEFT, LEFT_FACE, TOP_LEFT, BACK_FACE, TOP_LEFT, RIGHT_FACE, TOP_LEFT);
	rotate4Squares(FRONT_FACE, TOP, LEFT_FACE, TOP, BACK_FACE, TOP, RIGHT_FACE, TOP);
	rotate4Squares(FRONT_FACE, TOP_RIGHT, LEFT_FACE, TOP_RIGHT, BACK_FACE, TOP_RIGHT, RIGHT_FACE, TOP_RIGHT);
	rotateFace(TOP_FACE);
}

void InteractableCube::bottomMove() {
	rotate4Squares(FRONT_FACE, BOTTOM_LEFT, RIGHT_FACE, BOTTOM_LEFT, BACK_FACE, BOTTOM_LEFT, LEFT_FACE, BOTTOM_LEFT);
	rotate4Squares(FRONT_FACE, BOTTOM, RIGHT_FACE, BOTTOM, BACK_FACE, BOTTOM, LEFT_FACE, BOTTOM);
	rotate4Squares(FRONT_FACE, BOTTOM_RIGHT, RIGHT_FACE, BOTTOM_RIGHT, BACK_FACE, BOTTOM_RIGHT, LEFT_FACE, BOTTOM_RIGHT);
	rotateFace(BOTTOM_FACE);
}