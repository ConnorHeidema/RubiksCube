#include "../inc/Cube.hpp"

void Cube::rotate4Squares(const Cube::Face& firstFace, const Cube::Position firstPosition,
	const Cube::Face& secondFace, const Cube::Position secondPosition, 
	const Cube::Face& thirdFace, const Cube::Position thirdPosition,
	const Cube::Face& fourthFace, const Cube::Position fourthPosition) {
	Color tempSquare = cube[fourthFace][fourthPosition];
	cube[fourthFace][fourthPosition] = cube[thirdFace][thirdPosition];
	cube[thirdFace][thirdPosition] = cube[secondFace][secondPosition];
	cube[secondFace][secondPosition] = cube[firstFace][firstPosition];
	cube[firstFace][firstPosition] = tempSquare;
}

void Cube::rotateFace(const Cube::Face& face) {
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

Cube::Cube() {
	for (auto face = 0; face < Face::NUM_FACES; face++) {
		for (auto position = 0; position < Position::NUM_POSITIONS; position++) {
			cube[face][position] = static_cast<Color>(face);
		}
	}
}

void Cube::rightMove() {
	rotate4Squares(FRONT_FACE, TOP_RIGHT, BOTTOM_FACE, TOP_RIGHT, BACK_FACE, BOTTOM_LEFT, TOP_FACE, TOP_RIGHT);
	rotate4Squares(FRONT_FACE, RIGHT, BOTTOM_FACE, RIGHT, BACK_FACE, LEFT, TOP_FACE, RIGHT);
	rotate4Squares(FRONT_FACE, BOTTOM_RIGHT, BOTTOM_FACE, BOTTOM_RIGHT, BACK_FACE, TOP_LEFT, TOP_FACE, BOTTOM_RIGHT);
	rotateFace(FRONT_FACE);
}